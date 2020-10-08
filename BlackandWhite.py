import cv2

originalImage = cv2.imread('single.jpeg')
grayImage = cv2.cvtColor(originalImage, cv2.COLOR_BGR2GRAY)

cv2.imshow('Gray image', grayImage)

cv2.waitKey(0)
cv2.destroyAllWindows()