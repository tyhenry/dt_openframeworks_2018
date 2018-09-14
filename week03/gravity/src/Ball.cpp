#include "Ball.h"

// setup
void Ball::setup(float size, float bounceFactor) {

	// initialize the object's variables

	// center on screen
	pos.x = ofGetWidth() * 0.5;
	pos.y = ofGetHeight() * 0.5;

	// no velocity to start
    vel = glm::vec2(0,0);
    
    // size
    radius = size;
    
    // bounce factor
    bounce = bounceFactor;
    
    // bounce = 0.0 would mean no bounce at all
    // bounce = 1.0 is perfect bounce, no loss of momentum
    
    
}

// update
void Ball::update(glm::vec2 force) {
    
    // move ball
    
    vel+=force;     // apply force (acceleration)
    pos+=vel;
    

    // check for bounces at edges of window:

	// check left
	if (pos.x <= radius) {
        
		pos.x = radius;		    // set the position back to the edge of window
        
        vel.x *= -bounce;		// bounce is a float from 0.0 to 1.0
                                // if bounce < 1.0, it will slow momentum
                                // (-1 * bounce) flips direction
	}
	// check right
	else if (pos.x >= ofGetWidth() - radius) {
		pos.x = ofGetWidth() - radius;			// similar to above
		vel.x *= -bounce;
	}

	// check top and bottom
	if (pos.y <= radius) {
		pos.y = radius;
		vel.y *= -bounce;
	}
	else if (pos.y >= ofGetHeight() - radius) {
		pos.y = ofGetHeight() - radius;
		vel.y *= -bounce;
	}
}


// draw the ball
void Ball::draw() {

    // set the color based on bounciness -
    // we'll interpolate between 2 colors:
    
    ofColor color1 = ofColor(50,0,255);     // purple-ish
    ofColor color2 = ofColor(255,100,220);  // pink-ish
    float percent  = bounce;        // 0 - 1
    
    ofColor color  = color1.getLerped(color2, percent);
    
    ofSetColor(color);
    
	ofDrawCircle(pos, radius);		// draw
    ofSetColor(255);                // restore global white draw color
}
