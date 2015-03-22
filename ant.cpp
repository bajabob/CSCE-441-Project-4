#include "ant.h"

Ant::Ant() {
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

	glScalef(scale, scale, 1);

	/**
	 * Translate/Rotate the whole ant
	 */
	glTranslatef( 0, 0, -100 );
	glRotatef( horizontal_spin, 0.0, 1.0, 0.3 );
	glRotatef( vertical_spin, 1.0, 0.0, 0.3 );

	// helps show the bounds of the ant
	if ( show_bounding_box ) {
		glutWireCube( 20.0 );
	}

	glColor3d( 1.0, 0.0, 0.0 );

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

	glColor3d( 0.0, 0.2, 0.2 );

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

	glColor3d( 0.5, 0.5, 0.0 );

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

	glScalef(-scale, -scale, 1);

	glPopMatrix();
}

void Ant::setAngle( int horizontal, int vertical ) {
	if ( horizontal > 0 || horizontal < 360 ) {
		this->horizontal_spin = horizontal;
	}
	if ( vertical > 0 || vertical < 360 ) {
		this->vertical_spin = vertical;
	}
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

void Ant::onIncreaseJoint() {
	switch (joint_control) {
	case JOINT_NECK:
		if ( joint_angle_neck < 40 ) {
			++joint_angle_neck;
		}
		break;
	case JOINT_LEGS_BASE:
		if ( joint_angle_legs_base < 60 ) {
			++joint_angle_legs_base;
		}
		break;
	case JOINT_LEGS_TIP:
		if ( joint_angle_legs_tip < 60 ) {
			++joint_angle_legs_tip;
		}
		break;
	}
}
void Ant::onDecreaseJoint() {
	switch (joint_control) {
	case JOINT_NECK:
		if ( joint_angle_neck > -40 ) {
			--joint_angle_neck;
		}
		break;
	case JOINT_LEGS_BASE:
		if ( joint_angle_legs_base > -60 ) {
			--joint_angle_legs_base;
		}
		break;
	case JOINT_LEGS_TIP:
		if ( joint_angle_legs_tip > -60 ) {
			--joint_angle_legs_tip;
		}
		break;
	}
}

void Ant::setScale(int vertical, int window_height){
	if(vertical > 0 || vertical < window_height){
		this->scale = ((vertical * 4.0)/window_height)-2.0;
	}
}
