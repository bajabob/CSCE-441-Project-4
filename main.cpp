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

int window;

Ant *ant;

void onDisplay( void ) {

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ant->onDisplay();

	glutSwapBuffers();
}

void onMouse( int button, int state, int x, int y ) {
	if ( state == GLUT_DOWN ) {

		glutPostRedisplay();
	}

}

void onMouseMove( int x, int y ) {
	ant->setAngle( x );
	glutPostRedisplay();
}

void onKeyPress( unsigned char key, int x, int y ) {
	switch ((char) key) {
	case 'q':
	case 27: // esc key
		glutDestroyWindow( window );
		exit( 0 );
	default:
		break;
	}
	glutPostRedisplay();
	return;
}

void init( void ) {
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

	// Enable lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat lightpos[] = {.5, 1., 1., 0.};
	glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

	glEnable(GL_DEPTH_TEST);
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

	ant = new Ant();

	init();

	glutMainLoop();
	return 0;
}
