import cv2
image= cv2.imread("C:\\Users\\shril\\Downloads\\download.jpg")

gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
edges=cv2.Canny(gray,100,200)
contours,hierarcy= cv2.findContours(edges,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
cv2.drawContours(gray,contours,-1,(0,0,220),2)

cv2.imshow("counters",gray)

cv2.waitKey(0)
cv2.destroyAllWindows()