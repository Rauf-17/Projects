#include <windows.h>

#include <GL/glut.h>

#include <math.h>

#include<cstdio>


  /* Name: Raufull Islam Rauf ID: 21-45779-3
     Name: Sadia Afrose ID: 21-45820-3
     Name: Rafayet Zaaman Abir ID: 21-45791-3
     Name: MD. Naimul Islam ID: 21-45801-3  */


   GLfloat position = 0.0f;

   GLfloat speed = 0.002f;


    GLfloat position1 = 0.0f;

   GLfloat speed1 = 0.001f;


   GLfloat position2 = 0.0f;

   GLfloat speed2 = 0.007f;


void update2(int value)

{

    if(position2 <= -1.9f)

    position2 = 1.0f;

    position2 -= speed2;

    glutPostRedisplay();

    glutTimerFunc(1000/70, update2, 0);


}


void update(int value)

{

    if(position <= -1.9f)

    position = 1.0f;

    position -= speed;

    glutPostRedisplay();

    glutTimerFunc(1000/60, update, 0);


}

void update1(int value)

{

    if(position1 <= -1.9f)

    position1 = 1.0f;

    position1 -= speed1;

    glutPostRedisplay();

    glutTimerFunc(1000/50, update1, 0);


}



void circle(float radius, float xc, float yc, float r, float g, float b)

{

    glBegin(GL_POLYGON);

	for(int i = 0; i < 200; i++)

        {

            glColor3ub(r, g, b);

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=radius;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+xc,y+yc);

        }

	glEnd();

}

void display()

{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);


	//sky color

    glBegin(GL_QUADS);

    glColor3ub(135 ,206 ,250);

    glVertex2f(-1.0f, 1.0f);

    glVertex2f(-1.0f, 0.3f);

    glVertex2f(1.0f, 0.3f);

    glVertex2f(1.0f, 1.0f);

    glEnd();

    //--------------------------------------------------


	//Sun

	glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    circle(0.055,-0.9,0.93,255,255,0);

    glPopMatrix();

    //------------------------------


	//Cloud 1

	glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);


    circle(0.02,-0.2,0.88,191,239,255);

    circle(0.022,-0.229,0.88,191,239,255);

    circle(0.015,-0.243,0.88,191,239,255);

    circle(0.022,-0.171,0.88,191,239,255);

    circle(0.015,-0.157,0.88,191,239,255);

    circle(0.015,-0.213,0.9,191,239,255);

    circle(0.015,-0.213,0.86,191,239,255);

    circle(0.015,-0.187,0.9,191,239,255);

    circle(0.015,-0.187,0.86,191,239,255);

    circle(0.015,-0.2,0.91,191,239,255);

    circle(0.015,-0.2,0.85,191,239,255);

    glPopMatrix();

    //------------------------------------------------


    //Cloud 2

    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    circle(0.02,0.25,0.9,191,239,255);

    circle(0.022,0.279,0.89,191,239,255);

    circle(0.017,0.293,0.89,191,239,255);

    circle(0.022,0.221,0.89,191,239,255);

    circle(0.017,0.207,0.89,191,239,255);

    circle(0.015,0.263,0.87,191,239,255);

    circle(0.015,0.237,0.87,191,239,255);

    glPopMatrix();

    //------------------------------------------------


    //Cloud 3

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    circle(0.024,0.9,0.9,191,239,255);

    circle(0.022,0.929,0.89,191,239,255);

    circle(0.017,0.943,0.89,191,239,255);

    circle(0.022,0.871,0.89,191,239,255);

    circle(0.017,0.857,0.89,191,239,255);

    circle(0.015,0.913,0.91,191,239,255);

    circle(0.015,0.887,0.91,191,239,255);

    glPopMatrix();

    //------------------------------------------------


    //Cloud 4

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    circle(0.025,-0.59,0.86,191,239,255);

    circle(0.018,-0.62,0.86,191,239,255);

    circle(0.018,-0.56,0.86,191,239,255);

    glPopMatrix();

    //------------------------------------------------


    //Cloud 5

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    circle(0.025,0.59,0.86,191,239,255);

    circle(0.018,0.62,0.86,191,239,255);

    circle(0.018,0.56,0.86,191,239,255);

    glPopMatrix();

    //------------------------------------------------



    //road full

    glBegin(GL_QUADS);

    glColor3ub(102 ,102 ,102);

    glVertex2f(-1.0f, 0.32f);

    glVertex2f(-1.0f, -0.1f);

    glVertex2f(1.0f, -0.1f);

    glVertex2f(1.0f, 0.32f);

    glEnd();

    //-----------------------------------------------------


    //Road Front 1

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f, -0.079f);

    glVertex2f(1.0f, -0.079f);

    glVertex2f(1.0f, -0.085f);

    glVertex2f(-1.0f, -0.085f);

    glEnd();

    //-------------------------------------------


    //Front 2

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f,0.18f);

    glVertex2f(-1.0f,0.195f);

    glVertex2f(1.0f,0.195f);

    glVertex2f(1.0f,0.18f);

    glEnd();

    //-------------------------------------------


    //Front Road Markers 1st lane

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.09f);

    glVertex2f(1.0f,0.07f);

    glVertex2f(0.8f,0.07f);

    glVertex2f(0.83f,0.09f);

    glVertex2f(0.73f,0.09f);

    glVertex2f(0.7f,0.07f);

    glVertex2f(0.5f,0.07f);

    glVertex2f(0.53f,0.09f);

    glVertex2f(0.43f,0.09f);

    glVertex2f(0.4f,0.07f);

    glVertex2f(0.2f,0.07f);

    glVertex2f(0.23f,0.09f);

    glVertex2f(0.1f,0.09f);

    glVertex2f(0.07f,0.07f);

    glVertex2f(-0.13f,0.07f);

    glVertex2f(-0.1f,0.09f);

    glVertex2f(-0.2f,0.09f);

    glVertex2f(-0.23f,0.07f);

    glVertex2f(-0.43f,0.07f);

    glVertex2f(-0.4f,0.09f);

    glVertex2f(-0.5f,0.09f);

    glVertex2f(-0.53f,0.07f);

    glVertex2f(-0.73f,0.07f);

    glVertex2f(-0.7f,0.09f);

    glVertex2f(-0.8f,0.09f);

    glVertex2f(-0.83f,0.07f);

    glVertex2f(-1.0f,0.07f);

    glVertex2f(-1.0f,0.09f);

    glEnd();

    //-----------------------------------------


    //Road Front Side Back 1

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.20f);

    glVertex2f(1.0f,0.21f);

    glVertex2f(-1.0f,0.21f);

    glVertex2f(-1.0f,0.20f);

    glEnd();

    //-------------------------------------------


    //Road Markers 2nd lane

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.255f);

    glVertex2f(1.0f,0.26f);

    glVertex2f(0.811f,0.26f);

    glVertex2f(0.8f,0.255f);

    glVertex2f(0.7f,0.255f);

    glVertex2f(0.711f,0.26f);

    glVertex2f(0.511f,0.26f);

    glVertex2f(0.5f,0.255f);

    glVertex2f(0.4f,0.255f);

    glVertex2f(0.411f,0.26f);

    glVertex2f(0.211f,0.26f);

    glVertex2f(0.2f,0.255f);

    glVertex2f(0.091f,0.255f);

    glVertex2f(0.1f,0.26f);

    glVertex2f(-0.1f,0.26f);

    glVertex2f(-0.111f,0.255f);

    glVertex2f(-0.211f,0.255f);

    glVertex2f(-0.2f,0.26f);

    glVertex2f(-0.4f,0.26f);

    glVertex2f(-0.411f,0.255f);

    glVertex2f(-0.511f,0.255f);

    glVertex2f(-0.5f,0.26f);

    glVertex2f(-0.7f,0.26f);

    glVertex2f(-0.711f,0.255f);

    glVertex2f(-0.811f,0.255f);

    glVertex2f(-0.8f,0.26f);

    glVertex2f(-1.0f,0.26f);

    glVertex2f(-1.0f,0.255f);

    glEnd();

    //--------------------------------------------------


    //Behind Back 2

    glBegin(GL_LINES);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f,0.31f);

    glVertex2f(1.0f,0.31f);

    glEnd();

    //------------------------------------------


    //road and train bridge connection

    glBegin(GL_POLYGON);

    glColor3f(1.0f,1.0f,1.0f);


    glVertex2f(-1.0f,-0.09f);

    glVertex2f(1.0f,-0.09f);

    glVertex2f(1.0f,-0.11f);

    glVertex2f(-1.0f,-0.11f);

    glEnd();


    //Bus Starts


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(255,0,0);

    glVertex2f(0.5f,0.0f);

    glVertex2f(0.9f,0.0f);

    glVertex2f(0.9f,-0.06f);

    glVertex2f(0.5f,-0.06f);

    glEnd();

    glPopMatrix();



    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(255,0,0);

    glVertex2f(0.5f,0.0f);

    glVertex2f(0.9f,0.0f);

    glVertex2f(0.9f,0.08f);

    glVertex2f(0.54f,0.08f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_LINES);

    glColor3ub(0,100,0);

    glVertex2f(0.58f,0.02f);

    glVertex2f(0.85f,0.02f);

    glEnd();

    glPopMatrix();


     glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_LINES);

    glColor3ub(0,100,0);

    glVertex2f(0.58f,0.04f);

    glVertex2f(0.85f,0.04f);

    glEnd();


    glPopMatrix();


    //wheel 1

     glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    circle(0.02f,0.6f,-0.06f,0,0,0);

    circle(0.01f,0.6f,-0.06f,255,255,255);

    //wheel 2


    circle(0.02f,0.8f,-0.06f,0,0,0);

    circle(0.01f,0.8f,-0.06f,255,255,255);

     glPopMatrix();

    //bus window

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.54f,-0.02f);

    glVertex2f(0.55f,0.06f);

    glVertex2f(0.58f,0.06f);

    glVertex2f(0.58f,-0.02f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.6f,0.0f);

    glVertex2f(0.6f,0.06f);

    glVertex2f(0.66f,0.06f);

    glVertex2f(0.66f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.68f,0.0f);

    glVertex2f(0.68f,0.06f);

    glVertex2f(0.74f,0.06f);

    glVertex2f(0.74f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.76f,0.0f);

    glVertex2f(0.76f,0.06f);

    glVertex2f(0.82f,0.06f);

    glVertex2f(0.82f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.84f,0.0f);

    glVertex2f(0.84f,0.06f);

    glVertex2f(0.87f,0.06f);

    glVertex2f(0.87f,0.0f);

    glEnd();


    glPopMatrix();


    //Light of Bus

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(255,215,0);

    glVertex2f(0.5f,-0.02f);

    glVertex2f(0.51f,-0.02f);

    glVertex2f(0.51f,-0.03f);

    glVertex2f(0.5f,-0.03f);


    glEnd();


    glPopMatrix();


    //bus ends----------------------------------------------



    //car 2 on bus road


    // car body


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0 );

    glVertex2f(-0.95f,0.19f);

    glVertex2f(-0.96f,0.13f);

    glVertex2f(-0.75f,0.13f);

    glVertex2f(-0.77f,0.17f);

    glEnd();


    glPopMatrix();

     // car body under


     glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0);

    glVertex2f(-0.96f,0.13f);

    glVertex2f(-0.93f,0.12f);

    glVertex2f(-0.76f,0.12f);

    glVertex2f(-0.75f,0.13f);

    glEnd();


    glPopMatrix();

    // car upper

    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0 );

    glVertex2f(-0.87f,0.22f);

    glVertex2f(-0.94f,0.18f);

    glVertex2f(-0.78f,0.17f);

    glVertex2f(-0.82f,0.21f);

    glEnd();


    glPopMatrix();



      // car mirror back



      glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.88f,0.22f);

    glVertex2f(-0.92f,0.19f);

    glVertex2f(-0.90f,0.17f);

    glVertex2f(-0.86f,0.19f);

    glEnd();


    glPopMatrix();


      // car mirror front


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.82f,0.215f);

    glVertex2f(-0.83f,0.185f);

    glVertex2f(-0.795f,0.16f);

    glVertex2f(-0.78f,0.175f);

    glEnd();


     glPopMatrix();



      // car mirror middle


      glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.85f,0.19f);

    glVertex2f(-0.89f,0.17f);

    glVertex2f(-0.805f,0.16f);

    glVertex2f(-0.84f,0.187f);

    glEnd();


    glPopMatrix();



    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    circle(-0.02,-0.92,0.12,0,0,0);

    circle(-0.01,-0.92,0.12,255,255,255);


    circle(-0.02,-0.81,0.12,0,0,0);

    circle(-0.01,-0.81,0.12,255,255,255);


    glPopMatrix();


    //car 2 ends------------------------





    // Car on Lane 2 (Car 1)


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.98f,0.29f);

    glVertex2f(-0.88f,0.29f);

    glVertex2f(-0.86f,0.27f);

    glVertex2f(-0.96f,0.27f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.98f,0.29f);

    glVertex2f(-0.88f,0.29f);

    glVertex2f(-0.9f,0.31f);

    glVertex2f(-0.98f,0.31f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.97f,0.31f);

    glVertex2f(-0.91f,0.31f);

    glVertex2f(-0.93f,0.33f);

    glVertex2f(-0.95f,0.33f);



    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2f(-0.965f,0.31f);

    glVertex2f(-0.905f,0.31f);

    glVertex2f(-0.925f,0.33f);

    glVertex2f(-0.945f,0.33f);



    glEnd();




    circle(0.01f,-0.95f,0.27f,0,0,0);

    circle(0.005f,-0.95f,0.27f,255,255,255);

    circle(0.01,-0.9f,0.27f,0,0,0);

    circle(0.005,-0.9f,0.27f,255,255,255);


    glPopMatrix();



    //Car On Lane 2(Car 2)

    glPushMatrix();

	glTranslatef(position2,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(112,12,12);


    glVertex2f(0.78f,0.22f);

    glVertex2f(0.98f,0.22f);

    glVertex2f(0.98f,0.24f);

    glVertex2f(0.84f,0.24f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(112,12,12);

    glVertex2f(0.86f,0.24f);

    glVertex2f(0.89f,0.27f);

    glVertex2f(0.94f,0.27f);

    glVertex2f(0.96f,0.24f);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(25,25,25);

    glVertex2f(0.88f,0.24f);

    glVertex2f(0.9f,0.26f);

    glVertex2f(0.92f,0.26f);

    glVertex2f(0.94f,0.24f);

    glEnd();


    circle(0.01f,0.85f,0.22f,0,0,0);

    circle(0.005f,0.85f,0.22f,255,255,255);

    circle(0.01f,0.95f,0.22f,0,0,0);

    circle(0.005f,0.95f,0.22f,255,255,255);

    glPopMatrix();

    //car 2 ends--------------------------


    //Middle LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.02f,0.199f);
    glVertex2f(-0.02f,0.199f);
    glVertex2f(-0.02f,0.196f);
    glVertex2f(0.02f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.005f,0.197f);
    glVertex2f(-0.005f,0.197f);
    glVertex2f(-0.005f,0.7f);
    glVertex2f(0.005f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.005f,0.679f);
    glVertex2f(0.005f,0.67f);
    glVertex2f(0.07f,0.69f);
    glVertex2f(0.07f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.059f,0.694f);
    glVertex2f(0.059f,0.685f);
    glVertex2f(0.069f,0.685f);
    glVertex2f(0.069f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(-0.005f,0.679f);
    glVertex2f(-0.005f,0.67f);
    glVertex2f(-0.07f,0.65f);
    glVertex2f(-0.07f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.059f,0.65f);
    glVertex2f(-0.059f,0.644f);
    glVertex2f(-0.069f,0.647f);
    glVertex2f(-0.069f,0.657f);

    glEnd();

    //------------------------------------------


    //Right LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.72f,0.199f);
    glVertex2f(0.68f,0.199f);
    glVertex2f(0.68f,0.196f);
    glVertex2f(0.72f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.705f,0.197f);
    glVertex2f(0.695f,0.197f);
    glVertex2f(0.695f,0.7f);
    glVertex2f(0.705f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.705f,0.679f);
    glVertex2f(0.705f,0.67f);
    glVertex2f(0.77f,0.69f);
    glVertex2f(0.77f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.759f,0.694f);
    glVertex2f(0.759f,0.685f);
    glVertex2f(0.769f,0.685f);
    glVertex2f(0.769f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(0.695f,0.679f);
    glVertex2f(0.695f,0.67f);
    glVertex2f(0.63f,0.65f);
    glVertex2f(0.63f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.629f,0.65f);
    glVertex2f(0.629f,0.644f);
    glVertex2f(0.639f,0.647f);
    glVertex2f(0.639f,0.657f);

    glEnd();

    //------------------------------------------


    //Left LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(-0.72f,0.199f);
    glVertex2f(-0.68f,0.199f);
    glVertex2f(-0.68f,0.196f);
    glVertex2f(-0.72f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(-0.705f,0.197f);
    glVertex2f(-0.695f,0.197f);
    glVertex2f(-0.695f,0.7f);
    glVertex2f(-0.705f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(-0.695f,0.679f);
    glVertex2f(-0.695f,0.67f);
    glVertex2f(-0.63f,0.69f);
    glVertex2f(-0.63f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.629f,0.694f);
    glVertex2f(-0.629f,0.685f);
    glVertex2f(-0.639f,0.685f);
    glVertex2f(-0.639f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(245,245 ,245);

    glVertex2f(-0.705f,0.679f);
    glVertex2f(-0.705f,0.67f);
    glVertex2f(-0.77f,0.65f);
    glVertex2f(-0.77f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.779f,0.65f);
    glVertex2f(-0.779f,0.644f);
    glVertex2f(-0.769f,0.647f);
    glVertex2f(-0.769f,0.657f);

    glEnd();

    //-----------------------------------------



    //-------------------------------------------------------

    // water color

    glBegin(GL_POLYGON);

    glColor3ub(24 ,116, 205);

    glVertex2f(-1.0f, -1.0f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(1.0f,-0.1f);


    glVertex2f(1.0f,-0.1f);

    glVertex2f(1.0f,-1.0f);

    glVertex2f(1.0f,-1.0f);

    glVertex2f(-1.0f, -1.0f);

    glEnd();

    //----------------------------------------------------



    //train Track


    glBegin(GL_QUADS);

    glColor3ub(102 ,102 ,102 );

    glVertex2f(-1.0f, -0.25f);

    glVertex2f(-1.0f, -0.5f);

    glVertex2f(1.0f, -0.5f);

    glVertex2f(1.0f, -0.25f);


    glEnd();


    //Rail Line -------------------

    glBegin(GL_LINES);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.00f,-0.32f);

    glVertex2f(1.00f,-0.32f);

    glVertex2f(-1.00f,-0.42f);

    glVertex2f(1.00f,-0.42f);

    glVertex2f(-1.00f,-0.4f);

    glVertex2f(1.00f,-0.4f);

    glVertex2f(-1.0f,-0.34f);

    glVertex2f(1.0f,-0.34f);

    glEnd();

    //-------------------------------------------


     //train starts ->

     glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);


     // train buggy most left

     glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87 );

    glVertex2f(-1.0f,-0.28f);

    glVertex2f(-1.0f,-0.4f);

    glVertex2f(-0.9f,-0.4f);

    glVertex2f(-0.9f,-0.28f);

    glEnd();


     // train buggy 2

     glBegin(GL_QUADS);

    glColor3ub(34 ,139 ,34 );

    glVertex2f(-0.9f,-0.28f);

    glVertex2f(-0.9f,-0.4f);

    glVertex2f(-0.76f,-0.4f);

    glVertex2f(-0.76f,-0.28f);

    glEnd();


     // train buggy 3

       glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87);

    glVertex2f(-0.76f,-0.28f);

    glVertex2f(-0.76f,-0.4f);

    glVertex2f(-0.62f,-0.4f);

    glVertex2f(-0.62f,-0.28f);

    glEnd();

      // train buggy 4

       glBegin(GL_QUADS);

    glColor3ub(34 ,139 ,34);

    glVertex2f(-0.62f,-0.28f);

    glVertex2f(-0.62f,-0.4f);

    glVertex2f(-0.46f,-0.4f);

    glVertex2f(-0.46f,-0.28f);

    glEnd();

     // train engine top

       glBegin(GL_QUADS);

    glColor3ub(255, 0, 0 );

    glVertex2f(-0.46f,-0.28f);

    glVertex2f(-0.46f,-0.3f);

    glVertex2f(-0.36f,-0.3f);

    glVertex2f(-0.38f,-0.28f);

    glEnd();

      // train engine bottom

       glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87 );

    glVertex2f(-0.46f,-0.3f);

    glVertex2f(-0.46f,-0.4f);

    glVertex2f(-0.36f,-0.4f);

    glVertex2f(-0.36f,-0.3f);

    glEnd();

    // train line

    glBegin(GL_POLYGON);

    glColor3ub(245,245,245);

    glVertex2f(-0.46f,-0.34f);

    glVertex2f(-0.46f,-0.36f);

    glVertex2f(-1.0f,-0.36f);

    glVertex2f(-1.0f,-0.34f);

    glEnd();

    //train window left to right

      glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.98f,-0.3f);

    glVertex2f(-0.98f,-0.38f);

    glVertex2f(-0.96f,-0.38f);

    glVertex2f(-0.96f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.94f,-0.3f);

    glVertex2f(-0.94f,-0.35f);

    glVertex2f(-0.92f,-0.35f);

    glVertex2f(-0.92f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.88f,-0.3f);

    glVertex2f(-0.88f,-0.35f);

    glVertex2f(-0.86f,-0.35f);

    glVertex2f(-0.86f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.84f,-0.3f);

    glVertex2f(-0.84f,-0.38f);

    glVertex2f(-0.82f,-0.38f);

    glVertex2f(-0.82f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.80f,-0.3f);

    glVertex2f(-0.80f,-0.35f);

    glVertex2f(-0.78f,-0.35f);

    glVertex2f(-0.78f,-0.3f);

    glEnd();


      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.74f,-0.3f);

    glVertex2f(-0.74f,-0.35f);

    glVertex2f(-0.72f,-0.35f);

    glVertex2f(-0.72f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.70f,-0.3f);

    glVertex2f(-0.70f,-0.38f);

    glVertex2f(-0.68f,-0.38f);

    glVertex2f(-0.68f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.66f,-0.3f);

    glVertex2f(-0.66f,-0.35f);

    glVertex2f(-0.64f,-0.35f);

    glVertex2f(-0.64f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.60f,-0.3f);

    glVertex2f(-0.60f,-0.35f);

    glVertex2f(-0.58f,-0.35f);

    glVertex2f(-0.58f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.56f,-0.3f);

    glVertex2f(-0.56f,-0.38f);

    glVertex2f(-0.54f,-0.38f);

    glVertex2f(-0.54f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.52f,-0.3f);

    glVertex2f(-0.52f,-0.35f);

    glVertex2f(-0.50f,-0.35f);

    glVertex2f(-0.50f,-0.3f);

    glEnd();


    //engine gate


     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.42f,-0.3f);

    glVertex2f(-0.42f,-0.38f);

    glVertex2f(-0.40f,-0.38f);

    glVertex2f(-0.40f,-0.35f);

    glEnd();


     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.41f,-0.3f);

    glVertex2f(-0.39f,-0.35f);

    glVertex2f(-0.36f,-0.35f);

    glVertex2f(-0.36f,-0.3f);

    glEnd();

    //train wheels

    circle(0.016,-0.4,-0.4,64,46,5);

    circle(0.01,-0.4,-0.4,139,69,19);

    circle(0.016,-0.44,-0.4,64,46,5);

    circle(0.01,-0.44,-0.4,139,69,19);


    circle(0.016,-0.52,-0.4,64,46,5);

    circle(0.01,-0.52,-0.4,139,69,19);

    circle(0.016,-0.56,-0.4,64,46,5);

    circle(0.01,-0.56,-0.4,139,69,19);

    circle(0.016,-0.65,-0.4,64,46,5);

    circle(0.01,-0.65,-0.4,139,69,19);

    circle(0.016,-0.69,-0.4,64,46,5);

    circle(0.01,-0.69,-0.4,139,69,19);

    circle(0.016,-0.81,-0.4,64,46,5);

    circle(0.01,-0.81,-0.4,139,69,19);

    circle(0.016,-0.85,-0.4,64,46,5);

    circle(0.01,-0.85,-0.4,139,69,19);

    circle(0.016,-0.92,-0.4,64,46,5);

    circle(0.01,-0.92,-0.4,139,69,19);

    circle(0.016,-0.96,-0.4,64,46,5);

    circle(0.01,-0.96,-0.4,139,69,19);


    glPopMatrix();



    //train ends-------------------



    //Train Bridge sides railing

    glBegin(GL_LINES);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.0f,-0.5f);

    glVertex2f(1.0f,-0.5f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(1.0f,-0.1f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.00f,-0.1f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.6f,-0.5f);

    glVertex2f(-0.9f,-0.1f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.3f,-0.1f);

    glVertex2f(-0.2f,-0.1f);

    glVertex2f(-0.6f,-0.5f);

    glVertex2f(-0.3f,-0.1f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.2f,-0.5f);

    glVertex2f(-0.2f,-0.1f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.6f,-0.1f);

    glVertex2f(0.2f,-0.5f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.9f,-0.5f);

    glVertex2f(1.0f,-0.5f);

    glVertex2f(0.6f,-0.1f);

    glEnd();

    //------------------------------------------


    //Train Bridge behind Railing


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.79f,-0.1f);

    glVertex2f(-0.66f,-0.25f);

    glVertex2f(-0.63f,-0.25f);

    glVertex2f(-0.74f,-0.1f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.66f,-0.25f);

    glVertex2f(-0.63f,-0.25f);

    glVertex2f(-0.49f,-0.1f);

    glVertex2f(-0.53f,-0.1f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.08f,-0.1f);

    glVertex2f(0.09f,-0.25f);

    glVertex2f(0.13f,-0.25f);

    glVertex2f(-0.02f,-0.1f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(0.3f,-0.1f);

    glVertex2f(0.24f,-0.1f);

    glVertex2f(0.09f,-0.25f);

    glVertex2f(0.13f,-0.25f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(0.72f,-0.1f);

    glVertex2f(0.89f,-0.25f);

    glVertex2f(0.93f,-0.25f);

    glVertex2f(0.78f,-0.1f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(1.0f,-0.14f);

    glVertex2f(0.89f,-0.25f);

    glVertex2f(0.93f,-0.25f);

    glVertex2f(1.0f,-0.19f);

    glEnd();



    //Boat 1

    glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);

    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(-0.94f,-0.75f);

    glVertex2f(-0.88f,-0.79f);

    glVertex2f(-0.79f,-0.79f);

    glVertex2f(-0.72f,-0.75f);

    glColor3ub(139, 169 ,190);

    glVertex2f(-0.90f,-0.75f);

    glVertex2f(-0.75f,-0.75f);

    glVertex2f(-0.78f,-0.72f);

    glVertex2f(-0.88f,-0.72f);


     glEnd();


     glPopMatrix();


    //pillar 1

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130 );

    glVertex2f(-1.0f,-0.5f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.8f,-0.6f);

    glVertex2f(-0.9f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(-0.9f,-0.6f);

    glVertex2f(-0.8f,-0.6f);

    glVertex2f(-0.82f,-0.8f);

    glVertex2f(-0.88f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(-0.94f,-0.8f);

    glVertex2f(-0.76f,-0.8f);

    glVertex2f(-0.78f,-0.85f);

    glVertex2f(-0.92f,-0.85f);

    glEnd();

    //----------------------------------


    //pillar 2

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130);

    glVertex2f(-0.2f,-0.5f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.0f,-0.6f);

    glVertex2f(-0.1f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(-0.1f,-0.6f);

    glVertex2f(0.0f,-0.6f);

    glVertex2f(-0.02f,-0.8f);

    glVertex2f(-0.08f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(-0.14f,-0.8f);

    glVertex2f(0.04f,-0.8f);

    glVertex2f(0.02f,-0.85f);

    glVertex2f(-0.12f,-0.85f);

    glEnd();

    //-------------------------------------------


    //pillar 3

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130);

    glVertex2f(0.6f,-0.5f);

    glVertex2f(0.9f,-0.5f);

    glVertex2f(0.8f,-0.6f);

    glVertex2f(0.7f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(0.7f,-0.6f);

    glVertex2f(0.8f,-0.6f);

    glVertex2f(0.78f,-0.8f);

    glVertex2f(0.72f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(0.66f,-0.8f);

    glVertex2f(0.84f,-0.8f);

    glVertex2f(0.82f,-0.85f);

    glVertex2f(0.68f,-0.85f);

    glEnd();


    //Train Track side box


    glBegin(GL_POLYGON);

    glColor3ub(245,245,245);

    glVertex2f(-1.0f,-0.48f);

    glVertex2f(1.0f,-0.48f);

    glVertex2f(1.0f,-0.52f);

    glVertex2f(-1.0f,-0.52f);

    glEnd();


    //bridge finish


    //Boat 2


    glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);


    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(-1.0f,-0.99f);

    glVertex2f(-1.0f,-0.97f);

    glVertex2f(-0.86f,-0.96f);

    glVertex2f(-0.88f,-0.99f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(205,133,63);

    glVertex2f(-1.0f,-0.97f);

    glVertex2f(-0.92f,-0.97f);

    glVertex2f(-0.92f,-0.92f);

    glEnd();


    glBegin(GL_LINES);

    glColor3ub(255,255,255);

    glVertex2f(-0.92f,-0.95f);

    glVertex2f(-0.9f,-0.95f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(205,133,63);

    glVertex2f(-0.91f,-0.97f);

    glVertex2f(-0.88f,-0.96f);

    glVertex2f(-0.91f,-0.92f);

    glEnd();


    glPopMatrix();

    //-----------------------------------------------


    //Boat 3


    glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);


    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(-0.4f,-0.97f);

    glVertex2f(-0.36f,-0.99f);

    glVertex2f(-0.24f,-0.99f);

    glVertex2f(-0.2f,-0.97f);


    glColor3ub(240,230,140);

    glVertex2f(-0.34f,-0.95f);

    glVertex2f(-0.37f,-0.97f);

    glVertex2f(-0.24f,-0.97f);

    glVertex2f(-0.26f,-0.95f);

    glEnd();


    glPopMatrix();

    //-------------------------------------------------


    //boat 4

    glPushMatrix();

	glTranslatef(position1,0.0f,0.0f);

    glBegin(GL_QUADS);

    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(1.00f,-0.95f);

    glVertex2f(0.86f,-0.95f);

    glVertex2f(0.82f,-0.94f);

    glVertex2f(1.00f,-0.94f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(101,13,0);

    glVertex2f(0.80f,-0.92f);

    glVertex2f(0.82f,-0.94f);

    glVertex2f(1.00f,-0.94f);

    glVertex2f(1.00f,-0.93f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,250,154);

    glVertex2f(0.86f,-0.93f);

    glVertex2f(0.94f,-0.88f);

    glVertex2f(0.94f,-0.93f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,255,127);

    glVertex2f(0.96f,-0.93f);

    glVertex2f(0.96f,-0.88f);

    glVertex2f(0.98f,-0.93f);

    glEnd();


    glBegin(GL_LINES);

    glColor3ub(190,190,190);

    glVertex2f(0.94f,-0.91f);

    glVertex2f(0.96f,-0.91f);


    glEnd();


    glPopMatrix();

    //-----------------------------------------

	glutSwapBuffers();

}









































void display1()

{

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);


	//sky color

    glBegin(GL_QUADS);

    glColor3ub(0 ,0 ,0);

    glVertex2f(-1.0f, 1.0f);

    glVertex2f(-1.0f, 0.3f);

    glVertex2f(1.0f, 0.3f);

    glVertex2f(1.0f, 1.0f);

    glEnd();

    //--------------------------------------------------



    circle(0.002,-0.8f,0.7f,255,255,153);
    circle(0.0013,-0.7f,0.6f,255,255,153);
    circle(0.0015,-0.65f,0.85f,255,255,153);
    circle(0.0019,0.76f,0.67f,255,255,153);
    circle(0.002,-0.3f,0.9f,255,255,153);
    circle(0.0014,-0.12,0.55,255,255,153);
    circle(0.0013,0.2,0.7,255,255,153);
    circle(0.002,0.12,0.1,255,255,153);
    circle(0.0013,-0.0,0.45,255,255,153);
    circle(0.002,0.27,0.9,255,255,153);
    circle(0.0013,0.45,0.56,255,255,153);
    circle(0.0017,0.55,0.97,255,255,153);
    circle(0.0015,0.8,0.7,255,255,153);
    circle(0.0014,0.95,0.7,255,255,153);
    circle(0.002,-0.2,0.4,255,255,153);
    circle(0.0013,-0.27,0.56,255,255,153);
    circle(0.002,-0.93,0.4,255,255,153);
    circle(0.002,-0.55,0.47,255,255,153);
    circle(0.002,-0.6,0.54,255,255,153);
    circle(0.002,-0.45,0.66,255,255,153);
    circle(0.002,-0.21,0.9,255,255,153);
    circle(0.002,-0.1,0.94,255,255,153);
    circle(0.002,-0.35,0.34,255,255,153);
    circle(0.1,-0.8f,0.7f,255,255,153);
    circle(0.1,-0.85f,0.7f,0,0,0);



    //road full

    glBegin(GL_QUADS);

    glColor3ub(102 ,102 ,102);

    glVertex2f(-1.0f, 0.32f);

    glVertex2f(-1.0f, -0.1f);

    glVertex2f(1.0f, -0.1f);

    glVertex2f(1.0f, 0.32f);

    glEnd();

    //-----------------------------------------------------


    //Road Front 1

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f, -0.079f);

    glVertex2f(1.0f, -0.079f);

    glVertex2f(1.0f, -0.085f);

    glVertex2f(-1.0f, -0.085f);

    glEnd();

    //-------------------------------------------


    //Front 2

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f,0.18f);

    glVertex2f(-1.0f,0.195f);

    glVertex2f(1.0f,0.195f);

    glVertex2f(1.0f,0.18f);

    glEnd();

    //-------------------------------------------


    //Front Road Markers 1st lane

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.09f);

    glVertex2f(1.0f,0.07f);

    glVertex2f(0.8f,0.07f);

    glVertex2f(0.83f,0.09f);

    glVertex2f(0.73f,0.09f);

    glVertex2f(0.7f,0.07f);

    glVertex2f(0.5f,0.07f);

    glVertex2f(0.53f,0.09f);

    glVertex2f(0.43f,0.09f);

    glVertex2f(0.4f,0.07f);

    glVertex2f(0.2f,0.07f);

    glVertex2f(0.23f,0.09f);

    glVertex2f(0.1f,0.09f);

    glVertex2f(0.07f,0.07f);

    glVertex2f(-0.13f,0.07f);

    glVertex2f(-0.1f,0.09f);

    glVertex2f(-0.2f,0.09f);

    glVertex2f(-0.23f,0.07f);

    glVertex2f(-0.43f,0.07f);

    glVertex2f(-0.4f,0.09f);

    glVertex2f(-0.5f,0.09f);

    glVertex2f(-0.53f,0.07f);

    glVertex2f(-0.73f,0.07f);

    glVertex2f(-0.7f,0.09f);

    glVertex2f(-0.8f,0.09f);

    glVertex2f(-0.83f,0.07f);

    glVertex2f(-1.0f,0.07f);

    glVertex2f(-1.0f,0.09f);

    glEnd();

    //-----------------------------------------


    //Road Front Side Back 1

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.20f);

    glVertex2f(1.0f,0.21f);

    glVertex2f(-1.0f,0.21f);

    glVertex2f(-1.0f,0.20f);

    glEnd();

    //-------------------------------------------


    //Road Markers 2nd lane

    glBegin(GL_QUADS);

    glColor3ub(255,250 ,250);

    glVertex2f(1.0f,0.255f);

    glVertex2f(1.0f,0.26f);

    glVertex2f(0.811f,0.26f);

    glVertex2f(0.8f,0.255f);

    glVertex2f(0.7f,0.255f);

    glVertex2f(0.711f,0.26f);

    glVertex2f(0.511f,0.26f);

    glVertex2f(0.5f,0.255f);

    glVertex2f(0.4f,0.255f);

    glVertex2f(0.411f,0.26f);

    glVertex2f(0.211f,0.26f);

    glVertex2f(0.2f,0.255f);

    glVertex2f(0.091f,0.255f);

    glVertex2f(0.1f,0.26f);

    glVertex2f(-0.1f,0.26f);

    glVertex2f(-0.111f,0.255f);

    glVertex2f(-0.211f,0.255f);

    glVertex2f(-0.2f,0.26f);

    glVertex2f(-0.4f,0.26f);

    glVertex2f(-0.411f,0.255f);

    glVertex2f(-0.511f,0.255f);

    glVertex2f(-0.5f,0.26f);

    glVertex2f(-0.7f,0.26f);

    glVertex2f(-0.711f,0.255f);

    glVertex2f(-0.811f,0.255f);

    glVertex2f(-0.8f,0.26f);

    glVertex2f(-1.0f,0.26f);

    glVertex2f(-1.0f,0.255f);

    glEnd();

    //--------------------------------------------------


    //Behind Back 2

    glBegin(GL_LINES);

    glColor3ub(255,250 ,250);

    glVertex2f(-1.0f,0.31f);

    glVertex2f(1.0f,0.31f);

    glEnd();

    //------------------------------------------


    //road and train bridge connection

    glBegin(GL_POLYGON);

    glColor3f(1.0f,1.0f,1.0f);


    glVertex2f(-1.0f,-0.09f);

    glVertex2f(1.0f,-0.09f);

    glVertex2f(1.0f,-0.11f);

    glVertex2f(-1.0f,-0.11f);

    glEnd();


    //Bus Starts


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(255,0,0);

    glVertex2f(0.5f,0.0f);

    glVertex2f(0.9f,0.0f);

    glVertex2f(0.9f,-0.06f);

    glVertex2f(0.5f,-0.06f);

    glEnd();

    glPopMatrix();



    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(255,0,0);

    glVertex2f(0.5f,0.0f);

    glVertex2f(0.9f,0.0f);

    glVertex2f(0.9f,0.08f);

    glVertex2f(0.54f,0.08f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_LINES);

    glColor3ub(0,100,0);

    glVertex2f(0.58f,0.02f);

    glVertex2f(0.85f,0.02f);

    glEnd();

    glPopMatrix();


     glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_LINES);

    glColor3ub(0,100,0);

    glVertex2f(0.58f,0.04f);

    glVertex2f(0.85f,0.04f);

    glEnd();


    glPopMatrix();


    //wheel 1

     glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    circle(0.02f,0.6f,-0.06f,0,0,0);

    circle(0.01f,0.6f,-0.06f,255,255,255);

    //wheel 2


    circle(0.02f,0.8f,-0.06f,0,0,0);

    circle(0.01f,0.8f,-0.06f,255,255,255);

     glPopMatrix();

    //bus window

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.54f,-0.02f);

    glVertex2f(0.55f,0.06f);

    glVertex2f(0.58f,0.06f);

    glVertex2f(0.58f,-0.02f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.6f,0.0f);

    glVertex2f(0.6f,0.06f);

    glVertex2f(0.66f,0.06f);

    glVertex2f(0.66f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.68f,0.0f);

    glVertex2f(0.68f,0.06f);

    glVertex2f(0.74f,0.06f);

    glVertex2f(0.74f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.76f,0.0f);

    glVertex2f(0.76f,0.06f);

    glVertex2f(0.82f,0.06f);

    glVertex2f(0.82f,0.0f);

    glEnd();

    glPopMatrix();


    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(1,1,1);

    glVertex2f(0.84f,0.0f);

    glVertex2f(0.84f,0.06f);

    glVertex2f(0.87f,0.06f);

    glVertex2f(0.87f,0.0f);

    glEnd();


    glPopMatrix();


    //Light of Bus

    glPushMatrix();

	glTranslatef(position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(255,215,0);

    glVertex2f(0.5f,-0.02f);

    glVertex2f(0.51f,-0.02f);

    glVertex2f(0.51f,-0.03f);

    glVertex2f(0.5f,-0.03f);


    glEnd();


    glPopMatrix();


    //bus ends----------------------------------------------



    //car 2 on bus road


    // car body


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0 );

    glVertex2f(-0.95f,0.19f);

    glVertex2f(-0.96f,0.13f);

    glVertex2f(-0.75f,0.13f);

    glVertex2f(-0.77f,0.17f);

    glEnd();


    glPopMatrix();

     // car body under


     glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0);

    glVertex2f(-0.96f,0.13f);

    glVertex2f(-0.93f,0.12f);

    glVertex2f(-0.76f,0.12f);

    glVertex2f(-0.75f,0.13f);

    glEnd();


    glPopMatrix();

    // car upper

    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(255 ,140, 0 );

    glVertex2f(-0.87f,0.22f);

    glVertex2f(-0.94f,0.18f);

    glVertex2f(-0.78f,0.17f);

    glVertex2f(-0.82f,0.21f);

    glEnd();


    glPopMatrix();



      // car mirror back



      glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.88f,0.22f);

    glVertex2f(-0.92f,0.19f);

    glVertex2f(-0.90f,0.17f);

    glVertex2f(-0.86f,0.19f);

    glEnd();


    glPopMatrix();


      // car mirror front


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.82f,0.215f);

    glVertex2f(-0.83f,0.185f);

    glVertex2f(-0.795f,0.16f);

    glVertex2f(-0.78f,0.175f);

    glEnd();


     glPopMatrix();



      // car mirror middle


      glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

     glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.85f,0.19f);

    glVertex2f(-0.89f,0.17f);

    glVertex2f(-0.805f,0.16f);

    glVertex2f(-0.84f,0.187f);

    glEnd();


    glPopMatrix();



    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);

    circle(-0.02,-0.92,0.12,0,0,0);

    circle(-0.01,-0.92,0.12,255,255,255);


    circle(-0.02,-0.81,0.12,0,0,0);

    circle(-0.01,-0.81,0.12,255,255,255);


    glPopMatrix();


    //car 2 ends------------------------


    // Car on Lane 2 (Car 1)


    glPushMatrix();

	glTranslatef(-position,0.0f,0.0f);


    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.98f,0.29f);

    glVertex2f(-0.88f,0.29f);

    glVertex2f(-0.86f,0.27f);

    glVertex2f(-0.96f,0.27f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.98f,0.29f);

    glVertex2f(-0.88f,0.29f);

    glVertex2f(-0.9f,0.31f);

    glVertex2f(-0.98f,0.31f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,0,102);

    glVertex2f(-0.97f,0.31f);

    glVertex2f(-0.91f,0.31f);

    glVertex2f(-0.93f,0.33f);

    glVertex2f(-0.95f,0.33f);



    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,0,0);

    glVertex2f(-0.965f,0.31f);

    glVertex2f(-0.905f,0.31f);

    glVertex2f(-0.925f,0.33f);

    glVertex2f(-0.945f,0.33f);



    glEnd();




    circle(0.01f,-0.95f,0.27f,0,0,0);

    circle(0.005f,-0.95f,0.27f,255,255,255);

    circle(0.01,-0.9f,0.27f,0,0,0);

    circle(0.005,-0.9f,0.27f,255,255,255);


    glPopMatrix();



    //Car On Lane 2(Car 2)

    glPushMatrix();

	glTranslatef(position2,0.0f,0.0f);

    glBegin(GL_POLYGON);

    glColor3ub(112,12,12);


    glVertex2f(0.78f,0.22f);

    glVertex2f(0.98f,0.22f);

    glVertex2f(0.98f,0.24f);

    glVertex2f(0.84f,0.24f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(112,12,12);

    glVertex2f(0.86f,0.24f);

    glVertex2f(0.89f,0.27f);

    glVertex2f(0.94f,0.27f);

    glVertex2f(0.96f,0.24f);


    glEnd();

    glBegin(GL_POLYGON);

    glColor3ub(25,25,25);

    glVertex2f(0.88f,0.24f);

    glVertex2f(0.9f,0.26f);

    glVertex2f(0.92f,0.26f);

    glVertex2f(0.94f,0.24f);

    glEnd();


    circle(0.01f,0.85f,0.22f,0,0,0);

    circle(0.005f,0.85f,0.22f,255,255,255);

    circle(0.01f,0.95f,0.22f,0,0,0);

    circle(0.005f,0.95f,0.22f,255,255,255);

    glPopMatrix();

    //car 2 ends--------------------------


    //Middle LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.02f,0.199f);
    glVertex2f(-0.02f,0.199f);
    glVertex2f(-0.02f,0.196f);
    glVertex2f(0.02f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.005f,0.197f);
    glVertex2f(-0.005f,0.197f);
    glVertex2f(-0.005f,0.7f);
    glVertex2f(0.005f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.005f,0.679f);
    glVertex2f(0.005f,0.67f);
    glVertex2f(0.07f,0.69f);
    glVertex2f(0.07f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.059f,0.694f);
    glVertex2f(0.059f,0.685f);
    glVertex2f(0.069f,0.685f);
    glVertex2f(0.069f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(-0.005f,0.679f);
    glVertex2f(-0.005f,0.67f);
    glVertex2f(-0.07f,0.65f);
    glVertex2f(-0.07f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.059f,0.65f);
    glVertex2f(-0.059f,0.644f);
    glVertex2f(-0.069f,0.647f);
    glVertex2f(-0.069f,0.657f);

    glEnd();

    //------------------------------------------


    //Right LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.72f,0.199f);
    glVertex2f(0.68f,0.199f);
    glVertex2f(0.68f,0.196f);
    glVertex2f(0.72f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.705f,0.197f);
    glVertex2f(0.695f,0.197f);
    glVertex2f(0.695f,0.7f);
    glVertex2f(0.705f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.705f,0.679f);
    glVertex2f(0.705f,0.67f);
    glVertex2f(0.77f,0.69f);
    glVertex2f(0.77f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.759f,0.694f);
    glVertex2f(0.759f,0.685f);
    glVertex2f(0.769f,0.685f);
    glVertex2f(0.769f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(0.695f,0.679f);
    glVertex2f(0.695f,0.67f);
    glVertex2f(0.63f,0.65f);
    glVertex2f(0.63f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(0.629f,0.65f);
    glVertex2f(0.629f,0.644f);
    glVertex2f(0.639f,0.647f);
    glVertex2f(0.639f,0.657f);

    glEnd();

    //------------------------------------------


    //Left LampPost

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(-0.72f,0.199f);
    glVertex2f(-0.68f,0.199f);
    glVertex2f(-0.68f,0.196f);
    glVertex2f(-0.72f,0.196f);

    glEnd();

    //Root
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(-0.705f,0.197f);
    glVertex2f(-0.695f,0.197f);
    glVertex2f(-0.695f,0.7f);
    glVertex2f(-0.705f,0.7f);

    glEnd();

    //Stand R
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(-0.695f,0.679f);
    glVertex2f(-0.695f,0.67f);
    glVertex2f(-0.63f,0.69f);
    glVertex2f(-0.63f,0.695f);

    glEnd();

    //Stand R Light
    glBegin(GL_POLYGON);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.629f,0.694f);
    glVertex2f(-0.629f,0.685f);
    glVertex2f(-0.639f,0.685f);
    glVertex2f(-0.639f,0.694f);

    glEnd();

    //Stand L
    glBegin(GL_POLYGON);
    glColor3ub(190,190 ,190);

    glVertex2f(-0.705f,0.679f);
    glVertex2f(-0.705f,0.67f);
    glVertex2f(-0.77f,0.65f);
    glVertex2f(-0.77f,0.655f);

    glEnd();

    //Stand L Light
    glBegin(GL_QUADS);
    glColor3ub(255,255 ,0);

    glVertex2f(-0.779f,0.65f);
    glVertex2f(-0.779f,0.644f);
    glVertex2f(-0.769f,0.647f);
    glVertex2f(-0.769f,0.657f);

    glEnd();

    //------------------------------------------



    //-------------------------------------------------------

    // water color

    glBegin(GL_POLYGON);

    glColor3ub(9,6,43);

    glVertex2f(-1.0f, -1.0f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(1.0f,-0.1f);


    glVertex2f(1.0f,-0.1f);

    glVertex2f(1.0f,-1.0f);

    glVertex2f(1.0f,-1.0f);

    glVertex2f(-1.0f, -1.0f);

    glEnd();

    //----------------------------------------------------



    //train Track


    glBegin(GL_QUADS);

    glColor3ub(102 ,102 ,102 );

    glVertex2f(-1.0f, -0.25f);

    glVertex2f(-1.0f, -0.5f);

    glVertex2f(1.0f, -0.5f);

    glVertex2f(1.0f, -0.25f);


    glEnd();


    //Rail Line -------------------

    glBegin(GL_LINES);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.00f,-0.32f);

    glVertex2f(1.00f,-0.32f);

    glVertex2f(-1.00f,-0.42f);

    glVertex2f(1.00f,-0.42f);

    glVertex2f(-1.00f,-0.4f);

    glVertex2f(1.00f,-0.4f);

    glVertex2f(-1.0f,-0.34f);

    glVertex2f(1.0f,-0.34f);

    glEnd();

    //-------------------------------------------


     //train starts ->

     glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);


     // train buggy most left

     glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87 );

    glVertex2f(-1.0f,-0.28f);

    glVertex2f(-1.0f,-0.4f);

    glVertex2f(-0.9f,-0.4f);

    glVertex2f(-0.9f,-0.28f);

    glEnd();


     // train buggy 2

     glBegin(GL_QUADS);

    glColor3ub(34 ,139 ,34 );

    glVertex2f(-0.9f,-0.28f);

    glVertex2f(-0.9f,-0.4f);

    glVertex2f(-0.76f,-0.4f);

    glVertex2f(-0.76f,-0.28f);

    glEnd();


     // train buggy 3

       glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87);

    glVertex2f(-0.76f,-0.28f);

    glVertex2f(-0.76f,-0.4f);

    glVertex2f(-0.62f,-0.4f);

    glVertex2f(-0.62f,-0.28f);

    glEnd();

      // train buggy 4

       glBegin(GL_QUADS);

    glColor3ub(34 ,139 ,34);

    glVertex2f(-0.62f,-0.28f);

    glVertex2f(-0.62f,-0.4f);

    glVertex2f(-0.46f,-0.4f);

    glVertex2f(-0.46f,-0.28f);

    glEnd();

     // train engine top

       glBegin(GL_QUADS);

    glColor3ub(255, 0, 0 );

    glVertex2f(-0.46f,-0.28f);

    glVertex2f(-0.46f,-0.3f);

    glVertex2f(-0.36f,-0.3f);

    glVertex2f(-0.38f,-0.28f);

    glEnd();

      // train engine bottom

       glBegin(GL_QUADS);

    glColor3ub(46 ,139 ,87 );

    glVertex2f(-0.46f,-0.3f);

    glVertex2f(-0.46f,-0.4f);

    glVertex2f(-0.36f,-0.4f);

    glVertex2f(-0.36f,-0.3f);

    glEnd();

    // train line

    glBegin(GL_POLYGON);

    glColor3ub(245,245,245);

    glVertex2f(-0.46f,-0.34f);

    glVertex2f(-0.46f,-0.36f);

    glVertex2f(-1.0f,-0.36f);

    glVertex2f(-1.0f,-0.34f);

    glEnd();

    //train window left to right

      glBegin(GL_QUADS);

    glColor3ub(0,0,0 );

    glVertex2f(-0.98f,-0.3f);

    glVertex2f(-0.98f,-0.38f);

    glVertex2f(-0.96f,-0.38f);

    glVertex2f(-0.96f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.94f,-0.3f);

    glVertex2f(-0.94f,-0.35f);

    glVertex2f(-0.92f,-0.35f);

    glVertex2f(-0.92f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.88f,-0.3f);

    glVertex2f(-0.88f,-0.35f);

    glVertex2f(-0.86f,-0.35f);

    glVertex2f(-0.86f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.84f,-0.3f);

    glVertex2f(-0.84f,-0.38f);

    glVertex2f(-0.82f,-0.38f);

    glVertex2f(-0.82f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.80f,-0.3f);

    glVertex2f(-0.80f,-0.35f);

    glVertex2f(-0.78f,-0.35f);

    glVertex2f(-0.78f,-0.3f);

    glEnd();


      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.74f,-0.3f);

    glVertex2f(-0.74f,-0.35f);

    glVertex2f(-0.72f,-0.35f);

    glVertex2f(-0.72f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.70f,-0.3f);

    glVertex2f(-0.70f,-0.38f);

    glVertex2f(-0.68f,-0.38f);

    glVertex2f(-0.68f,-0.3f);

    glEnd();

      glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.66f,-0.3f);

    glVertex2f(-0.66f,-0.35f);

    glVertex2f(-0.64f,-0.35f);

    glVertex2f(-0.64f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.60f,-0.3f);

    glVertex2f(-0.60f,-0.35f);

    glVertex2f(-0.58f,-0.35f);

    glVertex2f(-0.58f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.56f,-0.3f);

    glVertex2f(-0.56f,-0.38f);

    glVertex2f(-0.54f,-0.38f);

    glVertex2f(-0.54f,-0.3f);

    glEnd();

     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.52f,-0.3f);

    glVertex2f(-0.52f,-0.35f);

    glVertex2f(-0.50f,-0.35f);

    glVertex2f(-0.50f,-0.3f);

    glEnd();


    //engine gate


     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.42f,-0.3f);

    glVertex2f(-0.42f,-0.38f);

    glVertex2f(-0.40f,-0.38f);

    glVertex2f(-0.40f,-0.35f);

    glEnd();


     glBegin(GL_QUADS);

    glColor3ub(0,0,0);

    glVertex2f(-0.41f,-0.3f);

    glVertex2f(-0.39f,-0.35f);

    glVertex2f(-0.36f,-0.35f);

    glVertex2f(-0.36f,-0.3f);

    glEnd();

    //train wheels

    circle(0.016,-0.4,-0.4,64,46,5);

    circle(0.01,-0.4,-0.4,139,69,19);

    circle(0.016,-0.44,-0.4,64,46,5);

    circle(0.01,-0.44,-0.4,139,69,19);


    circle(0.016,-0.52,-0.4,64,46,5);

    circle(0.01,-0.52,-0.4,139,69,19);

    circle(0.016,-0.56,-0.4,64,46,5);

    circle(0.01,-0.56,-0.4,139,69,19);

    circle(0.016,-0.65,-0.4,64,46,5);

    circle(0.01,-0.65,-0.4,139,69,19);

    circle(0.016,-0.69,-0.4,64,46,5);

    circle(0.01,-0.69,-0.4,139,69,19);

    circle(0.016,-0.81,-0.4,64,46,5);

    circle(0.01,-0.81,-0.4,139,69,19);

    circle(0.016,-0.85,-0.4,64,46,5);

    circle(0.01,-0.85,-0.4,139,69,19);

    circle(0.016,-0.92,-0.4,64,46,5);

    circle(0.01,-0.92,-0.4,139,69,19);

    circle(0.016,-0.96,-0.4,64,46,5);

    circle(0.01,-0.96,-0.4,139,69,19);


    glPopMatrix();



    //train ends-------------------



    //Train Bridge sides railing

    glBegin(GL_LINES);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.0f,-0.5f);

    glVertex2f(1.0f,-0.5f);

    glVertex2f(-1.0f,-0.1f);

    glVertex2f(1.0f,-0.1f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(240 ,248 ,255);

    glVertex2f(-1.00f,-0.1f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.6f,-0.5f);

    glVertex2f(-0.9f,-0.1f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.3f,-0.1f);

    glVertex2f(-0.2f,-0.1f);

    glVertex2f(-0.6f,-0.5f);

    glVertex2f(-0.3f,-0.1f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.2f,-0.5f);

    glVertex2f(-0.2f,-0.1f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.6f,-0.1f);

    glVertex2f(0.2f,-0.5f);

    glVertex2f(0.5f,-0.1f);

    glVertex2f(0.9f,-0.5f);

    glVertex2f(1.0f,-0.5f);

    glVertex2f(0.6f,-0.1f);

    glEnd();

    //------------------------------------------


    //Train Bridge behind Railing


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.79f,-0.1f);

    glVertex2f(-0.66f,-0.25f);

    glVertex2f(-0.63f,-0.25f);

    glVertex2f(-0.74f,-0.1f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.66f,-0.25f);

    glVertex2f(-0.63f,-0.25f);

    glVertex2f(-0.49f,-0.1f);

    glVertex2f(-0.53f,-0.1f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(-0.08f,-0.1f);

    glVertex2f(0.09f,-0.25f);

    glVertex2f(0.13f,-0.25f);

    glVertex2f(-0.02f,-0.1f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(0.3f,-0.1f);

    glVertex2f(0.24f,-0.1f);

    glVertex2f(0.09f,-0.25f);

    glVertex2f(0.13f,-0.25f);


    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(0.72f,-0.1f);

    glVertex2f(0.89f,-0.25f);

    glVertex2f(0.93f,-0.25f);

    glVertex2f(0.78f,-0.1f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3f(1,1,1);

    glVertex2f(1.0f,-0.14f);

    glVertex2f(0.89f,-0.25f);

    glVertex2f(0.93f,-0.25f);

    glVertex2f(1.0f,-0.19f);

    glEnd();

    glPushMatrix();

    //Boat 1






    //pillar 1

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130 );

    glVertex2f(-1.0f,-0.5f);

    glVertex2f(-0.7f,-0.5f);

    glVertex2f(-0.8f,-0.6f);

    glVertex2f(-0.9f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(-0.9f,-0.6f);

    glVertex2f(-0.8f,-0.6f);

    glVertex2f(-0.82f,-0.8f);

    glVertex2f(-0.88f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(-0.94f,-0.8f);

    glVertex2f(-0.76f,-0.8f);

    glVertex2f(-0.78f,-0.85f);

    glVertex2f(-0.92f,-0.85f);

    glEnd();

    //----------------------------------


    //pillar 2

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130);

    glVertex2f(-0.2f,-0.5f);

    glVertex2f(0.1f,-0.5f);

    glVertex2f(0.0f,-0.6f);

    glVertex2f(-0.1f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(-0.1f,-0.6f);

    glVertex2f(0.0f,-0.6f);

    glVertex2f(-0.02f,-0.8f);

    glVertex2f(-0.08f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(-0.14f,-0.8f);

    glVertex2f(0.04f,-0.8f);

    glVertex2f(0.02f,-0.85f);

    glVertex2f(-0.12f,-0.85f);

    glEnd();

    //-------------------------------------------


    //pillar 3

    glBegin(GL_QUADS);

    glColor3ub(130 ,130 ,130);

    glVertex2f(0.6f,-0.5f);

    glVertex2f(0.9f,-0.5f);

    glVertex2f(0.8f,-0.6f);

    glVertex2f(0.7f,-0.6f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(190,190,190);

    glVertex2f(0.7f,-0.6f);

    glVertex2f(0.8f,-0.6f);

    glVertex2f(0.78f,-0.8f);

    glVertex2f(0.72f,-0.8f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(105,105,105);

    glVertex2f(0.66f,-0.8f);

    glVertex2f(0.84f,-0.8f);

    glVertex2f(0.82f,-0.85f);

    glVertex2f(0.68f,-0.85f);

    glEnd();


    //Train Track side box


    glBegin(GL_POLYGON);

    glColor3ub(245,245,245);

    glVertex2f(-1.0f,-0.48f);

    glVertex2f(1.0f,-0.48f);

    glVertex2f(1.0f,-0.52f);

    glVertex2f(-1.0f,-0.52f);

    glEnd();


    //bridge finish



    //-----------------------------------------------


    //Boat 3


    glPushMatrix();

	glTranslatef(-position1,0.0f,0.0f);


    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(-0.4f,-0.97f);

    glVertex2f(-0.36f,-0.99f);

    glVertex2f(-0.24f,-0.99f);

    glVertex2f(-0.2f,-0.97f);


    glColor3ub(240,230,140);

    glVertex2f(-0.34f,-0.95f);

    glVertex2f(-0.37f,-0.97f);

    glVertex2f(-0.24f,-0.97f);

    glVertex2f(-0.26f,-0.95f);

    glEnd();


    glPopMatrix();

    //-------------------------------------------------


    //boat 4

    glPushMatrix();

	glTranslatef(position1,0.0f,0.0f);

    glBegin(GL_QUADS);

    glBegin(GL_QUADS);

    glColor3ub(25,25,25);

    glVertex2f(1.00f,-0.95f);

    glVertex2f(0.86f,-0.95f);

    glVertex2f(0.82f,-0.94f);

    glVertex2f(1.00f,-0.94f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3ub(101,13,0);

    glVertex2f(0.80f,-0.92f);

    glVertex2f(0.82f,-0.94f);

    glVertex2f(1.00f,-0.94f);

    glVertex2f(1.00f,-0.93f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,250,154);

    glVertex2f(0.86f,-0.93f);

    glVertex2f(0.94f,-0.88f);

    glVertex2f(0.94f,-0.93f);

    glEnd();


    glBegin(GL_POLYGON);

    glColor3ub(0,255,127);

    glVertex2f(0.96f,-0.93f);

    glVertex2f(0.96f,-0.88f);

    glVertex2f(0.98f,-0.93f);

    glEnd();


    glBegin(GL_LINES);

    glColor3ub(190,190,190);

    glVertex2f(0.94f,-0.91f);

    glVertex2f(0.96f,-0.91f);


    glEnd();


    glPopMatrix();

    //-----------------------------------------





	glutSwapBuffers();

}



void Key(int key, int x, int y)
    {
    switch(key)
    {
        case GLUT_KEY_UP:
            glutDisplayFunc(display);
            break;
        case GLUT_KEY_DOWN:
            glutDisplayFunc(display1);
            break;

    }

    glutPostRedisplay();
}



int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutCreateWindow("Architecture Marvels- Padma Bridge in OPENGL Glory");

	glutInitWindowSize(720, 720);
    glutSpecialFunc(Key);
	glutDisplayFunc(display);

	glutTimerFunc(1000/60, update, 0);
	glutTimerFunc(1000/80, update1, 0);
	glutTimerFunc(1000/30, update2, 0);


    glutMainLoop();

	return 0;

}




