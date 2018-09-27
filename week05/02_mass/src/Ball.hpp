//
//  Ball.hpp
//  Mass
//

#pragma once
#include "ofMain.h"

class Ball {
public:
		

    void setup(glm::vec2 p, float m);	// mass should be on scale of 0 to 10
	
    void applyForce(glm::vec2 force); // acceleration += force / mass
	
	void update(); // apply and reset acceleration
	
	void checkWalls(ofRectangle walls); // bounce off walls
	
	void draw();
	void drawDirectionLine();	// draw ball's direction vector

	
    glm::vec2 pos, vel, acc;
	
	float mass;         // mass adds "weight" - this "resists" external forces
    // force = mass x acceleration      <-- Newton's second law
    // acceleration = force / mass      <-- divide force by mass
    
	float radius;		// we use the mass to set radius and color internally
	ofColor color;
	
	
	
};
