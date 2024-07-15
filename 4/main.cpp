#include<windows.h>
#include<GL/glut.h>

int width = 800;
int height=600;
float rectWidth = 100.0f;
float rectHeight = 50.0f;
float rectPositionX = (width - rectWidth) / 2.0f;
float rectPositionY = (height - rectHeight) / 2.0f;
float rotationAngle = 0.0f;
float scaleFactor = 1.0f;

void drawRectangle(float x,float y,float width,float height)
{
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x+ width , y);
    glVertex2f(x+width, y+height);
    glVertex2f(x,y+height);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(rectPositionX, rectPositionY, 0.0f);
    glRotatef(rotationAngle,0.0f,0.0f,1.0f);
    glScalef(scaleFactor, scaleFactor,1.0f);
    glColor3f(1.0f,0.0f,0.0f);
    drawRectangle(0.0f,0.0f,rectWidth,rectHeight);
    glFlush();
}

void keyboard(unsigned char key, int x,int y)
{
    switch(key)
    {
        case 't':
            rectPositionX += 10.0f;
            break;
        case 'r':
            rotationAngle += 10.0f;
            break;
        case 's':
            scaleFactor *= 1.1f;
            break;
        case 'u':
            scaleFactor -= 1.1f;
            break;
        case 'e':
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void initializeOpenGL(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width,height);
    glutCreateWindow("Geometric operation in 2D");

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,width,0,height);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

}

int main(int argc,char **argv)
{
    initializeOpenGL(argc,argv);
    glutMainLoop();
    return 0;
}

