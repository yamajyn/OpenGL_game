#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <time.h>
#include "myShape.h"


#define KEY_ESC 27
int xBegin, yBegin;
int mButton;
float distance, elevation, azimuth;
float rot=0.;
float x = 0,y=-25,z=35;
float light[] = {1.0,1.0,-1.0,0.0};

int i;
int j;

float acceleration =0;
float v = 0;
float elapsedTime =0;

float shininess = 128.;

void scene(void){
	//color
	//initial
	float ambient[]  = { 0.6, 0.6, 0.6, 1.0 };//ŠÂ‹«Œõ
	float diffuse[] = { 0.1, 0.1, 0.1, 1.0 };//ŠgŽUŒõ
	float specular[] = { 0.1, 0.1, 0.1, 1.0 };//‹¾–Ê”½ŽË
	//ground
	float groundDif[] = { 160./255,160./255 , 160./255, 1.0 };
	//line
	float lineDif[] = { 100./255,100./255 , 100./255, 1.0 };
	float lineSpe[] = {0.8, 0.8, 0.8, 1.0};
	float makuraDif[] = { 70./255,30./255 , 0./255, 1.0 };
	//home
	float homeDif[] = { 220./255,220./255 , 250./255, 1.0 };
  //‚«‚¢‚ë
  float homelineDif[] = { 180./255,180./255 , 80./255, 1.0 };
	//overheadLine
	float ovLineDif[] = { 180./255,180./255 , 210./255, 1.0 };
	float stopDif[] = {250./255,250./255 , 250./255, 1.0 };

	glEnable(GL_DEPTH_TEST);
	glEnable( GL_LIGHTING );
	glLightfv( GL_LIGHT0,GL_POSITION,light);


	glMaterialfv( GL_FRONT, GL_SPECULAR, specular );
	glMaterialfv( GL_FRONT, GL_AMBIENT, ambient );
	glMaterialf( GL_FRONT, GL_SHININESS, shininess );
// ground
	   glMaterialfv( GL_FRONT, GL_DIFFUSE, groundDif );
	   glPushMatrix ();
	   glRotatef( -90., 1.0, 0.0, 0.0);
	   glNormal3f(0., 0., 1.);
	   glRecti(-100000,-100000, 100000,100000);
	   glPopMatrix ();


//line

	glPushMatrix();
		glMaterialfv( GL_FRONT, GL_DIFFUSE, lineDif );
		glMaterialfv( GL_FRONT, GL_SPECULAR, lineSpe );
		glTranslatef( 0., 2.5, -10.0 );
		glScalef(100000, 2, 1 );
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef( 0., 2.5, 10.0 );
		glScalef(100000,2, 1 );
		glutSolidCube(1.0);
	glPopMatrix();

	//makuragi
	glMaterialfv( GL_FRONT, GL_SPECULAR, specular );
	glMaterialfv( GL_FRONT, GL_DIFFUSE, makuraDif );
	for(i=0; i<1000; i++){
		glPushMatrix();
			glTranslatef( i*20-5000, 1, 0 );
			glScalef(6, 1, 30 );
			glutSolidCube(1.0);
		glPopMatrix();
	}
	//subline

		glPushMatrix();
			glMaterialfv( GL_FRONT, GL_DIFFUSE, lineDif );
			glMaterialfv( GL_FRONT, GL_SPECULAR, lineSpe );
			glTranslatef( 0., 2.5, -45.0 );
			glScalef(100000, 2, 1 );
			glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
			glTranslatef( 0., 2.5, -25.0 );
			glScalef(100000,2, 1 );
			glutSolidCube(1.0);
		glPopMatrix();

		//makuragi
		glMaterialfv( GL_FRONT, GL_SPECULAR, specular );
		glMaterialfv( GL_FRONT, GL_DIFFUSE, makuraDif );
		for(i=0; i<1000; i++){
			glPushMatrix();
				glTranslatef( i*20-5000, 1, -35 );
				glScalef(6, 1, 30 );
				glutSolidCube(1.0);
			glPopMatrix();
		}

// home
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse );
	glTranslatef( 5000, 7.5, 42.0 );
	glScalef(2000, 15, 50 );
	glutSolidCube(1.0);

glPopMatrix();
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 5000, 55, 42.0 );
  glRotatef( 2, 1.0, 0.0, 0.0);
	glScalef(2000, 1, 50 );
	glutSolidCube(1.0);

glPopMatrix();

glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homelineDif );
	glTranslatef( 5000, 15, 25.0 );
	glScalef(2000, 1, 5 );
	glutSolidCube(1.0);

glPopMatrix();

//home2
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 5000, 7.5, -78.0 );
	glScalef(2000, 15, 50 );
	glutSolidCube(1.0);

glPopMatrix();
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 5000, 55, -78.0 );
  glRotatef( -2, 1.0, 0.0, 0.0);
	glScalef(2000, 1, 50 );
	glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homelineDif );
	glTranslatef( 5000, 15, -60.0 );
	glScalef(2000, 1, 5 );
	glutSolidCube(1.0);

glPopMatrix();

//ovLine
for(i=0; i<10; i++){
	glPushMatrix();
		glMaterialfv( GL_FRONT, GL_DIFFUSE, ovLineDif );
		glTranslatef( i*150+5000.-800, 30, 55.0 );
		glScalef(2, 50, 2);
		glutSolidCube(1.0);
	glPopMatrix();
}
for(i=0; i<10; i++){
	glPushMatrix();
		glMaterialfv( GL_FRONT, GL_DIFFUSE, ovLineDif );
		glTranslatef( i*150+5000.-800, 30, -90.0 );
		glScalef(2, 50, 2 );
		glutSolidCube(1.0);
	glPopMatrix();
}





glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 0., 7.5, 42.0 );
	glScalef(2000, 15, 50 );
	glutSolidCube(1.0);

glPopMatrix();
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 0., 55, 42.0 );
  glRotatef( 2, 1.0, 0.0, 0.0);
	glScalef(2000, 1, 50 );
	glutSolidCube(1.0);

glPopMatrix();

glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homelineDif );
	glTranslatef( 0., 15, 25.0 );
	glScalef(2000, 1, 5 );
	glutSolidCube(1.0);

glPopMatrix();

//home2
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 0., 7.5, -78.0 );
	glScalef(2000, 15, 50 );
	glutSolidCube(1.0);

glPopMatrix();
glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homeDif );
	glTranslatef( 0., 55, -78.0 );
  glRotatef( -2, 1.0, 0.0, 0.0);
	glScalef(2000, 1, 50 );
	glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
	glMaterialfv( GL_FRONT, GL_DIFFUSE, homelineDif );
	glTranslatef( 0., 15, -60.0 );
	glScalef(2000, 1, 5 );
	glutSolidCube(1.0);

glPopMatrix();


  glMaterialfv( GL_FRONT, GL_DIFFUSE, ovLineDif );
//ovLine
for(i=0; i<10; i++){
	glPushMatrix();
		glTranslatef( i*150.-800, 30, 55.0 );
		glScalef(2, 50, 2);
		glutSolidCube(1.0);
	glPopMatrix();
}
for(i=0; i<10; i++){
	glPushMatrix();
		glTranslatef( i*150.-800, 30, -90.0 );
		glScalef(2, 50, 2 );
		glutSolidCube(1.0);
	glPopMatrix();
}


for(i=0; i<100; i++){
	glPushMatrix();

		glTranslatef( i*400.+1000, 40, 25.0 );
		glScalef(2, 80, 2);
		glutSolidCube(1.0);
	glPopMatrix();

  glPushMatrix();
		glTranslatef( i*400.+1000, 75, -20.0 );
		glScalef(2, 1, 92);
		glutSolidCube(1.0);
	glPopMatrix();
  glPushMatrix();
		glTranslatef( i*400.+1000, 61, -20.0 );
		glScalef(2, 1, 92);
		glutSolidCube(1.0);
	glPopMatrix();
 for(j=0;j<4;j++){
    glPushMatrix();
  		glTranslatef( i*400.+1000, 68, -50.0+j*20 );
  		glScalef(1, 15, 1);
  		glutSolidCube(1.0);
  	glPopMatrix();
  }
}
for(i=0; i<100; i++){
	glPushMatrix();
		glTranslatef( i*400.+1000, 40, -65.0 );
		glScalef(2, 80, 2 );
		glutSolidCube(1.0);
	glPopMatrix();
}

//bill

glMaterialfv( GL_FRONT, GL_DIFFUSE, stopDif );
glPushMatrix();
	glTranslatef( 150 ,10, -20.0 );
	glScalef(1, 20, 1 );
	glutSolidCube(1.0);
glPopMatrix();
glPushMatrix();
	glTranslatef( 150 ,15, -20.0 );
	glRotatef(45,1,0,0);
	glScalef(1, 6, 6 );
	glutSolidCube(1.0);
glPopMatrix();


	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glPopMatrix();

}


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix ();
	glTranslatef( 0.0, 0.0, -distance);
	glRotatef( -elevation, 1.0, 0.0, 0.0);
	glRotatef( -azimuth, 0.0, 1.0, 0.0);
	glTranslatef( x, y, z);
	scene();
	glPopMatrix();
	glutSwapBuffers();

}

void idle(void)
{
  float t = (clock() - elapsedTime)/1000.;

  if(v<0){
    v=0;
		acceleration=0;
  }
	x-=v*t + 1./2.*acceleration*t*t;
  v+=acceleration*t;
elapsedTime = clock();
	glutPostRedisplay();
	//•Ï”‚ð•Ï‰»‚³‚¹‚é
}

void initLighting(void){
	float diffuseL [] = {1.0,1.0,1.0,1.0};
	float specularL [] = {0.6,0.6,0.6,0.6};
	float ambientL [] = {0.5,0.5,0.5,1.0};

	glLightfv( GL_LIGHT0,GL_DIFFUSE,diffuseL);
	glLightfv( GL_LIGHT0,GL_SPECULAR,specularL);
	glLightfv( GL_LIGHT0,GL_AMBIENT,ambientL);
	glEnable( GL_LIGHT0);
}

void myMouse(int button, int state, int x, int y)
{
	if ( state == GLUT_DOWN )
	{      	xBegin = x;     yBegin = y;
        	mButton = button;
	}
}
void myKbd( unsigned char key, int x, int y )
{
	if ( key == KEY_ESC ) exit( 0 );
  //1
  if (key == '1'){
    acceleration =-50;
  }else if(key=='2'){
    acceleration =-3;
  }else if(key=='3'){
    acceleration =-2;
  }else if(key=='4'){
    acceleration =-1;
  }else if(key=='5'){
    acceleration =0;
  }else if(key=='6'){
    acceleration =1;
  }else if(key=='7'){
    acceleration =2;
  }else if(key=='8'){
    acceleration =3;
  }else if(key=='9'){
    acceleration =3.5;
  }else if(key=='0'){
    acceleration =50;
  }
}

void myMotion(int x, int y)
{
    	int xDisp, yDisp;

    	xDisp = x - xBegin;    	yDisp = -y + yBegin;

    	switch(mButton)
	{
    	   case GLUT_LEFT_BUTTON:
		azimuth += (double) xDisp/5.0;
        	elevation -= (double) yDisp/5.0;
        	break;

    	   case GLUT_RIGHT_BUTTON:
        	distance -= (double) (xDisp + yDisp)*10.0;
        	break;
    	}
    	xBegin = x;    yBegin = y;

    	glutPostRedisplay();
}

void myInit (char *progname)
{
	int width = 1280, height = 720;

    glutInitWindowPosition(0, 0);
    glutInitWindowSize( width, height);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow(progname);
    glClearColor (0.0, 0.0, 0.0, 1.0);
   	glutMouseFunc( myMouse );
    glutMotionFunc( myMotion );
    glutKeyboardFunc( myKbd );

    	distance = 0;   elevation=0;    azimuth = -90;

	glShadeModel(GL_FLAT);
	initLighting();
}

void myReshape(int width, int height)
{
	float aspect = (float) width / (float) height;

	glViewport(0, 0, width, height);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluPerspective(50.0, aspect, 1.0, 3000.0);
    	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{	glutInit(&argc, argv);
	myInit(argv[0]);
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();

	return(0);
}
