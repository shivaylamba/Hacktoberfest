import matplotlib.pyplot as plt
import matplotlib.image as mpimg

import numpy as np
import cv2

image = mpimg.imread('car_green_screen2.jpg')

print('Image Dimensions:', image.shape)
plt.imshow(image)
plt.show()

lower_green = np.array([0,250,0]) 
upper_green = np.array([250,255,250])

mask = cv2.inRange(image, lower_green, upper_green)

# Vizualize the mask
plt.imshow(mask, cmap='gray')
plt.show()

masked_image = np.copy(image)

masked_image[mask != 0] = [0, 0, 0]

# Display it!
plt.imshow(masked_image)
plt.show()

# Load in a background image, and convert it to RGB 
background_image = mpimg.imread('sky.jpg')

## TODO: Crop it or resize the background to be the right size (450x660)
crop_background_image = background_image[0:masked_image.shape[0], 0:masked_image.shape[1]]

## TODO: Mask the cropped background so that the car area is blocked
crop_background_image.setflags(write=1)
crop_background_image[mask == 0] = [0, 0, 0]

## TODO: Display the background and make sure 
plt.imshow(crop_background_image)
plt.show()