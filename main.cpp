#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "ant.h";

const int VIEWMODE_TOTAL = 3;
const int VIEWMODE_ROTATE = 0;
const int VIEWMODE_SCALE = 1;
const int VIEWMODE_TRANSLATE = 2;

int current_viewmode = VIEWMODE_ROTATE;

int window;

Ant *ant;

float translate_horizontal = 0;
float translate_vertical = 0;

void onDisplay( void ) {

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glTranslatef( translate_horizontal, translate_vertical, 0 );
	ant->onDisplay();
	glTranslatef( -translate_horizontal, -translate_vertical, 0 );
	glutSwapBuffers();
}

void onMouse( int button, int state, int x, int y ) {
	if ( state == GLUT_DOWN ) {

		glutPostRedisplay();
	}

}

void onMouseMove( int x, int y ) {
	switch (current_viewmode) {
	case VIEWMODE_ROTATE:
		ant->setAngle( x, y );
		break;
	case VIEWMODE_SCALE:
		ant->setScale(y, 400);
		break;
	case VIEWMODE_TRANSLATE:
		int locx = x - 200;
		int locy = 200 - y;



		translate_horizontal = (locx * 35) / 400;
		translate_vertical = (locy * 35) / 400;
		break;
	}
	glutPostRedisplay();
}

void onKeyPress( unsigned char key, int x, int y ) {
	switch ((char) key) {
	case 'q':
	case 27: // esc key
		glutDestroyWindow( window );
		exit( 0 );
		break;
	case '+':
	case '=':
		ant->onIncreaseJoint();
		break;
	case '-':
		ant->onDecreaseJoint();
		break;
	case 'v':
		++current_viewmode;
		if ( current_viewmode == VIEWMODE_TOTAL ) {
			current_viewmode = 0;
		}
		break;
	case 'b':
		ant->toggleBoundingBox();
		break;
	case 'j':
		ant->toggleJoint();
		break;
	default:
		break;
	}
	glutPostRedisplay();
	return;
}

void init( void ) {
	ant = new Ant();

	glClearColor( 0.0, 0.0, 0.0, 0.0 );

	ant->init();

	GLdouble volume = 1.7 * 10;
	GLdouble left = -volume;
	GLdouble right = volume;
	GLdouble bottom = -volume;
	GLdouble top = volume;
	GLdouble near = 0;
	GLdouble far = 2 * volume;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( left, right, bottom, top, near, far );

	GLdouble upX = 0;
	GLdouble upY = 1;
	GLdouble upZ = 0;
	GLdouble cameraX = 0;
	GLdouble cameraY = 0;
	GLdouble cameraZ = volume + (-100);
	GLdouble centerX = 0;
	GLdouble centerY = 0;
	GLdouble centerZ = -100;

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( cameraX, cameraY, cameraZ, centerX, centerY, centerZ, upX, upY,
			upZ );

	glColorMaterial( GL_FRONT_AND_BACK, GL_EMISSION );
	glEnable( GL_COLOR_MATERIAL );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );

	GLfloat lightpos[] = { .4, 1., 1., 0. };
	glLightfv( GL_LIGHT0, GL_POSITION, lightpos );

	glEnable( GL_DEPTH_TEST );
	glDisable( GL_TEXTURE_2D );
}

int main( int argc, char** argv ) {
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize( 400, 400 );
	glutInitWindowPosition( 100, 100 );
	window = glutCreateWindow( "Robert Timm - Homework 4" );

	glutMouseFunc( onMouse );
	glutMotionFunc( onMouseMove );
	glutKeyboardFunc( onKeyPress );
	glutDisplayFunc( onDisplay );

	init();

	glutMainLoop();
	return 0;
}
