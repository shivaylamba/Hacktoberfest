import matplotlib.pyplot as plt
import numpy as np
import cv2

image = cv2.imread('pizza_bluescreen.jpg')

print('This image is:', type(image),
	  ' with dimensions:', image.shape)

image_copy = np.copy(image)

image_copy = cv2.cvtColor(image_copy, cv2.COLOR_BGR2RGB)

plt.imshow(image_copy)
plt.show()

# define the color threshold
lower_blue = np.array([0,0,200])
upper_blue = np.array([250,250,255])

# create a mask
# define the masked area
mask = cv2.inRange(image_copy, lower_blue, upper_blue)

# visualize mask
plt.imshow(mask, cmap='gray')
plt.show()

# mask the image to let pizza show through
masked_image = np.copy(image_copy)

masked_image[mask != 0] = [0, 0, 0]

# display it
plt.imshow(masked_image)
plt.show()

# mask and add background image 

# load in background image and convert it to rgb
background_image = cv2.imread('space_background.jpg')
background_image = cv2.cvtColor(background_image, cv2.COLOR_BGR2RGB)

# crop it to right size
crop_background = background_image[0:514, 0:816]

crop_background[mask == 0] = [0, 0, 0]
plt.imshow(crop_background)
plt.show()

# complete image
complete_image = masked_image + crop_background

plt.imshow(complete_image)
plt.show()