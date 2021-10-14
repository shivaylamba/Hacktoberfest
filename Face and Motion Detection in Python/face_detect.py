import cv2

#create cascadeClassifier object
face_cascade=cv2.CascadeClassifier("C:\\Users\\gagro\\Python 3.9.2\\Lib\\site-packages\\cv2\data\\haarcascade_frontalface_default.xml")

#reading the image
img=cv2.imread("sample.jpg")
#reading image in grayscale
gray_img=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

#now searching the coordinates of the image
faces=face_cascade.detectMultiScale(gray_img, scaleFactor=1.05,minNeighbors=5)
for x,y,w,h in faces:
    img=cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),3)
cv2.imshow("sample",img)
cv2.waitKey(0)
cv2.destroyAllWindows()
