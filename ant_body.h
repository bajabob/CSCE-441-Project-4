#ifndef ANTTHORAX_H_
#define ANTTHORAX_H_

#include <iostream>

#include "position.h"

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

class AntBody: public Position {

public:

	AntBody( GLdouble tx, GLdouble ty, GLdouble tz, GLdouble rx, GLdouble ry,
			GLdouble rz, GLdouble angle ) :
			Position( tx, ty, tz, rx, ry, rz, angle ) {
	}

	void setDimensions(float length, float frontRadius, float backRadius);
	void init();
	void onDisplay();
	void onPostDisplay();

private:

	float length;

	float backRadius, frontRadius;

	GLUquadricObj *body, *back, *front;

};

#endif
