import cv2 as cv
import numpy as np
cam=cv.VideoCapture(0)
face=cv.CascadeClassifier("haarcascade_frontalface_default.xml")
while True:
    _,frame=cam.read()
    frame=cv.flip(frame,1)
    try:
        new=face.detectMultiScale(frame)
        for i in range(len(new)):
            new1=new[i]
            new1[0]-=(new1[2])*0.10
            new1[1]-=(new1[3])*0.10
            new1[2]*=1.1
            new1[3]*=1.1
            new_frame=frame[new1[1]:new1[1]+new1[3],new1[0]:new1[0]+new1[2]]
            new_frame=cv.blur(new_frame,(35,35))
            frame[new1[1]:new1[1]+new1[3],new1[0]:new1[0]+new1[2]]=new_frame
    except:
        pass
    cv.imshow('output',frame)
    if(cv.waitKey(1)&0xff == ord('q')):
        break
cam.release()
cv.destroyAllWindows()