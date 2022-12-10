#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;


#include<GL/gl.h>
#include <GL/glut.h>

//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 10;
float _moveC1 = -30.0;
float _moveC2 = -14.0;
float _moveC3= 8.0;
float _movesun1 = -1.5;
float _movesun2 = 14;
float _moveman1 = -6;
float _moveman2 = 4;
float _moveman3 = 0;
float _moveman4 = 5;
float _moveman5 = 5;
float _moveman6 = -2;
float _skyR = 0.0;
float _skyG = 0.8;
float _skyB = 1.0;
float _sunG = 1.0;
float _moveCar = -6;
float _cntrlCar = 5;
float scaleX = .4;
float scaleY = .4;
float scaleZ = .4;

bool isup = 0;
bool isDown = 0;
bool isOn = 0;


void sky()
{
    glPushMatrix();//sky
        glBegin(GL_POLYGON);
            glColor3f(_skyR,_skyG,_skyB);
            //glColor3f(0,0.8,1.0);
            glVertex3i(-50,0,0);
            glVertex3i(50,0,0);
            glVertex3i(50,40,0);
            glVertex3i(-50,40,0);

        glEnd();
    glPopMatrix();
    if(isDown == 0){
    glPushMatrix();
    glTranslatef(0,0,2);
    glPushMatrix();//cloud_1
    glTranslatef(_moveC1,0.0,0.0);
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-24.4,9.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-24.3,7.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-22.0,9.5,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.35,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-26,8.5,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-22.9,7.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();//cloud_2
    glTranslatef(_moveC2,0.0,0.0);
        glPushMatrix();
        glTranslatef(-5.0,9.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.0,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.5,9.2,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.15,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.8,8.2,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.0,8.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();//cloud_3
    glTranslatef(_moveC3,0.0,0.0);
        glPushMatrix();
        glColor3f(1.5,8.5,1.5);
        glTranslatef(-5.4,8.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-4.3,8.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.8,9,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.15,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.5,9,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.9,8.0,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    }
}

void sun()
{
    glPushMatrix();
    glColor3f(1,_sunG,0);
    glutSolidSphere(1.5,100,100);
    glPopMatrix();
}

void roof_part()
{
    glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-.45,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.25,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.05,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.15,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.25,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.45,.6,0);
    glutSolidCube(.2);
    glPopMatrix();
}

void window()
{
    glPushMatrix();
    glPushMatrix();
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(-.3,-.3,0);
    glVertex3f(.3,-.3,0);
    glVertex3f(.3,.3,0);
    glVertex3f(-.3,.3,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    if(isDown == 0)
        glColor3f(0,0,0);
    else
        glColor3f(.7,.7,0);
    glBegin(GL_QUADS);
    glVertex3f(-.25,-.2,.01);
    glVertex3f(-.05,-.2,.01);
    glVertex3f(-0.05,.2,.01);
    glVertex3f(-.25,.2,.01);
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(.05,-.2,.01);
    glVertex3f(.25,-.2,.01);
    glVertex3f(.25,.2,.01);
    glVertex3f(.05,.2,.01);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void line()
{
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0,0,.51);
    glBegin(GL_LINES);
    glVertex3f(-.5,0,0);
    glVertex3f(.5,0,0);
    glEnd();
    glPopMatrix();
}

void brick()
{
    glPushMatrix();
    glTranslatef(0,.45,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.40,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.35,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.30,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.25,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.20,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.15,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.10,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.05,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.00,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.05,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.10,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.15,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.20,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.25,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.30,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.35,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.40,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.45,0);
    line();
    glPopMatrix();

    glPushMatrix();
    glRotatef(90,0,0,1);
    glPushMatrix();
    glTranslatef(0,.45,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.35,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.25,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.15,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.05,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.05,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.15,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.25,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.35,0);
    line();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.45,0);
    line();
    glPopMatrix();
    glPopMatrix();
}

void room()
{
    glPushMatrix();

    glPushMatrix();
    glColor3f(.7,.2,0);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-.4);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,.4);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(180,0,1,0);
    brick();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,.52);
    window();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-.52);
    glRotatef(180,0,1,0);
    window();
    glPopMatrix();
    glPopMatrix();
}

void fatline()
{
    glPushMatrix();
    glTranslatef(0,-.5,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.45,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.4,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.35,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.3,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.25,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.2,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.15,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-.1,.5);
    glutSolidCube(.05);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.0,.5);
    glutSolidCube(.05);
    glPopMatrix();
}

void gate()
{
    glPushMatrix();
    glTranslatef(0,.4,0);
    glutWireCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,-.4);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,-.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,.0);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,.4);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glColor3f(.5,.5,.5);
    glRotatef(90,0,1,0);
    glTranslatef(0,0,.5);
    glBegin(GL_QUADS);
    glVertex3f(-.5,.6,0);
    glVertex3f(.5,.6,0);
    glVertex3f(.5,1,0);
    glVertex3f(-.5,1,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(.5,.5,.5);
    glRotatef(90,0,1,0);
    glTranslatef(0,0,-.5);
    glBegin(GL_QUADS);
    glVertex3f(-.5,.6,0);
    glVertex3f(.5,.6,0);
    glVertex3f(.5,1,0);
    glVertex3f(-.5,1,0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.4,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.3,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.2,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.1,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.1,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.2,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.3,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.4,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glColor3f(.6,.6,.6);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.5,.5);
    glVertex3f(.5,-.5,.5);
    glVertex3f(.5,-.5,-.5);
    glVertex3f(-.5,-.5,-.5);
    glEnd();
    glPopMatrix();
}

void anex_1()
{
    glPushMatrix();
    glTranslatef(-4,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    gate();
    glPopMatrix();
    glPushMatrix();
    glRotatef(180,0,1,0);
    gate();
    glPopMatrix();
}

void arena()
{
 glPushMatrix();
    glutWireCube(1);
    glPopMatrix();
   glPushMatrix();
    glTranslatef(0,0,-.4);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    //glTranslatef(0,0,.0);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,.2);
    roof_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,.4);
    roof_part();
    glPopMatrix();
    glColor3f(.7,.7,.7);
    glPushMatrix();
    glTranslatef(-.4,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.3,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.2,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.1,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.1,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.2,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.3,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.4,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.5,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.5,.4,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.5,.6,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5,0,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5,.4,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5,.6,0);
    fatline();
    glPopMatrix();
    glPushMatrix();
    glColor3f(.6,.6,.6);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.5,.5);
    glVertex3f(.5,-.5,.5);
    glVertex3f(.5,-.5,-.5);
    glVertex3f(-.5,-.5,-.5);
    glEnd();
    glPopMatrix();
}

void anex_2()
{
    glPushMatrix();
    glTranslatef(-4,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,1.2,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,1.2,0);
    room();
    glPopMatrix();
}

void anex_5()
{
    glPushMatrix();
    glTranslatef(-4,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    room();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,1.2,0);
    room();
    glPopMatrix();
}

void admin_building()
{
    glPushMatrix();//admin_building_main
        glColor3f(0.7,0.7,0.7);
        glRotatef(90,1,0,0);
        glTranslatef(0,0,-1.2);
        glutSolidSphere(1.5,20,20);
    glPopMatrix();

     glPushMatrix();//admin_building_window
        glColor3f(0.0,0.0,1.0);
        glRotatef(90,1,0,0);
        glTranslatef(0,0,-1.2);
        glutWireSphere(1.505,20,15);
    glPopMatrix();
    glPushMatrix();
    glScalef(.8,.8,.8);
    glTranslatef(0,-.8,0);
    glPushMatrix();
    glColor3f(.7,.7,.7);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    brick();
    glPopMatrix();
    glPushMatrix();
    glRotatef(180,0,1,0);
    brick();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,.52);
    window();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-.52);
    glRotatef(180,0,1,0);
    window();
    glPopMatrix();
    glPopMatrix();
}

void walkway()
{
    glPushMatrix();
    glColor3f(.7,.7,.7);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.5,.5);
    glVertex3f(.5,-.5,.5);
    glVertex3f(.5,-.5,-.5);
    glVertex3f(-.5,-.5,-.5);
    glEnd();
    glColor3f(.5,.5,.5);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,.5);
    glVertex3f(.5,-.6,.5);
    glVertex3f(.5,-.5,.5);
    glVertex3f(-.5,-.5,.5);
    glEnd();
    glPopMatrix();
}

void road_part()
{
    glPushMatrix();
    walkway();
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
}

void lampPost(){
    glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(.1,0,0);
        glVertex3f(.1,1.5,0);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(.1,0,0);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(.1,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-.1);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-.1);
        glVertex3f(0,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();

    glPopMatrix();
    glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,0);
        glVertex3f(1,1.5,0);
        glVertex3f(1,1.6,0);
        glVertex3f(0,1.6,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,-0.1);
        glVertex3f(1,1.5,-0.1);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,1.6,0);
        glVertex3f(1,1.6,0);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor4f(1,1,0,.5);
        glRotatef(-90,1,0,0);
        glTranslatef(.95,0.05,0.05);
        if(isOn)
            glutSolidCone(.6,1.5,10,10);
    glPopMatrix();
}

void car(){
    glPushMatrix();
    //glTranslatef(_moveCar, 0.0, -3.0); //Move forward 5 units

    glPushMatrix(); //Save the current state of transformations
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.9, 0.2, 1.0);
	glVertex3f(-0.9, 0.31, 1.0);
	glVertex3f(-0.75, 0.37, 1.0);
	glVertex3f(-0.75, 0.2, 1.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.75, 0.2, 1.0);
	glVertex3f(-0.75, 0.37, 1.0);
	glVertex3f(-0.3, 0.37, 1.0);
	glVertex3f(-0.3, 0.2, 1.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.3, 0.2, 1.0);
	glVertex3f(-0.3, 0.37, 1.0);
	glVertex3f(-0.15, 0.3, 1.0);
	glVertex3f(-0.15, 0.2, 1.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(0.950,0.950,0.950);
    glBegin(GL_QUADS);
    glVertex3f(-0.73, 0.38, 1.0);
	glVertex3f(-0.69, 0.47, 1.0);
	glVertex3f(-0.53, 0.47, 1.0);
	glVertex3f(-0.53, 0.38, 1.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(0.950,0.950,0.950);
    glBegin(GL_QUADS);
    glVertex3f(-0.5, 0.38, 1.0);
	glVertex3f(-0.5, 0.47, 1.0);
	glVertex3f(-0.36, 0.47, 1.0);
	glVertex3f(-0.32, 0.38, 1.0);
	glEnd();
	glPopMatrix();


	glPushMatrix(); //Save the current state of transformations
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.75, 0.37, 1.0);
	glVertex3f(-0.7, 0.48, 1.0);
	glVertex3f(-0.35, 0.48, 1.0);
	glVertex3f(-0.3, 0.37, 1.0);
	glEnd();
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(0.0,0.0,1.0);
	glTranslatef(-0.75, 0.2, 1.0); //Move to the center of the triangle
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glutSolidTorus(0.01,0.06,5,20);
    glColor3f(1.0,1.0,1.0);
	glutSolidTorus(0.01,0.04,5,20);
    glColor3f(0.0,0.0,0.0);
	glutSolidTorus(0.02,0.02,5,20);
	glPopMatrix();

	glPushMatrix(); //Save the current state of transformations
    glColor3f(0.0,0.0,1.0);
	glTranslatef(-0.3, 0.2, 1.0); //Move to the center of the triangle
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glutSolidTorus(0.01,0.06,5,20);
    glColor3f(1.0,1.0,1.0);
	glutSolidTorus(0.01,0.04,5,20);
    glColor3f(0.0,0.0,0.0);
	glutSolidTorus(0.02,0.02,5,20);
	glPopMatrix();


	glPopMatrix();
}

void smallW(){
     glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(.7,.2,0);
        glVertex3f(-6,0,0);
        glVertex3f(6,0,0);
        glVertex3f(6,.3,0);
        glVertex3f(-6,.3,0);
    glEnd();
    glPushMatrix();
    glTranslatef(0,0,.01);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-6,.1,0);
        glVertex3f(6,.1,0);

        glVertex3f(-6,.2,0);
        glVertex3f(6,.2,0);
    glEnd();
    glPopMatrix();
    glTranslatef(0,0,-.01);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-6,.1,0);
        glVertex3f(6,.1,0);

        glVertex3f(-6,.2,0);
        glVertex3f(6,.2,0);
    glEnd();
    glPopMatrix();
}

void tree(){
        glPushMatrix();
        glColor3f(.8,.3,0);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(.1,0,0);
        glVertex3f(.1,.4,0);
        glVertex3f(0,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(.1,0,0);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,.4,-.1);
        glVertex3f(.1,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-.1);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,.4,-.1);
        glVertex3f(0,.4,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-.1);
        glVertex3f(0,.4,-.1);
        glVertex3f(0,.4,0);
        glEnd();
        glPushMatrix();
        glTranslatef(0.05,.35,-.05);
        glColor3f(0,.8,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.18,.5,10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.05,.50,-.05);
        glColor3f(0,1,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.2,.5,10,10);
        glPopMatrix();
    glPopMatrix();
}

void bigW(){
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(.7,.2,0);
        glVertex3f(-6,0,0);
        glVertex3f(6,0,0);
        glVertex3f(6,.8,0);
        glVertex3f(-6,.8,0);
    glEnd();
    glPushMatrix();
    glTranslatef(0,0,.01);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-6,.1,0);
        glVertex3f(6,.1,0);

        glVertex3f(-6,.2,0);
        glVertex3f(6,.2,0);

        glVertex3f(-6,.3,0);
        glVertex3f(6,.3,0);

        glVertex3f(-6,.4,0);
        glVertex3f(6,.4,0);

        glVertex3f(-6,.5,0);
        glVertex3f(6,.5,0);

        glVertex3f(-6,.6,0);
        glVertex3f(6,.6,0);

        glVertex3f(-6,.7,0);
        glVertex3f(6,.7,0);
    glEnd();
    glPopMatrix();
    glTranslatef(0,0,-.01);
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-6,.1,0);
        glVertex3f(6,.1,0);

        glVertex3f(-6,.2,0);
        glVertex3f(6,.2,0);

        glVertex3f(-6,.3,0);
        glVertex3f(6,.3,0);

        glVertex3f(-6,.4,0);
        glVertex3f(6,.4,0);

        glVertex3f(-6,.5,0);
        glVertex3f(6,.5,0);

        glVertex3f(-6,.6,0);
        glVertex3f(6,.6,0);

        glVertex3f(-6,.7,0);
        glVertex3f(6,.7,0);
    glEnd();
    glPopMatrix();
}

void man(){
    glPushMatrix(); //Save the transformations performed thus far
    glRotatef(_angle,0,1,0);
    glScalef(.1,.1,.1);
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(0,1,0);
        glutSolidCube(.5);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(0,.1,0);
        glutSolidCube(1.2);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0,-.2,0);
        glutSolidCube(1.2);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.5,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.3,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.1,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.5,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.3,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.1,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(.9,-0.2,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(.9,-0.4,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(-.9,-0.2,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(-.9,-0.4,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.0,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.2,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.4,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.6,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.0,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.2,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.4,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.6,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(.3,-1.9,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(.3,-2.0,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(-.3,-1.9,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(-.3,-2.0,0);
        glutSolidCube(.25);
        glPopMatrix();
    glPopMatrix();

}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0);//Move forward 5 units

    glPushMatrix();
    glRotatef(_ang_tri,1,0,0);
    glRotatef(_angle,0,1,0);
    //glTranslatef(0,0,2.0);
    glScalef(scaleX, scaleY,scaleZ);
    glPushMatrix();
    glTranslatef(-3,0,1);
    anex_1();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4.2,.5,-2.0);
    admin_building();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6,0,-.1);
    glPushMatrix();
    anex_2();//anex2
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,1.18,0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,-1.0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,1.18,-1.0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-2.0);
    anex_2();//anex3
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,-2.0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,1.18,-2.0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-5,0,3);
    anex_2();//anex4
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,-2);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,1.18,-2);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,-2);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,1.18,-2);
    arena();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-5,0,0);
    glPushMatrix();
    anex_5();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,1.18,0);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,-1);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,1.18,-1);
    glRotatef(90,0,1,0);
    arena();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-5,0,-2);
    anex_2();//anex6
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,-2);
    arena();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,1.18,-2);
    arena();
    glPopMatrix();
    glPushMatrix();//field
    glColor3f(0.0,0.6,0.0);
    glBegin(GL_POLYGON);
    glVertex3f(-30,-.55,30);
    glVertex3f(30,-.55,30);
    glVertex3f(30,-.55,-30);
    glVertex3f(-30,-.55,-30);
    glEnd();
    glPopMatrix();
    glPushMatrix();//sky
    glTranslatef(0,-.5,-30);
    sky();
    glPopMatrix();
    glPushMatrix();//sky
    glRotatef(90,0,1,0);
    glTranslatef(0,-.5,-30);
    sky();
    glPopMatrix();
    glPushMatrix();//sun
    if(isup == 0)
    {
        glTranslatef(-28,_movesun1,0);
        sun();
    }
    glPopMatrix();
    glPushMatrix();//sky
    glRotatef(-90,0,1,0);
    glTranslatef(0,-.5,-30);
    sky();
    glPopMatrix();
    glPushMatrix();//sky
    glRotatef(180,0,1,0);
    glTranslatef(0,-.5,-30);
    sky();
    glPopMatrix();
    glPushMatrix();//sun
    if(isup == 1){
        glTranslatef(28,_movesun2,0);
        sun();
    }
    glPopMatrix();
    glPushMatrix();//road & Walkway
    glScalef(.7,.7,.7);
    glPushMatrix();
    glTranslatef(-17,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-16,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-15,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-14,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-13,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-12,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-11,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-9,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-8,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-7,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(7,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,7);
    road_part();
    glPopMatrix();
    glPushMatrix();//car1
    glTranslatef(_moveCar,-0.8,10.8);
    glRotatef(180,0,1,0);
    glScalef(2,2,2);
    car();
    glPopMatrix();
    glPushMatrix();//car2
    glTranslatef(_cntrlCar,-0.8,11.2);
    glRotatef(180,0,1,0);
    glScalef(2,2,2);
    car();
    glPopMatrix();
    glPushMatrix();//car3
    glRotatef(90,0,1,0);
    glTranslatef(3,-0.8,7.2);
    glScalef(2,2,2);
    car();
    glPopMatrix();
    glPushMatrix();//car4
    glRotatef(90,0,1,0);
    glTranslatef(5,-0.8,7.2);
    glScalef(2,2,2);
    car();
    glPopMatrix();
    glPushMatrix();//car5
    glRotatef(90,0,1,0);
    glTranslatef(7,-0.8,7.2);
    glScalef(2,2,2);
    car();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,0,7);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11,0,7);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11.5,0,7);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,7);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,6);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,5);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,4);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,3);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,2);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,1);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-2);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,0);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-3);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-4);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-5);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-6);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-7);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-8);
    glRotatef(90,0,1,0);
    road_part();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,-1);
    glRotatef(90,0,1,0);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(9,0,-1);
    glRotatef(90,0,1,0);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11.5,0,-1);
    glRotatef(180,0,1,0);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11.5,0,-3);
    glRotatef(180,0,1,0);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(11.5,0,-5.5);
    glRotatef(180,0,1,0);
    glColor3f(.3,.3,.3);
    glBegin(GL_QUADS);
    glVertex3f(-.5,-.6,3.0);
    glVertex3f(.5,-.6,3.0);
    glVertex3f(.5,-.6,.5);
    glVertex3f(-.5,-.6,.5);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(8,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(7,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(5,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,0);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,-1);
    glRotatef(90,0,1,0);
    walkway();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3,0,-2);
    glRotatef(180,0,1,0);
    walkway();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glRotatef(90,0,-1,0);
    glTranslatef(4.4,-.5,12);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glRotatef(90,0,-1,0);
    glTranslatef(4.4,-.5,9);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glRotatef(90,0,-1,0);
    glTranslatef(4.4,-.5,5);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glRotatef(90,0,-1,0);
    glTranslatef(4.4,-.5,1);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glRotatef(90,0,-1,0);
    glTranslatef(4.4,-.5,-3);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glTranslatef(5.85,-.5,1.5);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glTranslatef(5.85,-.5,3.5);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glTranslatef(5.1,-.5,-4);
    lampPost();
    glPopMatrix();
    glPushMatrix();//Lamppost
    glTranslatef(5.1,-.5,-5.5);
    lampPost();
    glPopMatrix();
    glPushMatrix();//smallWall
    glTranslatef(-5.9,-.5,4.3);
    smallW();
    glPopMatrix();
    glPushMatrix();//smallWall
    glTranslatef(0,-.5,4.3);
    smallW();
    glPopMatrix();
    glPushMatrix();//smallWall
    glRotatef(90,0,1,0);
    glScalef(.32,1,1);
    glTranslatef(-7.5,-.5,5.8);
    smallW();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.1,-.5,1.2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-9.1,-.5,1.2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-8.1,-.5,1.2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.35,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5.35,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4.35,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,2);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.7,-.5,1.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.7,-.5,1);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.7,-.5,.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-3.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-4.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-5.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-6.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-7.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-8.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.5,-.5,-9.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-8.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-7.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-6.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-5.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-4.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-3.8,-.5,-3.5);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-5.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-7.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-8.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-9.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.8,-.5,-2.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.8,-.5,-1.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.8,-.5,-.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-10.8,-.5,.8);
    tree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-7,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(3,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glRotatef(45,0,1,0);
    glScalef(.6,1,1);
    glTranslatef(-1,-.5,14);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(6.5,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,-1,0);
    glTranslatef(-6.5,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,-1,0);
    glTranslatef(-2.0,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glRotatef(90,0,1,0);
    glTranslatef(-1.5,-.5,12);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6.0,-.5,-12.5);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-6.0,-.5,-12.5);
    bigW();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_moveman1,0,5.0);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_moveman2,0,5.0);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_moveman3,0,5.0);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6.5,0,_moveman4);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_moveman5,0,.2);
    man();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(_moveman6,0,.2);
    man();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();// exchange for glFlash()
}

void cloudeMov()
{
     _moveC1 += 0.3;
    if(_moveC1>= 50.9)
        _moveC1 = -30;

     _moveC2 += 0.3;
    if(_moveC2>= 30.9)
        _moveC2 = -30;


     _moveC3 += 0.35;
    if(_moveC3>= 30.9)
        _moveC3 = -30;
}

void update(int value) {
    cloudeMov();
    //Tell GLUT that the display has changed

    if(isup == 0){
    _movesun1 += .25;
    if(_movesun1>=30){
        _movesun1= -2;
        isup = 1;
     }
     _skyG = 0.8;
     _skyB = 1;
     _sunG = 1;
    }

    if(isup == 1){
        _movesun2 -= .25;
        if(_movesun2<= -15){
            _movesun2 = 14;
            isup = 0;
            isDown = 0;
        }
        if(_movesun2<= -3.0)
            isDown = 1;
        _skyG -= 0.008;
        _skyB -= 0.010;
        _sunG -= 0.01;

    }
        _moveCar += .25;
        if(_moveCar>=5.5)
            _moveCar = -18.5;

    _moveman1 += .1;
    if(_moveman1>=5)
        _moveman1 = -7.5;
    _moveman2 += .05;
    if(_moveman2>=5)
        _moveman2 = -7.5;
    _moveman3 += .1;
    if(_moveman3>=5)
        _moveman3 = -7.5;

    _moveman4 -= .05;
    if(_moveman4<=2)
        _moveman4 = 5;
    _moveman5 -= .1;
    if(_moveman5<=-3)
        _moveman5 = 2;
    _moveman6 += .15;
    if(_moveman6>=2.5)
        _moveman6 = -3;
    //Tell GLUT to call update again in 25 milliseconds
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'o':
        if(isOn == 0)
            isOn = 1;
        else
            isOn = 0;
        glutPostRedisplay();
        break;
    case 'a':
        _cntrlCar -= .25;
        break;
    case 'd':
        _cntrlCar += .25;
        break;
    default:
        break;
    case '+':
        scaleX += .1;
        scaleY += .1;
        scaleZ += .1;
        break;
    case '-':
        scaleX -= .1;
        scaleY -= .1;
        scaleZ -= .1;
        break;
    }
}

void specialKey(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_LEFT:
        _angle += .5f;
        if(_angle>=360)
            _angle = 0.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        _angle -= .5f;
        if(_angle>=360)
            _angle = 0.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        _ang_tri += .5;
        if(_ang_tri>=180)
            _ang_tri=0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        _ang_tri -= .5;
        if(_ang_tri<= 0)
            _ang_tri = 180;
        break;
    default:
        break;
    }
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0.0,1360,0.0,800);
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1360, 600);

    //Create the window
    glutCreateWindow("AIUB Campus");
    initRendering();
    init();

    //Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutTimerFunc(30, update, 0); //Add a timer

    glutMainLoop();
    return 0;
}
