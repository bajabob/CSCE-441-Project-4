#include "ant_body.h"

void AntBody::setDimensions( float length, float frontRadius, float backRadius ) {
	this->length = length;
	this->backRadius = backRadius;
	this->frontRadius = frontRadius;
}

void AntBody::init() {
	this->body = gluNewQuadric();
	gluQuadricNormals( this->body, GLU_SMOOTH );

	this->back = gluNewQuadric();
	gluQuadricNormals( this->back, GLU_SMOOTH );

	this->front = gluNewQuadric();
	gluQuadricNormals( this->front, GLU_SMOOTH );
}

void AntBody::onDisplay() {
	glRotatef( this->angle, this->rx, this->ry, this->rz );
	glTranslatef( this->tx, this->ty, this->tz );

	gluCylinder( this->body, this->backRadius, this->frontRadius, this->length,
			32, 32 );
	gluSphere( this->back, this->backRadius, 32, 32 );
	glTranslatef( 0, 0, this->length );
	gluSphere( this->front, this->frontRadius, 32, 32 );
	glTranslatef( 0, 0, -this->length );

}

void AntBody::onPostDisplay() {
	glTranslatef( -this->tx, -this->ty, -this->tz );
	glRotatef( -this->angle, this->rx, this->ry, this->rz );
}
