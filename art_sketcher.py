import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load the image
image = cv2.imread('image.jpg')

# Convert the image to grayscale
grey_img = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Invert the grayscale image
invert = cv2.bitwise_not(grey_img)

# Apply a Gaussian blur to the inverted image
blur = cv2.GaussianBlur(invert, (21, 21), 0)

# Invert the blurred image again
invertedblur = cv2.bitwise_not(blur)

# Divide the grayscale image by the inverted blurred image to get the sketch
sketch = cv2.divide(grey_img, invertedblur, scale=256.0)

# Display and save the final sketch image
cv2.imshow('Sketch image', sketch)
cv2.imwrite("sketch.jpeg", sketch)
cv2.waitKey(0)
