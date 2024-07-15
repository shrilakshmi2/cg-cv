#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include <iostream>
float squareX = 0.0f; // X position of the square
float squareY = 0.0f; // Y position of the square
float squareSize = 0.2f; // Size of the square
float moveSpeed = 0.01f; // Movement speed of the square
void init() {
 glClearColor(0.0, 0.0, 0.0, 1.0); // Set clear color to black
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
 glColor3f(1.0, 0.0, 1.0); // Set drawing color to white
 // Draw the square
 glBegin(GL_POLYGON);
 glVertex2f(squareX, squareY);
 glVertex2f(squareX + squareSize, squareY);
 glVertex2f(squareX + squareSize, squareY + squareSize);
 glVertex2f(squareX, squareY + squareSize);
 glEnd();
 glutSwapBuffers(); // Swap the front and back buffers (double buffering)
}
void timer(int) {
 // Update square position
 squareX += moveSpeed;
 if (squareX > 1.0 || squareX < -1.0) {
 moveSpeed = -moveSpeed; // Reverse direction when hitting edges
 }
 glutPostRedisplay(); // Request a redraw
 glutTimerFunc(16, timer, 0); // 60 FPS (1000 ms / 60 = 16.67 ms per frame)
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(800, 600); // Set the window size
 glutCreateWindow("OpenGL Animation");
 glutDisplayFunc(display);
 glutTimerFunc(0, timer, 0); // Call the timer function immediately
 init(); // Initialize OpenGL parameters
 glutMainLoop(); // Enter the main loop
 return 0;
}
