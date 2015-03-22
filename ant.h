#ifndef ANT_H_
#define ANT_H_

#include <iostream>

#include "ant_body.h"
#include "ant_leg.h"

using namespace std;

const int JOINT_TOTAL = 3;
const int JOINT_NECK = 0;
const int JOINT_LEGS_BASE = 1;
const int JOINT_LEGS_TIP = 2;

class Ant {

public:

	Ant();

	void init();

	void onDisplay();

	void setAngle( int horizontal, int vertical );

	void setScale( int vertical, int window_height);

	void toggleBoundingBox();

	void toggleJoint();

	void onIncreaseJoint();
	void onDecreaseJoint();

private:

	bool show_bounding_box = false;

	int joint_control = JOINT_NECK;

	float joint_angle_neck = 0;
	float joint_angle_legs_base = 0;
	float joint_angle_legs_tip = 20;

	float scale = 1.0;

	GLdouble horizontal_spin = 0,
			 vertical_spin = 0;

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
