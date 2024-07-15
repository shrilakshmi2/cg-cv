#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
GLint X1,Y1,X2,Y2;
void LineBres(void){
glClear(GL_COLOR_BUFFER_BIT);
 int dx=abs(X2-X1),dy=abs(Y2-Y1);
 int p=2*dy-dx;
 int twoDy=2*dy,twoDyDx=2*(dy-dx);
 int x,y;
 if(X1>X2)
 {
 x=X2;
 y=Y2;
 X2=X1;
 }
 else
 {
 x=X1;
 y=Y1;
 X2=X2;
 }
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 while(x<X2)
 {
 x++;
 if(p<0)
 p+=twoDy;
 else
 {
 y++;
 p+=twoDyDx;
 }
 glVertex2i(x,y);
 }
 glEnd();
 glFlush();
}
void Init()
{
 glClearColor(1.0,1.0,1.0,0);
 glColor3f(1.0,0.0,0.0);
 glPointSize(8.0);
 glViewport(0,0,50,50);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0,50,0,50);
}
int main(int argc, char **argv)
{
 printf("enter two points to draw lineBresenham: ");
 printf("\n enter point1(X1,Y1): ");
 scanf("%d%d",&X1,&Y1);
 printf("\n enter point2(X2,Y2): ");
 scanf("%d%d",&X2,&Y2);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(300,400);
 glutInitWindowPosition(0,0);
 glutCreateWindow("LinearBresenham");
 Init();
 glutDisplayFunc(LineBres);
 glutMainLoop();
}
