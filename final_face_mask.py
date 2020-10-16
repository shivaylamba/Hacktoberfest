import numpy as np
import cv2
import random

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')
mouth_cascade = cv2.CascadeClassifier('haarcascade_mcs_mouth.xml')
upper_body = cv2.CascadeClassifier('haarcascade_upperbody.xml')


bw_threshold = 80


font = cv2.FONT_HERSHEY_COMPLEX
org = (30, 30)
wore_mask_font_color = (0, 255, 0)
not_wore_mask_font_color = (0, 0, 255)
thickness = 2
font_scale = 1
wore_mask = "Mask: 100.0% Good Job!"
not_wore_mask = "Mask: 0.0% Please wear mask!"

cap = cv2.VideoCapture(0)

while True:
    ret, img = cap.read()
    img = cv2.flip(img,1)
    
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    (thresh, black_and_white) = cv2.threshold(gray, bw_threshold, 255, cv2.THRESH_BINARY)
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
    faces_bw = face_cascade.detectMultiScale(black_and_white, 1.1, 4)

    if(len(faces) == 0 and len(faces_bw) == 0):
        cv2.putText(img, "No face found...", org, font, font_scale, wore_mask_font_color, thickness, cv2.LINE_AA)
    elif(len(faces) == 0 and len(faces_bw) == 1):
        
        cv2.putText(img, wore_mask, org, font, font_scale, wore_mask_font_color, thickness, cv2.LINE_AA)
    else:
        
        for (x, y, w, h) in faces:
            cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 3)
            roi_gray = gray[y:y + h, x:x + w]
            roi_color = img[y:y + h, x:x + w]


            mouth_rects = mouth_cascade.detectMultiScale(gray, 1.5, 5)

        #if face is detected, but mouth is not, then the person is wearing mask.
        if(len(mouth_rects) == 0):
            cv2.putText(img, wore_mask, org, font, font_scale, wore_mask_font_color, thickness, cv2.LINE_AA)
        else:
            for (mx, my, mw, mh) in mouth_rects:

                if(y < my < y + h):
                   
                    cv2.putText(img, not_wore_mask, org, font, font_scale, not_wore_mask_font_color, thickness, cv2.LINE_AA)
                    break

    cv2.imshow('Mask Detection', img)
    if cv2.waitKey(1) & 0xFF==ord("q"):
        break

cap.release()
cv2.destroyAllWindows()
