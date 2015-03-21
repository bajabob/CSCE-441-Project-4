#ifndef ANT_H_
#define ANT_H_

#include <iostream>

#include "ant_thorax.h"

using namespace std;

class Ant{

public:

	Ant(){
		angle = 80.0f;
		thorax = new AntThorax();
	}

	void init(){
		thorax->init();
	}

	void onDisplay(){
		glPushMatrix();
		glTranslatef( 0, 0, -100 );
		glRotatef( this->angle, 0.0, 1.0, 0.2 );
		glutWireCube(20.); //cube of size 20x20x20
		thorax->onDisplay();
		glPopMatrix();
	}

	void setAngle(int angle){
		if(angle < 0 || angle > 360){
			return;
		}
		this->angle = angle;
	}

private:

	GLdouble angle;

	AntThorax *thorax;

};

#endif
