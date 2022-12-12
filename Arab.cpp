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


glEnd();

//tree base
glBegin(GL_QUADS);
glColor3ub (150, 75, 0);

glVertex2i(50, 110);
glVertex2i(50, 200);
glVertex2i(100, 200);
glVertex2i(100, 110);

glEnd();

//main leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(0, 200);
glVertex2i(150, 200);
glVertex2i(75, 320);
glEnd();

//top quad
glBegin(GL_QUADS);
glColor3ub (0, 155, 0);

glVertex2i(30, 200);
glVertex2i(30, 300);
glVertex2i(120, 300);
glVertex2i(120, 200);

glEnd();

//top tri
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(30, 300);
glVertex2i(75, 320);
glVertex2i(120, 300);

glEnd();

//r-tri
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(100, 230);
glVertex2i(100, 300);
glVertex2i(142, 260);
glEnd();

//r-tri
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(50, 230);
glVertex2i(50, 300);
glVertex2i(8, 260);
glEnd();



//right top tree
//tree base
glBegin(GL_QUADS);
glColor3ub (150, 75, 0);

glVertex2i(370, 130);
glVertex2i(370, 220);
glVertex2i(400, 220);
glVertex2i(400, 130);

glEnd();

//main leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(350, 200);
glVertex2i(420, 200);
glVertex2i(384, 320);
glEnd();

//r leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 175, 0);

glVertex2i(350, 200);
glVertex2i(420, 200);
glVertex2i(450, 300);
glEnd();

//l leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 255, 0);

glVertex2i(350, 200);
glVertex2i(420, 200);
glVertex2i(350, 300);
glEnd();

//l leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 200, 0);

glVertex2i(350, 200);
glVertex2i(420, 200);
glVertex2i(300, 280);
glEnd();



//river


//right big tree
//tree base
glBegin(GL_QUADS);
glColor3ub (150, 75, 0);

glVertex2i(750, 30);
glVertex2i(750, 220);
glVertex2i(780, 220);
glVertex2i(780, 30);

glEnd();

//main leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(720, 220);
glVertex2i(810, 220);
glVertex2i(760, 340);

glEnd();

//r leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 175, 0);

glVertex2i(720, 220);
glVertex2i(810, 220);
glVertex2i(800, 320);
glEnd();

//l leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 150, 0);

glVertex2i(720, 220);
glVertex2i(810, 220);
glVertex2i(680, 320);
glEnd();

//l leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 150, 0);

glVertex2i(720, 220);
glVertex2i(810, 220);
glVertex2i(650, 280);
glEnd();



//r leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 150, 0);

glVertex2i(720, 220);
glVertex2i(810, 220);
glVertex2i(850, 280);
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

