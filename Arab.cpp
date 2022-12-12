#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<cmath>



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
