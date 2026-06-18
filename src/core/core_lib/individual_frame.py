

import cv2
import argparse
import torch
from ultralytics import YOLO


class Why_make_class:

    def __init__(self):

        resolution = (1280, 720)

        self.font = cv2.FONT_HERSHEY_DUPLEX
        self.model = YOLO("/home/jhsrobo/corews/src/core/core_lib/best.pt")
        #self.model = YOLO("/Users/iankim/Documents/Programming/CRAB/Crab_model/runs/detect/train12/weights/best.pt")

        if torch.cuda.is_available():
            self.gpu = True
        else:
            self.gpu = False

        self.font = cv2.FONT_HERSHEY_DUPLEX
        self.color = (255, 255, 255) # White
        self.background_color = (32, 32, 32) # Gray
        self.thickness = 1
        self.display_width = resolution[0]
        self.display_height = resolution[1]
        self.line_type = cv2.LINE_AA
        self.left_align = int(self.display_width / 40)
        self.vertical_increment = int(self.display_height / 20)



    def add_text(self, frame, text, position, font_size = 0.6):
        frame = cv2.putText(frame, text, (position[0] + 1, position[1] + 1), self.font, font_size, self.background_color, self.thickness, self.line_type)
        frame = cv2.putText(frame, text, position, self.font, font_size, self.color, self.thickness, self.line_type)
        return frame

    def run_frame(self, filepath = "a.png", confidence=0.7):

        frame = cv2.imread(filepath)

        roi_x = 0
        roi_y = 0
        cv2.rectangle(frame, (roi_x, roi_y), (frame.shape[1], frame.shape[0]), (255, 255, 0), 3)
        if self.gpu:
            results = self.model.track(
                    frame[roi_y:, roi_x:, :],
                    device=0,
                    conf=0.25,
            )
        else:
            results = self.model.track(
                    frame[roi_y:, roi_x:, :],
                    device="cpu",
                    conf=0.25,
            )

        result = results[0]
        num_filtered_detections = 0
        
        if result.boxes is not None and len(result.boxes) > 0:
            boxes = result.boxes

            class_ids = boxes.cls
            confs = boxes.conf
            target_class_id = 0
            min_confidence = confidence

            mask = (
                    (class_ids == target_class_id) &
                    (confs >= min_confidence)
                    )

            filtered_boxes = boxes[mask]

            track_ids = None
            if filtered_boxes.id is not None:
                active_ids = set(filtered_boxes.id.int().cpu().tolist())
                num_filtered_detections = len(active_ids)
                track_ids = filtered_boxes.id.int().cpu().tolist()
            else:
                num_filtered_detections = 0
                
            for box in filtered_boxes.xyxy:
                x1, y1, x2, y2 = box.tolist()

                x = int(x1)
                y = int(y1)
                w = int(x2 - x1)
                h = int(y2 - y1)

                cv2.rectangle(
                    frame,
                    (roi_x+x, roi_y+y),
                    (roi_x+x + w, roi_y+y + h),
                    (0, 0, 255),
                    2
                )

        font_size = 0.6
        position = (100, 600)
        text = "Number of European Green Crabs: " + str(num_filtered_detections)
        
        frame = self.add_text(frame, text, position, font_size)
        
        cv2.imwrite("yolo_screenshot.png", frame)


if __name__ == "__main__": # w vibecode
    parser = argparse.ArgumentParser(
        description="Run YOLO crab detection on an image."
    )

    parser.add_argument(
        "--path",
        type=str,
        default="a.png",
        help="Path to input image"
    )

    parser.add_argument(
        "--conf",
        type=float,
        default=0.7,
        help="Minimum confidence threshold"
    )

    args = parser.parse_args()

    detector = Why_make_class()
    detector.run_frame(
        filepath=args.path,
        confidence=args.conf,
    )
