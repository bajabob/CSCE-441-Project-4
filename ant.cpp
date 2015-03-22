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

	// helps show the bounds of the ant
	if ( show_bounding_box ) {
		glutWireCube( 20.0 );
	}

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
	glRotatef( joint_angle_neck, 0, 1.0, 0.0 );
	neck->onDisplay();
	head->onDisplay();
	head->onPostDisplay();
	neck->onPostDisplay();
	glRotatef( -joint_angle_neck, 0, 1.0, 0.0 );

	front_left_leg->setBaseAngle( joint_angle_legs_base );
	front_right_leg->setBaseAngle( joint_angle_legs_base );
	middle_left_leg->setBaseAngle( joint_angle_legs_base );
	middle_right_leg->setBaseAngle( joint_angle_legs_base );
	rear_left_leg->setBaseAngle( joint_angle_legs_base );
	rear_right_leg->setBaseAngle( joint_angle_legs_base );

	front_left_leg->setTipAngle( joint_angle_legs_tip );
	front_right_leg->setTipAngle( joint_angle_legs_tip );
	middle_left_leg->setTipAngle( joint_angle_legs_tip );
	middle_right_leg->setTipAngle( joint_angle_legs_tip );
	rear_left_leg->setTipAngle( joint_angle_legs_tip );
	rear_right_leg->setTipAngle( joint_angle_legs_tip );

	front_left_leg->onDisplay();
	glRotatef( 180, 0, 1.0, 0.0 );
	front_right_leg->onDisplay();

	glTranslatef( 0, 0, 2.5 );
	middle_right_leg->onDisplay();
	glRotatef( 180, 0, 1.0, 0.0 );
	middle_left_leg->onDisplay();

	glTranslatef( 0, 0, -2.5 );
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

void Ant::toggleBoundingBox() {
	show_bounding_box = !show_bounding_box;
}

void Ant::toggleJoint() {
	++joint_control;
	if ( joint_control == JOINT_TOTAL ) {
		joint_control = 0;
	}
}
