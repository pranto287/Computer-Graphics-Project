#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<cmath>


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(5.0);


//land
glBegin(GL_QUADS);
glColor3ub (255, 191, 128);

glVertex2i(0, 0);
glVertex2i(0, 200);
glVertex2i(840, 200);
glVertex2i(840, 0);
glEnd();

//pyramid-l
//back


glEnd();

//front
glBegin(GL_TRIANGLES);
glColor3ub (255, 153, 51);

glVertex2i(20, 200);
glVertex2i(300, 200);
glVertex2i(180, 380);

glEnd();


//pyramid-r
//back



//front




//tree base



//main leaf

//top tri

//r-tri

//r-tri



//right top tree
//tree base

//main leaf

//r leaf

//l leaf


//river


//right big tree
//tree base


glEnd();


glFlush ();
}

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