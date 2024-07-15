import cv2
import numpy as np
image= cv2.imread("C:\\Users\\shril\\Downloads\\download.jpg")
h,w=image.shape[:2]
angle=45
scale_x=0.5
scale_y=0.5
tx=50
ty=50
rotation_matrix=cv2.getRotationMatrix2D((w/2,h/2),angle,1)
rotation_image=cv2.warpAffine(image,rotation_matrix,(w,h))
scaled_image=cv2.resize(image,None,fx=scale_x,fy=scale_y)
translation_matrix=np.float32([[0,1,tx],[1,0,ty]])
translation_image=cv2.warpAffine(image,translation_matrix,(w,h))
cv2.imshow('Original Image',image)
cv2.imshow('Rotated Image',rotation_image)
cv2.imshow('Scaled Image',scaled_image)
cv2.imshow('Translated Image',translation_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

