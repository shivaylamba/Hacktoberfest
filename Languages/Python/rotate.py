import cv2
import numpy as np 
import argparse 
import imutils

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required=True,help="path to image ")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
cv2.imshow("Original",image)

(h,w) = image.shape[:2]

center = (w // 2 , h // 2)

M = cv2.getRotationMatrix2D(center,45,1.3)
rotated = cv2.warpAffine(image,M,(w,h))
cv2.imshow("rotated 45",rotated)

M = cv2.getRotationMatrix2D(center,-90,1.0)
rotated = cv2.warpAffine(image,M,(w,h))
cv2.imshow("Rotated -90 Degrees",rotated)

rotated = imutils.rotate(image,180)
cv2.imshow("Rotated 180 Degrees",rotated)

cv2.waitKey(0)
