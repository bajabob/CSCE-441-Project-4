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
	cout << "onDisplay" << endl;

	glClear( GL_COLOR_BUFFER_BIT );

	ant->onDisplay();

	glutSwapBuffers();
}

void onMouse( int button, int state, int x, int y ) {
	if ( state == GLUT_DOWN ) {

		glutPostRedisplay();
	}

}

void onMouseMove( int x, int y ) {

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

	GLdouble Vol = 10 * 1.8;
	GLdouble Left = -Vol;
	GLdouble Right = Vol;
	GLdouble Bottom = -Vol;
	GLdouble Top = Vol;
	GLdouble Near = 0;
	GLdouble Far = 2 * Vol;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( Left, Right, Bottom, Top, Near, Far );

	GLdouble eyeX = 0;
	GLdouble eyeY = 0;
	GLdouble eyeZ = -100 + Vol;
	GLdouble centerX = 0;
	GLdouble centerY = 0;
	GLdouble centerZ = -100;
	GLdouble upX = 0;
	GLdouble upY = 1;
	GLdouble upZ = 0;

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt( eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ );
}

int main( int argc, char** argv ) {
	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
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
