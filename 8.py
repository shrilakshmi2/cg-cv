import cv2
import numpy as np
image=cv2.imread("C:\\Users\\shril\\Downloads\\download.jpg")
height,width=image.shape[:2]
angle=45

scale_x=0.5
scale_y=0.5

tx=50
ty=50
rotation_matrix=cv2.getRotationMatrix2D((width/2,height/2),angle,1)
rotated_image=cv2.warpAffine(image,rotation_matrix,(width,height))
scaled_image=cv2.resize(image,None,fx=scale_x,fy=scale_y)

translation_matrix=np.float32([[1,0,tx],[0,1,ty]])
translated_image=cv2.warpAffine(image,translation_matrix,(width,height))
cv2.imshow('Original Image',image)
cv2.imshow('Rotated Image',rotated_image)
cv2.imshow('Scaled Image',scaled_image)
cv2.imshow('Translated Image',translated_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

