#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
 void init () {

glClearColor (0.0, 0.0, 0.0,1.0);
glColor3f (1.0, 0.0, 0.0);
glPointSize (25);
glViewport(0, 0, 50, 50);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D (0,50,0,50);
}
void draw() {
glBegin (GL_POINTS);
glVertex2f (5.0, 5.0);
glVertex2f (5.0, 7.0);
glVertex2f (5.0,9.0);
glVertex2f (5.0,11.0);

glVertex2f (13.0, 5.0);
glVertex2f (13.0, 7.0);
glVertex2f (13.0, 9.0);
glVertex2f (13.0,11.0);

glVertex2f (7.0, 13.0);
glVertex2f (9.0, 13.0);
glVertex2f (11.0,13.0);


glVertex2f (5.0, 5.0);
glVertex2f (7.0, 5.0);
glVertex2f (9.0, 5.0);
glVertex2f (11.0, 5.0);
glEnd();
glFlush();
}
int main (int argc , char ** argv) {
glutInit (&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640,640);
glutInitWindowPosition (0,0);
glutCreateWindow ("OpenGL program");
init ();
glutDisplayFunc (draw);
glutMainLoop ();
}
