#include "Ball.h"

// setup
void Ball::setup() {

	// initialize the object's variables

	// random radius between 10 and 50
	radius = ofRandom(10,20);			

	// random colors
	float red	= ofRandom(0,255);
	float green	= ofRandom(0,255);		
	float blue	= ofRandom(0,255);
	color = ofColor(red, green, blue);

	// center on screen
	pos.x = ofGetWidth() * 0.5;
	pos.y = ofGetHeight() * 0.5;

	// no velocity to start
    vel = glm::vec2(0,0);
    
}

// update position, etc.
void Ball::update(glm::vec2 force) {
    
    acc = force;
    
    vel+=acc;
    pos+=vel;

	// check for bounces at edges of window:

	// check left
	if (pos.x <= radius) {
		pos.x = radius;		// set the position back to the edge of window
		vel.x *= -1;		// and reverse velection
	}
	// check right
	else if (pos.x >= ofGetWidth() - radius) {
		pos.x = ofGetWidth() - radius;			// similar to above
		vel.x *= -1; // slow down
	}

	// check top and bottom
	if (pos.y <= radius) {
		pos.y = radius;
		vel.y *= -1;
	}
	else if (pos.y >= ofGetHeight() - radius) {
		pos.y = ofGetHeight() - radius;
		vel.y *= -1;
	}
}


// draw the ball
void Ball::draw() {

	ofSetColor(color);				// set the GLOBAL color
	ofDrawCircle(pos, radius);		// and draw
    ofSetColor(255);                // restore global white draw color
}
