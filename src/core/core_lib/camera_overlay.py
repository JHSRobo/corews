import cv2
import numpy as np
from ultralytics import YOLO
import torch

class HUD():
    def __init__(self, resolution = (1280, 720)):
        
        # Appearance Settings
        self.font = cv2.FONT_HERSHEY_DUPLEX
        self.color = (255, 255, 255) # White
        self.background_color = (32, 32, 32) # Gray
        self.thickness = 1
        self.display_width = resolution[0]
        self.display_height = resolution[1]
        self.line_type = cv2.LINE_AA
        self.left_align = int(self.display_width / 40)
        self.vertical_increment = int(self.display_height / 20)
        self.model = YOLO("/home/jhsrobo/corews/src/core/core_lib/best.pt")

        if torch.cuda.is_available():
            self.gpu = True
        else:
            self.gpu = False

        self.f = 800
        self.base_cube = np.float32([
            [-1,-1,-1],
            [ 1,-1,-1],
            [ 1, 1,-1],
            [-1, 1,-1],
            [-1,-1, 1],
            [ 1,-1, 1],
            [ 1, 1, 1],
            [-1, 1, 1]
        ]) * 100

        self.cube = self.base_cube * 0.3

        self.edges = [
            (0,1),(1,2),(2,3),(3,0),
            (4,5),(5,6),(6,7),(7,4),
            (0,4),(1,5),(2,6),(3,7)
        ]

        self.front_face = [4,5,6,7]

        self.pos_x = resolution[0]//2
        self.pos_y = resolution[1]//2


    # Overlays the current camera's index and nickname
    def add_camera_details(self, frame, index, nickname):
        text = "{}: {}".format(index, nickname)
        font_size = 0.8
        position = (self.left_align, self.vertical_increment)

        frame = self.add_text(frame, text, position, font_size)
        return frame


    # Overlays the current thruster status onto the frame
    def add_thruster_status(self, frame, status_bool):
        if status_bool: status_text = "Enabled"
        else: status_text = "Disabled" 
        text = "Thrusters: {}".format(status_text)

        font_size = 0.6
        position = (self.left_align, 2 * self.vertical_increment)

        frame = self.add_text(frame, text, position, font_size)
        return frame


    # Accepts a dictionary of sensitivity values and overlays them onto the frame
    def add_gripper(self, frame, gripper):
        
        # Add the header
        font_size = 0.6
        position = (self.left_align, 3 * self.vertical_increment)
        text = "Gripper: {}".format(gripper)
        frame = self.add_text(frame, text, position, font_size)
        
        return frame


    # Accepts a dictionary of sensitivity values and overlays them onto the frame
    def add_sensitivity(self, frame, sensitivities):
        
        # Add the header
        font_size = 0.6
        position = (self.left_align, 5 * self.vertical_increment)
        frame = self.add_text(frame, "Sensitivity:", position, font_size)

        # Add the individual sensitivies:
        font_size = 0.5
        counter = 5.66
        for key in sensitivities:
            position = (self.left_align + 20, int(counter * self.vertical_increment))
            text = "{}: {}".format(key, sensitivities[key])
            frame = self.add_text(frame, text, position, font_size)
            counter += 0.66
        
        return frame
    

    # Accepts a dictionary of sensitivity values and overlays them onto the frame
    def add_publish_status(self, frame, publish_status):
        
        # Add the header
        font_size = 0.6
        position = (self.left_align, 4 * self.vertical_increment)
        text = "Recording Feed: {}".format(publish_status)
        frame = self.add_text(frame, text, position, font_size)
        
        return frame
        
    def add_orientation_info(self, frame, yaw, pitch, roll):

        # Endpoints for the roll/pitch line
        startX = int(self.display_width / 2 - 100 + abs(roll / 90 * 100))
        startY = int(self.display_height / 2 + roll + pitch)
        endX = int(self.display_width / 2 + 100 - abs(roll / 90 * 100))
        endY = int(self.display_height / 2 - roll + pitch)

        # Draw roll/pitch line
        frame = cv2.line(frame, (startX, startY), (endX, endY), (0, 255, 0), 5)

        return frame


    def add_photogrammetry_box(self, frame):
        y1, y2, x1, x2 = 48, 810, 0, 1380
        sub_img = frame[y1:y2, x1:x2]
        darkened_rect = np.ones(frame.shape, dtype=np.uint8) * 40

        frame = cv2.addWeighted(frame, 0.5, darkened_rect, 0.5, 1.0)
        frame[y1:y2, x1:x2] = sub_img

        return frame


    def leak_notification(self, frame):
        text = "LEAK DETECTED"
        font_size = 1
        
        # Find how large the text will be so we know how to center it
        textSize = cv2.getTextSize(text, self.font, font_size, self.thickness)[0]
        position = (int(self.display_width / 2 - textSize[0] / 2), int(self.display_height / 2))

        frame = self.add_text(frame, text, position, font_size)
        return frame
    

    def add_text(self, frame, text, position, font_size = 0.6):
        frame = cv2.putText(frame, text, (position[0] + 1, position[1] + 1), self.font, font_size, self.background_color, self.thickness, self.line_type)
        frame = cv2.putText(frame, text, position, self.font, font_size, self.color, self.thickness, self.line_type)
        return frame

    
    def crab_model(self, frame): 
        if self.gpu:
            results = self.model(frame, device=0, conf=0.5)
        else:
            results = self.model(frame, device="cpu", conf=0.5)

        result = results[0]

        if result.boxes is None or len(result.boxes) == 0:
            num_filtered_detections = 0
            annotated_frame = frame.copy()
        else:
            boxes = result.boxes
            class_ids = boxes.cls
            confs = boxes.conf

            target_class_id = 0
            min_confidence = 0.5

            mask = (class_ids == target_class_id) & (confs >= min_confidence)

            filtered_boxes = boxes[mask]

            num_filtered_detections = mask.sum().item()

            result.boxes = filtered_boxes
            annotated_frame = result.plot()


        font_size = 0.6
        position = (self.left_align, 9 * self.vertical_increment)
        text = "Number of European Green Crabs: " + str(num_filtered_detections)

        annotated_frame = self.add_text(annotated_frame, text, position, font_size)

        return annotated_frame
         
       

    def overlay_3d(self, frame, roll, pitch):

        R = self.rotation_matrix(roll, pitch)
        rotated = (R @ self.cube.T).T

        rotated += np.array([0, 0, 600])

        projected = []
        for point in rotated:
            x = int((self.f * point[0] / point[2]) + self.pos_x)
            y = int((self.f * point[1] / point[2]) + self.pos_y)
            projected.append((x,y))

        for edge in self.edges:
            cv2.line(frame,
                     projected[edge[0]],
                     projected[edge[1]],
                     (0,255,0), 2)

        for i in range(4):
            pt1 = projected[self.front_face[i]]
            pt2 = projected[self.front_face[(i+1)%4]]
            cv2.line(frame, pt1, pt2, (0,0,255), 3)

        return frame


    def rotation_matrix(self, roll, pitch):
        r = np.deg2rad(roll)
        p = np.deg2rad(pitch)

        Rx = np.array([
            [1,0,0],
            [0,np.cos(r),-np.sin(r)],
            [0,np.sin(r), np.cos(r)]
        ])

        Ry = np.array([
            [ np.cos(p),0,np.sin(p)],
            [0,1,0],
            [-np.sin(p),0,np.cos(p)]
        ])

        return Ry @ Rx
