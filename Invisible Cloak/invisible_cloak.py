import cv2
import numpy as np
import time
def hsv(x):
   pass
cap=cv2.VideoCapture(0)
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))
time.sleep(3)
background=0
for i in range(60):
    ret,background=cap.read()
#background=np.flip(background,axis=1)
cv2.namedWindow("Orginal")
cv2.namedWindow("Detection")
cv2.createTrackbar("LH","Detection",0,255,hsv)
cv2.createTrackbar("LS","Detection",0,255,hsv)
cv2.createTrackbar("LV","Detection",0,255,hsv)
cv2.createTrackbar("HH","Detection",255,255,hsv)
cv2.createTrackbar("HS","Detection",255,255,hsv)
cv2.createTrackbar("HV","Detection",255,255,hsv)
while(1):
    ret,img=cap.read()
    lh=cv2.getTrackbarPos("LH","Detection")
    ls=cv2.getTrackbarPos("LS","Detection")
    lv=cv2.getTrackbarPos("LV","Detection")
    hh=cv2.getTrackbarPos("HH","Detection")
    hs=cv2.getTrackbarPos("HS","Detection")
    hv=cv2.getTrackbarPos("HV","Detection")
    HSV=cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

    
    lower_red = np.array([0, 120,70]) 
    upper_red = np.array([10,255,255]) 


    mask1= cv2.inRange(HSV,lower_red, upper_red) 

    lower_red = np.array([175,120,70]) 
    upper_red = np.array([180,255,255]) 

    
    mask2= cv2.inRange(HSV,lower_red, upper_red) 
  
    mask1=mask1+mask2 
    kernel = np.ones((5,5),np.uint8)
   
    mask1=cv2.morphologyEx(mask1,cv2.MORPH_OPEN, kernel,iterations=2)
    mask2= cv2.morphologyEx(mask1,cv2.MORPH_DILATE,kernel,iterations = 1)
    mask2=cv2.bitwise_not(mask1)
    Output1=cv2.bitwise_and(background,background,mask=mask1)
    print(background.shape)
    print(mask1.shape)
    Output2=cv2.bitwise_and(img,img,mask=mask2)
    final=cv2.addWeighted(Output1,1,Output2,1,0)
    cv2.imshow("magic",final)
    cv2.imshow("Orginal",img)
    out.write(final)
    k=cv2.waitKey(20)
    if k==27:
        break
    
cap.release()
  