import argparse
import cv2
from PIL import Image

ap = argparse.ArgumentParser()
ap.add_argument('-i','--image',required=True,help="path")
args = vars(ap.parse_args())

image = cv2.imread(args['image'])
cv2.imshow("Original",image)

flip_image = cv2.flip(image,1)
cv2.imshow("Flipped",flip_image)

flip_image = cv2.flip(image,0)
cv2.imshow("F_verticallY",flip_image)

flip_image = cv2.flip(image,-1)
cv2.imshow("Both" ,flip_image)

cv2.waitKey(0)