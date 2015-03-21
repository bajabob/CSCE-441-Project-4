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
		gluCylinder( this->body, 10.0f, 10.0f, 10.0f, 32, 32 );
	}

private:
	GLUquadricObj *body;

};

#endif
