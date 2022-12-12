#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<cmath>


void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3ub (128, 128, 128);
glPointSize(5.0);



//pyramid-l
//back
glBegin(GL_TRIANGLES);
glColor3ub (150, 75, 0);

glVertex2i(20, 200);
glVertex2i(340, 200);
glVertex2i(180, 380);

glEnd();

//front



//pyramid-r
//back
glBegin(GL_TRIANGLES);
glColor3ub (150, 75, 0);

glVertex2i(320, 200);
glVertex2i(640, 200);
glVertex2i(480, 400);

glEnd();
//front


//tree base

//cloud 1
int i2;
	GLfloat x2=150; GLfloat y2=400; GLfloat radius2 =30;
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
	GLfloat x3=180; GLfloat y3=400; GLfloat radius3 =20;
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
	GLfloat x4=110; GLfloat y4=400; GLfloat radius4 =20;
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




//cloud 2
int i5;
	GLfloat x5=550; GLfloat y5=400; GLfloat radius5 =30;
	int triangleAmount5 = 20;
	GLfloat twicePi5 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x5, y5);
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f(
		            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
			    y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
			);
		}
	glEnd();


	int i6;
	GLfloat x6=580; GLfloat y6=400; GLfloat radius6 =20;
	int triangleAmount6 = 20;
	GLfloat twicePi6 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x6, y6);
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f(
		            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
			    y3 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
			);
		}
	glEnd();


	int i7;
	GLfloat x7=510; GLfloat y7=400; GLfloat radius7 =20;
	int triangleAmount7 = 20;
	GLfloat twicePi7 = 2.0f * 3.1416;

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(128, 124, 113);
		glVertex2f(x7, y7);
		for(i7 = 0; i7 <= triangleAmount7; i7++) {
			glVertex2f(
		            x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
			    y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
			);
		}
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
