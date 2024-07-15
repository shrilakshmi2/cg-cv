import cv2
import numpy as np
import mediapipe as mp
import random

mp_drawing = mp.solutions.drawing_utils
mp_hands = mp.solutions.hands

score = 0
x_enemy = random.randint(50, 600)
y_enemy = random.randint(50, 400)

def enemy(image):
    global x_enemy, y_enemy
    cv2.circle(image, (x_enemy, y_enemy), 25, (0, 200, 0), 5)

# Initialize video capture
video = cv2.VideoCapture(0)

# Start hand tracking
with mp_hands.Hands(min_detection_confidence=0.8, min_tracking_confidence=0.5) as hands:
    while video.isOpened():
        _, frame = video.read()

        # Convert image to RGB format and flip horizontally
        image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        image = cv2.flip(image, 1)
        image_height, image_width, _ = image.shape

        # Process hand landmarks
        results = hands.process(image)

        # Convert image back to BGR format
        image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)

        # Draw score
        font = cv2.FONT_HERSHEY_SIMPLEX
        color = (255, 0, 255)
        cv2.putText(image, f"Score: {score}", (20, 50), font, 1, color, 4, cv2.LINE_AA)

        # Draw enemy circle
        enemy(image)

        # Check for hand landmarks and index finger tip
        if results.multi_hand_landmarks:
            for hand_landmarks in results.multi_hand_landmarks:
                # Draw hand landmarks
                mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(250, 44, 250), thickness=2, circle_radius=2),
                                          mp_drawing.DrawingSpec(color=(0, 255, 0), thickness=2, circle_radius=2))

                for point in mp_hands.HandLandmark:
                    normalized_landmark = hand_landmarks.landmark[point]
                    pixel_coordinates_landmark = mp_drawing._normalized_to_pixel_coordinates(
                        normalized_landmark.x, normalized_landmark.y, image_width, image_height)

                    if point == mp_hands.HandLandmark.INDEX_FINGER_TIP:
                        # Calculate distance between fingertip and enemy center
                        dist = np.sqrt((pixel_coordinates_landmark[0] - x_enemy)**2 +
                                       (pixel_coordinates_landmark[1] - y_enemy)**2)

                        # Check if fingertip is touching the enemy circle
                        if dist <= 25:
                            print("Found")
                            x_enemy = random.randint(50, 600)
                            y_enemy = random.randint(50, 400)
                            score += 1
                            cv2.putText(image, f"Score: {score}", (20, 50), font, 1, color, 4, cv2.LINE_AA)
                            enemy(image)

        # Display the image
        cv2.imshow('Hand Tracking', image)

        # Exit when 'q' is pressed
        if cv2.waitKey(10) & 0xFF == ord('q'):
            print(score)
            break

# Release video capture and close all windows
video.release()
cv2.destroyAllWindows()