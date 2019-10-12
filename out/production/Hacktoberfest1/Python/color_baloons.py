import numpy as np
import matplotlib.pyplot as plt
import cv2

image = cv2.imread('water_balloons.jpg')
image_copy = np.copy(image)

image = cv2.cvtColor(image_copy, cv2.COLOR_BGR2RGB)

plt.imshow(image)
plt.show()

r = image[:,:,0]
g = image[:,:,1]
b = image[:,:,2]

f, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(20,10))

ax1.set_title('Red')
ax1.imshow(r, cmap='gray')

ax2.set_title('Green')
ax2.imshow(g, cmap='gray')

ax3.set_title('Blue')
ax3.imshow(b, cmap='gray')

plt.show()

# Convert RGB to HSV
hsv = cv2.cvtColor(image, cv2.COLOR_RGB2HSV)

h = hsv[:,:,0]
s = hsv[:,:,1]
v = hsv[:,:,2]

f, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(20,10))

ax1.set_title('Hue')
ax1.imshow(h, cmap='gray')

ax2.set_title('Saturation')
ax2.imshow(s, cmap='gray')

ax3.set_title('Value')
ax3.imshow(v, cmap='gray')

plt.show()

# define pink and hue threshold
lower_hue = np.array([160,0,0])
upper_hue = np.array([180,255,255])

lower_pink = np.array([180,0,100])
upper_pink = np.array([255,255,230])

#mask image

mask_rgb = cv2.inRange(image, lower_pink, upper_pink)

masked_image = np.copy(image)
masked_image[mask_rgb==0] = [0,0,0]

plt.imshow(masked_image)
plt.show()


# using HSV

mask_hsv = cv2.inRange(image, lower_hue, upper_hue)

masked_image = np.copy(image)
masked_image[mask_hsv==0] = [0,0,0]

plt.imshow(masked_image)
plt.show()




