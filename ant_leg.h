#ifndef ANT_LEG_H_
#define ANT_LEG_H_

#include <iostream>

#include "ant_body.h"

using namespace std;

class AntLeg{

public:
	void init();
	void onDisplay();

private:

	/**
	 * The up/down angle of upper leg
	 */
	float base_angle = 20;

	AntBody *upper;
	AntBody *lower;

};

#endif
