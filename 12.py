import cv2
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
image=cv2.imread("C:\\Users\\shril\\Downloads\\download (1).jpg")
gray=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
faces=face_cascade.detectMultiScale(gray,1.1,4)
for (x,y,w,h) in faces:
    cv2.rectangle(image,(x,y),(x+w,y+h),(255,0,0),2)
    cv2.rectangle(image,(x+2,y+2),(x+w-2,y+h-2),(0,225,0),2)
    cv2.imshow("Image",image)
    cv2.waitKey(0)