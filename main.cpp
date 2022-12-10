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


//pyramid-l
//back
glBegin(GL_TRIANGLES);
glColor3ub (150, 75, 0);

glVertex2i(20, 200);
glVertex2i(340, 200);
glVertex2i(180, 380);

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
glBegin(GL_TRIANGLES);
glColor3ub (255, 153, 51);

glVertex2i(320, 200);
glVertex2i(580, 200);
glVertex2i(480, 400);

glEnd();

//tree base


//main leaf
glBegin(GL_TRIANGLES);
glColor3ub (0, 155, 0);

glVertex2i(0, 160);
glVertex2i(150, 160);
glVertex2i(75, 290);
glEnd();

//top quad

//top tri


//r-tri

//r-tri




//sun
int i1;
	GLfloat x1=50; GLfloat y1=400; GLfloat radius1 =20;
	int triangleAmount1 = 20;
	GLfloat twicePi1 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,0);
		glVertex2f(x1, y1);
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f(
		            x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
			    y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1))
			);
		}
	glEnd();


//cloud
int i2;
	GLfloat x2=550; GLfloat y2=400; GLfloat radius2 =30;
	int triangleAmount2 = 20;
	GLfloat twicePi2 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x2, y2);
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f(
		            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
			    y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
			);
		}
	glEnd();


	int i3;
	GLfloat x3=580; GLfloat y3=400; GLfloat radius3 =20;
	int triangleAmount3 = 20;
	GLfloat twicePi3 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x3, y3);
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f(
		            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
			    y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
			);
		}
	glEnd();


	int i4;
	GLfloat x4=510; GLfloat y4=400; GLfloat radius4 =20;
	int triangleAmount4 = 20;
	GLfloat twicePi4 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x4, y4);
		for(i4 = 0; i4 <= triangleAmount4; i4++) {
			glVertex2f(
		            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
			    y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
			);
		}
	glEnd();



glFlush ();
}

void myInit (void)
{
glClearColor(0, 1, 1, 1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (200, 200);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
