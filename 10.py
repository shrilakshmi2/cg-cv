import cv2
import numpy as np
image=cv2.imread("C:\\Users\\shril\\Downloads\\download.jpg")
blurred_image=cv2.GaussianBlur(image,(5,5),0)
cv2.imshow('original Image',image)
cv2.imshow("guassian blur",blurred_image)
cv2.waitKey(0)
cv2.destroyAllWindows()