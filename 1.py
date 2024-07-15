import cv2
import sys
import tkinter as tk
from tkinter import filedialog

class PlantDiseaseDetector:
    def __init__(self):
        self.MainWindow = tk.Tk()
        self.MainWindow.title("Plant Disease Detector ")
        self.S = tk.Scale(self.MainWindow, from_=0, to=255, length=500, 
                          orient=tk.HORIZONTAL,
                          background='white', fg='black', troughcolor='white', 
                          label="Processing Factor")
        self.S.pack()
        self.S.set(150)
        self.DiseasePercent = tk.StringVar()
        self.L = tk.Label(self.MainWindow, textvariable=self.DiseasePercent)
        self.L.pack()
        self.capture_button = tk.Button(self.MainWindow, text="Capture Image", command=self.CaptureImage)
        self.capture_button.pack()
        self.select_button = tk.Button(self.MainWindow, text="Select Image", command=self.SelectImage)
        self.select_button.pack()
        self.filename = ""
        self.camera_index = 0  # default camera index

    def CaptureImage(self):
        cap = cv2.VideoCapture(self.camera_index)
        if not cap.isOpened():
            print("Cannot open camera")
            return
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Cannot capture image")
                break
            cv2.imshow("Capture", frame)
            if cv2.waitKey(1) & 0xFF == ord('c'):  # press 'c' to capture
                cv2.imwrite("captured_image.jpg", frame)
                self.filename = "captured_image.jpg"
                self.ProcessImage(None)
                break
        cap.release()
        cv2.destroyAllWindows()

    def SelectImage(self):
        self.filename = filedialog.askopenfilename(title="Select Image")
        if self.filename!= "":
            self.ProcessImage(None)
        else:
            print("No File!")

    def ProcessImage(self, event=None):
        OriginalImage = cv2.imread(self.filename, 1)
        cv2.imshow("Original Image", OriginalImage)
        b = OriginalImage[:, :, 0]
        g = OriginalImage[:, :, 1]
        r = OriginalImage[:, :, 2]
        cv2.imshow("Red Channel", r)
        cv2.imshow("Green Channel", g)
        cv2.imshow("Blue Channel", b)
        Disease = r - g
        self.Alpha = b
        self.GetAlpha(OriginalImage)
        cv2.imshow("Alpha Channel", self.Alpha)
        ProcessingFactor = self.S.get()
        for i in range(0, OriginalImage.shape[0]):
            for j in range(0, OriginalImage.shape[1]):
                if int(g[i, j]) > ProcessingFactor:
                    Disease[i, j] = 255
        cv2.imshow("Disease Image", Disease)
        self.DisplayDiseasePercentage(Disease)

    def GetAlpha(self, OriginalImage):
        self.Alpha = OriginalImage.copy()
        for i in range(0, OriginalImage.shape[0]):
            for j in range(0, OriginalImage.shape[1]):
                if OriginalImage[i, j, 0] > 200 and OriginalImage[i, j, 1] > 200 and OriginalImage[i, j, 2] > 200:
                    self.Alpha[i, j] = 255
                else:
                    self.Alpha[i, j] = 0

    def DisplayDiseasePercentage(self, Disease):
        Count = 0
        Res =  0
        for i in range(0, Disease.shape[0]):
            for j in range(0, Disease.shape[1]):
                if self.Alpha[i, j] == 0:
                    Res += 1
                if Disease[i, j] < self.S.get():
                    Count += 1
        Percent = (Count / Res) * 100
        self.DiseasePercent.set("Percentage Disease: " + str(round(Percent, 2)) + "%")
        self.Alpha = None

    def run(self):
        self.MainWindow.mainloop()

if __name__== "__main__":
    detector = PlantDiseaseDetector()
    detector.run()