#ifndef ANT_H_
#define ANT_H_

#include <iostream>

#include "ant_thorax.h"

using namespace std;

class Ant{

public:

	Ant(){
		thorax = new AntThorax();
	}

	void init(){
		thorax->init();
	}

	void onDisplay(){
		glPushMatrix();
		glTranslatef( 0, 0, -100 );
		glRotatef( 10.0, 1., 1., 1. );
		glutWireCube(20.); //cube of size 20x20x20
		thorax->onDisplay();
		glPopMatrix();
	}

private:

	AntThorax *thorax;

};

#endif
