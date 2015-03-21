#ifndef ANTTHORAX_H_
#define ANTTHORAX_H_

#include <iostream>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

class AntThorax {

public:

	void init() {
		this->body = gluNewQuadric();
		gluQuadricNormals( this->body, GLU_SMOOTH );
		gluQuadricTexture( this->body, GL_TRUE );
	}

	void onDisplay() {
		glTranslatef( this->x, this->y, this->z );
		gluCylinder( this->body, 3.0f, 3.0f, 10.0f, 32, 32 );
	}

private:
	GLdouble x = 0;
	GLdouble y = 0;
	GLdouble z = -5;
	GLUquadricObj *body;

};

#endif
