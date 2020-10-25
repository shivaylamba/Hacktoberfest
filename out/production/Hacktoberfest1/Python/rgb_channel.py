import matplotlib.pyplot as plt
import matplotlib.image as mpimg

image = mpimg.imread('wa_state_highway.jpg')
plt.imshow(image)
plt.show()

# RGB Channel
r = image[:,:,0]
g = image[:,:,1]
b = image[:,:,2]

f, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(20,10))
ax1.set_title('R Channel')
ax1.imshow(r, cmap='gray')


ax2.set_title('G Channel')
ax2.imshow(g, cmap='gray')


ax3.set_title('B Channel')
ax3.imshow(b, cmap='gray')

plt.show()




