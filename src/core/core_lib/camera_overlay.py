import cv2
import numpy as np

class Overlay():
    def __init__(self):
        self.lower_red_first = np.array([0,70,10])
        self.upper_red_first = np.array([10,255,255])
        self.lower_red_second = np.array([170,70,10])
        self.upper_red_second = np.array([180,255,255])
        self.lower_white = np.array([0,3,240])
        self.upper_white = np.array([255,5,255])

    def depth_bar(self, frame, depthLevel):
        # Preparing the bar
        cv2.line(frame, (1240, 128), (1240, 640), (48, 18, 196), 5)
        cv2.line(frame, (1240, 128), (1190, 128), (48, 18, 196), 5)
        cv2.line(frame, (1240, 640), (1190, 640), (48, 18, 196), 5)

        # Intervals (32 pixels)
        for i in range(16):
            if i % 2 == 0:
                cv2.line(frame, (1240, 608 - (i * 32)), (1215, 608 - (i * 32)), (48, 18, 196), 5)
            else:
                cv2.line(frame, (1240, 608 - (i * 32)), (1190, 608 - (i * 32)), (48, 18, 196), 5)

        # Draw target depth
        if self.dh_enable:
            cv2.line(frame, (1190, int(self.target_depth * 32) + 128), (1240, int(self.target_depth * 32) + 128), (255,0,0), 5)
            cv2.putText(frame, "Target", (1085, int(self.target_depth * 32) + 135), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)


        # Draw pointer
        pt1 = (1240, (depthLevel * 32) + 128)
        pt2 = (1190, (depthLevel * 32) + 153)
        pt3 = (1190, (depthLevel * 32) + 103)

        pointer = np.array([pt1, pt2, pt3])
        cv2.drawContours(frame, [pointer.astype(int)], 0, (19,185,253), -1)

        return frame
    

    def throttle_bar(self, frame):
      tempThrottle = abs(self.rov_throttle + 1000)
      
      cv2.line(frame, (40,128), (40, 640), (48, 18, 196), 5)
      cv2.line(frame, (40,128), (90, 128), (48, 18, 196), 5)
      cv2.line(frame, (40,640), (90, 640), (48, 18, 196), 5)
      cv2.line(frame, (40,384), (90, 384), (48, 18, 196), 5)
      
      pt1 = (40, int(tempThrottle * 0.256) + 128)
      pt2 = (90, int(tempThrottle * 0.256) + 153)
      pt3 = (90, int(tempThrottle * 0.256) + 103)
      pointer = np.array([pt1, pt2, pt3])
      
      if not self.dh_enable:
        cv2.drawContours(frame, [pointer.astype(int)], 0, (19,185,253), -1)
      else:
        cv2.drawContours(frame, [pointer.astype(int)], 0, (255,0,0), -1)
      return frame