#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<cmath>



void myInit (void)
{
glClearColor(.3, .4, 1, 1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 840.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (840, 480);
glutInitWindowPosition (200, 200);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
