""" Convert RGB Image to Gray """
import cv2 
import argparse
from IPython.core.debugger import set_trace

# Terminal Argument passing of image file 
arg = argparse.ArgumentParser(description="Enter image path")
arg.add_argument("-i","--image", required=True, help="path to image")
args = vars(arg.parse_args())

def getPath(path):
    x = path.split("\\")
    x = x[:-1]
    temp = "\\".join(x)
    return temp


image = cv2.imread(args['image'])

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
path = getPath(args['image'])
status = cv2.imwrite(path + 'grayImage.jpg' ,gray)

cv2.destroyAllWindows()
