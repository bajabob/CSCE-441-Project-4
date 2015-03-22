#include "ant_leg.h"

void AntLeg::init() {
	upper = new AntBody( 0, 0, 0, 0, 1, 0, 90 );
	upper->setDimensions( 6, 0.3, 0.3 );
	upper->init();

	lower = new AntBody( 0, 0, 0, 1, 0, 0, 70 );
	lower->setDimensions( 6, 0.3, 0.3 );
	lower->init();
}

void AntLeg::onDisplay() {

	glRotatef( base_angle, 0, 0, 1 );
	upper->onDisplay();

	glTranslatef( 0, 0, 6 );

	lower->onDisplay();
	lower->onPostDisplay();

	glTranslatef( 0, 0, -6 );

	upper->onPostDisplay();
	glRotatef( -base_angle, 0, 0, 1 );

}
