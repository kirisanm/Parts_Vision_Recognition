# recevingPartB.py

import numpy as np
import cv2
import glob

"""
Parts Vision Recognition
------------------------
This part of the program analyzing the single image with other images.
"""


class receiving:

    def __init__(self, original):
        self.original = original
        """
        :param name: self
                         Using this to access the attributes
        :param name: original
                             image
        """

    def Original(self):
        """
        Param name: self
                        Using this to access the attributes
        """

        sift = cv2.xfeatures2d.SURF_create(2000)
        """
        Finding key points on the image and comparing that with other images in database
        """
        kp_1, desc_1 = sift.detectAndCompute(self.original, None)
        """
        Flann parameters
        """
        FLANN_INDEX_KDTREE = 0
        index_params = dict(algorithm=FLANN_INDEX_KDTREE, trees=5)
        search_params = dict()
        flann = cv2.FlannBasedMatcher(index_params, search_params)

        """
        Creating two empty array and adding images and names
        """
        all_images_to_compare = []
        titles = []
        for f in glob.iglob("../images/*"):

            image = cv2.imread(f)
            titles.append(f)
            all_images_to_compare.append(image)
        percentiage = 0
        """
        Reading images and their names in a for loop.
        Finding the key points and describing those key points on the image
        """

        for image_to_compare, title in zip(all_images_to_compare, titles):

            kp_2, desc_2 = sift.detectAndCompute(image_to_compare, None)
            #print("Kp1: " + str(len(kp_1)))
            # print("Kp2: " + str(len(kp_2)))  # 1 med 30

            matches = flann.knnMatch(desc_1, desc_2, k=2)
            """
            Ratio testing and saving temporary those good points
            """
            good_points = []
            for m, n in matches:
                if m.distance < 0.4 * n.distance:
                    good_points.append(m)
            number_keypoints = 0
            """
            Condition checking of the key points

            """
            if len(kp_1) > len(kp_2):
                number_keypoints = len(kp_1)
            else:
                number_keypoints = len(kp_2)
            """
            Writing some data on files.
            :match percentage
            :image name
            Computes the match percentage
            """
            percentiage = len(good_points) * 100 / number_keypoints
            f = open("../percent/percent.txt", "a")
            f.write("{:.0f}\n".format(percentiage))
            n = open("../imageName/name.txt", "a")
            print >> n, title
            n.close()
            # leser fra filen
            print("Filnavn:" + title)
            f = open("../percent/percent.txt", "r+")
            nums = f.readlines()
            nums = [int(i) for i in nums]
            w = (max(nums))
            """
            Checking condition and drawing match points if the there is a match
            Shows the image with the highest match percentage.
            Saving the result and shows on the screen
            """

            if percentiage == w:
                print("Match percent: {0:.1f}%".format(percentiage))
                result = cv2.drawMatches(self.original, kp_1, image_to_compare, kp_2,
                                         good_points, None)
                img = cv2.resize(result, None, fx=0.3, fy=0.3)

                cv2.imshow("The result image", img)
                cv2.imwrite("../result/result.jpg", result)
            else:
                print("Match percent: {0:.1f}%".format(percentiage))


if __name__ == '__main__':
    cleanPercentFile = open("../percent/percent.txt", "r+")
    cleanPercentFile.seek(0)
    cleanPercentFile.truncate()
    cleanNameFile = open("../imageName/name.txt", "r+")
    cleanNameFile.seek(0)
    cleanNameFile.truncate()
    """Removing the content of these two files before the program will run."""
    original = cv2.imread("../image/A4 C-0000 A.jpg")
    """Reading image."""

    receiving(original).Original()
