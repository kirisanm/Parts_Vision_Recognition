# recevingPartA.py

import cv2 as cv

"""
Parts Vision Recognition
------------------------

Part A for receiving

This is part of the program will take a single picture for recognition.
The "image" file is overwriting every time the uuser take new picture to recognize.

"""


class takePicture:

    def __init__(self, capture):
        self.capture = capture

    def captureFrame(self):

        while True:
            if self.Capture.isOpened():
                ret, frame = self.capture.read()
                blur = cv.GaussianBlur(frame, (5, 5), 0)
                cv.imshow("Frame", blur)
                key = cv.waitKey(1)
                if key == ord("q"):
                    break

                if key == ord("c"):

                    img_name = "../image/A4 C-0000 A.jpg"
                    cv.imwrite(img_name, blur)
                    print("{} Lagret".format(img_name))

            else:
                ret = False
                break


if __name__ == '__main__':

    capture = cv.VideoCapture(1)
    takePicture(capture).captureFrame()
