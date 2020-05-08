# sende.py
import cv2 as cv
import barcode
import pyzbar.pyzbar as pyzbar

'''
Parts Vision Recognition
---------------------------
This document is solely for the sending part.

Summary.
This part of the code basically reads the barcodes and takes picture and saving it in the different file directory.
'''


class sende:

    def __init__(self, EAN, capture):
        """
        This function takes three paramters

        :param name: self 
                         Using this to access the attributes
        :param name: EAN 
                        Is European Article Number (code39) in this case
        :param name: Capture 
                            Capturing video from the webcam

        """
        self.EAN = EAN
        self.capture = capture

    def getFrame(self):
        """
        This function takes one paramter.

        :param name: self - accessing attributes

        Count: int 
                  increasing each time when the program takes new picture
        Barcode: str
                    defined as an empty variable and gets the barcode value when the program read it
        """
        count = 0
        barcode = ''
        """
        While loop
        -----------
        Checking if the webcam is open.
        Reading frame and barcode.
        Bluring the image.
        The  program avoiding to save illegal image format like if image has no barcode name.
        

        """
        while (True):
            if self.capture.isOpened():
                ret, frame = self.capture.read()
                blurImage = cv.GaussianBlur(frame, (5, 5), 0)
                cv.imshow("Frame", blurImage)
                decodeBarcode = pyzbar.decode(frame)
                if decodeBarcode == []:
                    print("Fant ingen barcode")
                else:
                    for i in decodeBarcode:
                        barcode = i.data
                Key = cv.waitKey(1)
                if (Key == ord("q")):
                    print("Programmet avsluttet")
                    break
                if (Key == ord("c")):
                    # -------------------------------------------------------------
                    ean = self.EAN(barcode)
                    barcodePath = '../barcodes/' + barcode
                    """This if condition is not working. We have to check if the barcode Path includes barcode and not only .svg file extention"""
                    if (ean.save(barcodePath) == '.svg'):

                        pass
                    else:
                        ean.save(barcodePath)
                    # ----------------------------------------------------------

                    imageFullPath = "../images/{}.jpg".format(barcode)
                    if (imageFullPath == '../images/.jpg'):
                        pass
                    else:
                        cv.imwrite(imageFullPath, blurImage)
                        print("{} Lagret".format(imageFullPath))
                        count += 1
            else:

                Ret = False
                break


if __name__ == '__main__':
    """
    This function sets some  special variables name and executing all codes that was found in the file.
    Calling the class and executing the code.
    1 is defined for capturing video from webcam.
    0 is for inbuild webcam on pc.
    """
    EAN = barcode.get_barcode_class('code39')
    capture = cv.VideoCapture(1)
    sende(EAN, capture).getFrame()
