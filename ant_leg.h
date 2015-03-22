#ifndef ANT_LEG_H_
#define ANT_LEG_H_

#include <iostream>

#include "ant_body.h"

using namespace std;

class AntLeg{

public:
	void init();
	void onDisplay();
	void setBaseAngle(float angle);
	void setTipAngle(float angle);
private:

	/**
	 * The up/down angle of upper leg
	 */
	float base_angle;

	/**
	 * the up/down angle of the lower leg
	 */
	float tip_angle;

	AntBody *upper;
	AntBody *lower;

};

#endif
