#include "ant.h"

Ant::Ant() {
	angle = 80.0f;
	thorax = new AntBody( 0, 0, -5, 0, 0, 0, 0 );
	thorax->setDimensions( 5, 1.0, 1.0 );
	abdomen = new AntBody( 0, 0, -5.5, 1, 0, 0, -30 );
	abdomen->setDimensions( 3, 2.4, 1.5 );
	neck = new AntBody( 0, 0, 0, 1, 0, 0, -30 );
	neck->setDimensions( 3, 0.5, 0.5 );
	head = new AntBody( 0, 3, 3, 1, 0, 0, 60 );
	head->setDimensions( 2.1, 1.5, 2 );

	front_left_leg = new AntLeg();
	front_right_leg = new AntLeg();
	middle_left_leg = new AntLeg();
	middle_right_leg = new AntLeg();
	rear_left_leg = new AntLeg();
	rear_right_leg = new AntLeg();
}

void Ant::init() {
	thorax->init();
	abdomen->init();
	neck->init();
	head->init();

	front_left_leg->init();
	front_right_leg->init();
	middle_left_leg->init();
	middle_right_leg->init();
	rear_left_leg->init();
	rear_right_leg->init();
}

void Ant::onDisplay() {
	glPushMatrix();

	/**
	 * Translate/Rotate the whole ant
	 */
	glTranslatef( 0, 0, -100 );
	glRotatef( this->angle, 0.0, 1.0, 0.2 );

	// don't have shading, a cube helps design the ant
	glutWireCube( 20. );

	/**
	 * The thorax is our local center for the ant,
	 *  therefore we do not call a postTranslate, as all
	 *  other object positions derive from the thorax
	 */
	thorax->onDisplay();

	/**
	 * Construct the rest of the ant
	 */
	abdomen->onDisplay();
	abdomen->onPostDisplay();

	glTranslatef( 0, 0, 5.5 );
	neck->onDisplay();
	head->onDisplay();
	head->onPostDisplay();
	neck->onPostDisplay();

	front_left_leg->onDisplay();
	glRotatef( 180, 0, 1.0, 0.0 );
	front_right_leg->onDisplay();

	glTranslatef( 0, 0, 2.5 );
	middle_right_leg->onDisplay();
	glRotatef( 180, 0, 1.0, 0.0 );
	middle_left_leg->onDisplay();

	glTranslatef( 0, 0, 2.5 );
	rear_left_leg->onDisplay();
	glRotatef( 180, 0, 1.0, 0.0 );
	rear_right_leg->onDisplay();

	glPopMatrix();
}

void Ant::setAngle( int angle ) {
	if ( angle < 0 || angle > 360 ) {
		return;
	}
	this->angle = angle;
}
