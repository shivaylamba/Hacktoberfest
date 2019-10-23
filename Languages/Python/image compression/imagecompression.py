#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 13 19:10:01 2019

@author: hegderajesh
"""

'''
8-bit is converted to 3-bit
Ecah pixel is matrix of value 0-255

2^8 = 2^3

0-31    0
32-63   1
64-95   2
96-127  3
...
224-255 7


'''
import numpy
from PIL import Image

im = Image.open('image.jpeg')
pixelMap = im.load()

img = Image.new(im.mode, im.size)
pixelNew = img.load()

I = numpy.asanyarray(Image.open('image.jpeg'))

for i in range(img.size[0]):
    for j in range(img.size[1]):
        if(pixelMap[i,j][0]>=0 and pixelMap[i,j][0]<=31):
            pixelNew[i,j] = (0,0,0)
            
        elif(pixelMap[i,j][0]>=32 and pixelMap[i,j][0]<=63):
            pixelNew[i,j] = (1,1,1)
            
        elif(pixelMap[i,j][0]>=64 and pixelMap[i,j][0]<=95):
            pixelNew[i,j] = (2,2,2)
        
        elif(pixelMap[i,j][0]>=96 and pixelMap[i,j][0]<=127):
            pixelNew[i,j] = (3,3,3)
        
        elif(pixelMap[i,j][0]>=128 and pixelMap[i,j][0]<=159):
            pixelNew[i,j] = (4,4,4)
            
        elif(pixelMap[i,j][0]>=160 and pixelMap[i,j][0]<=191):
            pixelNew[i,j] = (5,5,5)
            
        elif(pixelMap[i,j][0]>=192 and pixelMap[i,j][0]<=223):
            pixelNew[i,j] = (6,6,6)
        
        elif(pixelMap[i,j][0]>=224 and pixelMap[i,j][0]<=255):
            pixelNew[i,j] = (7,7,7)

img.save('compressed_image.jpeg')
J = numpy.asanyarray(Image.open('compressed_image.jpeg'))
