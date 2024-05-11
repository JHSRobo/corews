#! /usr/bin/env python3

import rclpy
from rclpy.node import Node
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

class ImageCaptureNode(Node):
    def __init__(self):
        super().__init__("img_capture")
        self.log = self.get_logger()
        self.log.info("Image Capture Node Online")

        # Global Variables
        self.path =  "C:\jhsrobo\img_capture\img"
        self.count = 1
        self.coral_count = 1
        self.bridge = CvBridge()
        self.coral_mode = False

        # Coral Mode Parameter
        self.declare_parameter("coral_mode", self.coral_mode)
        self.create_timer(0.1, self.coral_mode_update)

        # Subscribers
        self.camera_subscriber = self.create_subscription(Image, "camera_feed", self.img_callback, 10)

    def coral_mode_update(self):
        coral_mode_parameter = self.get_parameter("coral_mode").value
        if self.coral_mode != coral_mode_parameter:
            self.log.info(f"New Coral Mode Value: {coral_mode_parameter}")
        self.coral_mode = coral_mode_parameter
        

    def img_callback(self, screenshot):
        img = self.bridge.imgmsg_to_cv2(screenshot, desired_encoding="passthrough")
        if self.coral_mode:
            cropped_img = img[0:505, 0:1215]
            if self.coral_count % 5 == 0:
                cv2.imwrite("{}\coral\{}.png".format(self.path, self.coral_count), cropped_img)
            self.coral_count += 1
        else:
            cv2.imwrite("{}\other\{}.png".format(self.path, self.count), img)
            self.count +=  1
