#ifndef ANT_H_
#define ANT_H_

#include <iostream>

#include "ant_body.h"
#include "ant_leg.h"

using namespace std;

class Ant {

public:

	Ant();

	void init();

	void onDisplay();

	void setAngle( int angle );

private:

	GLdouble angle;

	AntBody *thorax;
	AntBody *abdomen;
	AntBody *neck;
	AntBody *head;

	AntLeg *front_left_leg;
	AntLeg *front_right_leg;
	AntLeg *middle_left_leg;
	AntLeg *middle_right_leg;
	AntLeg *rear_left_leg;
	AntLeg *rear_right_leg;

};

#endif
