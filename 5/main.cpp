#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

float translateX = 0.0f, translateY = 0.0f, translateZ = -6.0f;
float rotateX = 30.0f, rotateY = 30.0f, rotateZ = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Apply transformations
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(scaleX, scaleY, scaleZ);

    glBegin(GL_TRIANGLES);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Right face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Back face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);

    // Left face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();
    glutSwapBuffers(); // Swap the buffers
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            translateY += 0.1f;
            break;
        case 's':
            translateY -= 0.1f;
            break;
        case 'a':
            translateX -= 0.1f;
            break;
        case 'd':
            translateX += 0.1f;
            break;
        case 'q':
            translateZ += 0.1f;
            break;
        case 'e':
            translateZ -= 0.1f;
            break;
        case 'i':
            rotateX += 5.0f;
            break;
        case 'k':
            rotateX -= 5.0f;
            break;
        case 'j':
            rotateY -= 5.0f;
            break;
        case 'l':
            rotateY += 5.0f;
            break;
        case 'u':
            rotateZ -= 5.0f;
            break;
        case 'o':
            rotateZ += 5.0f;
            break;
        case '+':
            scaleX += 0.1f;
            scaleY += 0.1f;
            scaleZ += 0.1f;
            break;
        case '-':
            scaleX -= 0.1f;
            scaleY -= 0.1f;
            scaleZ -= 0.1f;
            break;
        case 27: // ESC key
            exit(0);
    }
    glutPostRedisplay(); // Request a redisplay
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Geometric operations in 3D");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register the keyboard callback function
    init();
    glutMainLoop();
    return 0;
}
