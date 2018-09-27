//
//  Ball.cpp
//  Mass
//

#include "Ball.hpp"

// -----------------------------
void Ball::setup(glm::vec2 p, float m)	// mass on scale of 0 to 10
{
	pos = p;		// store pos and mass
	mass = m;
	
	radius = ofMap(mass, 0, 10, 0, 50);		// init radius based on mass
	
	int hue = ofMap(mass, 0, 10, 255, 175);	// init color based on mass
	color = ofColor::fromHsb(hue % 255, 255, 200);
	
}

// -----------------------------
void Ball::applyForce(glm::vec2 force)
{
	// force = mass x acceleration - Newton's 2nd Law
	
	acc += force / mass;	// add force to acceleration
}

// -----------------------------
void Ball::update()
{
	vel += acc;	// apply accumulated acceleration
	pos += vel;
	
	acc *= 0;	// clear acceleration
}

// -----------------------------
void Ball::checkWalls(ofRectangle walls)
{

	// bounce

	
	if (pos.x - radius < walls.getLeft())	// left wall
	{
		pos.x = walls.getLeft() + radius;
		vel.x *= -1 / mass;
	}
	else if (pos.x + radius > walls.getRight())	// right wall
	{
		pos.x = walls.getRight() - radius;
		vel.x *= -1 / mass;
	}
	
	if (pos.y - radius < walls.getTop())	// top wall
	{
		pos.y = walls.getTop() + radius;
		vel.y *= -1 / mass;
	}
	else if (pos.y + radius > walls.getBottom())	// bottom wall
	{
		pos.y = walls.getBottom() - radius;
		vel.y *= -1 / mass;
	}

}

// -----------------------------
void Ball::draw()
{
	ofPushStyle();		// store style
	
	ofSetColor(color);
	
	// draw ball
	ofDrawCircle(pos, radius);
	
	ofPopStyle();		// restore style
	
	// now draw the direction line -> pointing forward
	drawDirectionLine();

}

// -----------------------------
void Ball::drawDirectionLine()
{
	ofPushStyle();		// store style
	
	// invert ball color...
	
	ofColor invC = color;
	float hue = int(color.getHue() + 127.5) % 255; // modulo only works with int!
	invC.setHue(hue);
	
	ofSetColor(invC);
	
    glm::vec2 direction;
    direction = vel / glm::length(vel);         // "normalize" the velocity to find direction
	ofDrawLine(pos, pos + direction * radius);	// draw velocity line scaled to radius
	
	ofPopStyle();		// restore style

}






