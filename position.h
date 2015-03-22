#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

class Position {

public:

	Position( GLdouble tx, GLdouble ty, GLdouble tz, GLdouble rx, GLdouble ry,
			GLdouble rz, GLdouble angle ) :
			tx( tx ), ty( ty ), tz( tz ), rx( rx ), ry( ry ), rz( rz ), angle(
					angle ) {
	}

protected:

	GLdouble tx;
	GLdouble ty;
	GLdouble tz;

	GLdouble rx;
	GLdouble ry;
	GLdouble rz;

	GLdouble angle;

};

#endif
