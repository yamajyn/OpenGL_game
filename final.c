#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "myShape.h"

int xBegin, yBegin;
int mButton;
float distance, elevation, azimuth;
float rot=0.;
//color

//initial
float ambient[]  = { 0.4, 0.4, 0.4, 1.0 };//ä¬ã´åı
float diffuse[] = { 0.8, 0.8, 0.8, 1.0 };//ägéUåı
float specular[] = { 0.0, 0.0, 0.0, 1.0 };//ãæñ îΩéÀ
//ground
float groundDif[] = { 160./255,160./255 , 160./255, 1.0 };
//line
float lineDif[] = { 70./255,30./255 , 0., 1.0 };
float lineSpe[] = {0.5, 0.5, 0.5, 1.0};


float shininess = 128.;

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix ();
	glEnable(GL_DEPTH_TEST);
	glEnable( GL_LIGHTING );
    	glTranslatef( 0.0, 0.0, -distance);
    	glRotatef( -elevation, 1.0, 0.0, 0.0);
    	glRotatef( -azimuth, 0.0, 1.0, 0.0);

// x axis
    	   glColor3f( 1.0, 0.0, 0.0 );
	   glPushMatrix();
     	   glBegin( GL_LINES );
           	glVertex3f( 0., 0., 0.01 );  glVertex3f( 5., 0., 0.01 );
    	   glEnd();
    	   glPopMatrix();
// y axis
    	   glColor3f( 0.0, 1.0, 0.0 );
	   glPushMatrix();
     	   glBegin( GL_LINES );
        	glVertex3f( 0., 0., 0.01 );  glVertex3f( 0., 5., 0.01 );
    	   glEnd();
    	   glPopMatrix();
// z axis
    	   glColor3f( 0.0, 0.0, 1.0 );
	   glPushMatrix();
     	   glBegin( GL_LINES );
           	glVertex3f( 0., 0., 0. );  glVertex3f( 0., 0., 5. );
    	   glEnd();
    	   glPopMatrix();



	glMaterialfv( GL_FRONT, GL_SPECULAR, specular );
	glMaterialfv( GL_FRONT, GL_AMBIENT, ambient );
	glMaterialf( GL_FRONT, GL_SHININESS, shininess );
// ground
	   glMaterialfv( GL_FRONT, GL_DIFFUSE, groundDif );
	   glPushMatrix ();
	   glRotatef( -90., 1.0, 0.0, 0.0);
	   glNormal3f(0., 0., 1.);
	   glRecti(-100,-100, 100,100);
	   glPopMatrix ();


//line

	glPushMatrix();
		glMaterialfv( GL_FRONT, GL_DIFFUSE, lineDif );
		glScalef(200, 100, 100 );
		glRotatef( rot, 0.0, 1.0, 0.0 );
		glTranslatef( 0., 1.0, -10.0 );
		glutSolidCube(2.0);
	glPopMatrix();

	glPushMatrix();
		glScalef(200, 0.1, 0.05 );
		glRotatef( rot, 0.0, 1.0, 0.0 );
		glTranslatef( 0., 1.0, 10.0 );
		glutSolidCube(2.0);
	glPopMatrix();

// car
//	   glColor3f(1.0, 1.0, 1.0);
	   glPushMatrix ();
	   glRotatef( rot, 0.0, 1.0, 0.0 );
	   glTranslatef( 0., 0.0, -5.0 );
   // body

	   	glPushMatrix ();
           	glTranslatef(0.0, 1.0, 0.0 );
	   	glScalef(2.0, 0.5, 1.0 );
//	   	glutWireCube(2.0);
		glutSolidCube(2.0);
	   	glPopMatrix();
   // body-top
	   	glPushMatrix ();
           	glTranslatef(0.0, 2.0, 0.0 );
	   	glScalef(1.2, 0.5, 1.0 );
//	   	glutWireCube(2.0);
		glutSolidCube(2.0);
	   	glPopMatrix();
   // front wheel
		glMaterialfv( GL_FRONT, GL_DIFFUSE, diffuse );

	   	glPushMatrix ();
	   	glTranslatef( -1.0, 0.5, 0.0 );
		glRotatef( rot*5., 0.0, 0.0, 1.0 );
	   	glRotatef( 90.0, 1.0, 0.0, 0.0 );
//	   	myWireCylinder( 0.5, 2.0, 12 );
		mySolidCylinder( 0.5, 2.4, 4 );
	   	glPopMatrix();
   // rear wheel
	   	glPushMatrix ();
	  	glTranslatef( 1.0, 0.5, 0.0 );
		glRotatef( rot*5., 0.0, 0.0, 1.0 );
	   	glRotatef( 90.0, 1.0, 0.0, 0.0 );
//	   	myWireCylinder( 0.5, 2.0, 12 );
		mySolidCylinder( 0.5, 2.4, 4 );
	   	glPopMatrix();
   // propeller
		glPushMatrix ();
		glTranslatef(0., 2.6, 0.0 );
		glRotatef( rot*10., 0.0, 1.0, 0.0 );
		   glPushMatrix ();
	   	   glRotatef( 10.0, 0.0, 0.0, 1.0 );
//	   	   glScalef(0.2, 0.05, 1.0 );
//	   	   glutWireCube(3.0);
		   glScalef(6., 1.5, 30. );
		   glutSolidCube(0.1);
	   	   glPopMatrix();

	   	   glPushMatrix ();
 	   	   glRotatef( 10.0, 1.0, 0.0, 0.0 );
//	   	   glScalef(1.0, 0.05, 0.2 );
//	   	   glutWireCube(3.0);
	   	   glScalef(30., 1.5, 6.);
		   glutSolidCube(0.1);
	   	   glPopMatrix();
		glPopMatrix();

	    glDisable(GL_LIGHTING);
	    glDisable(GL_DEPTH_TEST);
	    glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void idle(void)
{

	glutPostRedisplay();
	//ïœêîÇïœâªÇ≥ÇπÇÈ
}

void myMouse(int button, int state, int x, int y)
{
	if ( state == GLUT_DOWN )
	{      	xBegin = x;     yBegin = y;
        	mButton = button;
	}
}

void myMotion(int x, int y)
{
    	int xDisp, yDisp;

    	xDisp = x - xBegin;    	yDisp = y - yBegin;

    	switch(mButton)
	{
    	   case GLUT_LEFT_BUTTON:
		azimuth += (double) xDisp/5.0;
        	elevation -= (double) yDisp/5.0;
        	break;

    	   case GLUT_RIGHT_BUTTON:
        	distance -= (double) (xDisp + yDisp)/60.0;
        	break;
    	}
    	xBegin = x;    yBegin = y;

    	glutPostRedisplay();
}

void myInit (char *progname)
{    	int width = 600, height = 450;

    	glutInitWindowPosition(0, 0);
    	glutInitWindowSize( width, height);
    	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    	glutCreateWindow(progname);
    	glClearColor (0.0, 0.0, 0.0, 1.0);

   	glutMouseFunc( myMouse );
    	glutMotionFunc( myMotion );

    	distance = 20.0;   elevation=-45.0;    azimuth = 30.0;

	glShadeModel(GL_FLAT);
	glEnable(GL_LIGHT0);
}
void myReshape(int width, int height)
{
	float aspect = (float) width / (float) height;

	glViewport(0, 0, width, height);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	gluPerspective(60.0, aspect, 1.0, 100.0);
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
