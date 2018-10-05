//
//  Attractor.cpp
//


#include "Attractor.hpp"

Attractor::Attractor()
{
	pos.x = ofRandom(ofGetWidth());
	pos.y = ofRandom(ofGetHeight());
	mass = ofRandom(5.,30.);
	
}

Attractor::Attractor(glm::vec2 _pos, float _mass)
{
	pos = _pos;
	mass = ofClamp(_mass, 5., 30.); // keep mass between 5 and 30
	
}

glm::vec2 Attractor::getForce(Mover mover)
{
	// calculate a force of attraction on mover
	
	glm::vec2 dir	= pos - mover.pos;	// the target is the attractor
    float distance	= glm::length(dir);
    
    glm::vec2 force = glm::vec2(0,0);   // default to 0 force
    
    if (distance > 0) {     // avoid division by 0
 
        // we'll model gravity:
        // from http://natureofcode.com/book/chapter-2-forces/#chapter02_section9
        //
        // gravity magnitude = (G * mass1 * mass2) / (distance * distance)
        //
        //		where G = gravitational constant
        
        // we'll "clamp" the distance between 5 and 25
        // to prevent super-massive or super-micro gravity forces
        // ... this is a hack to keep things in equilibrium!
        float distanceMod	= ofClamp(distance, 5., 25.);
        
        float strength	    = (G * mass * mover.mass) / (distanceMod * distanceMod);
	
        glm::vec2 dirNorm   = dir / distance;   // normalized direction
        force	= dirNorm * strength;
	
    }
	return force;
}

void Attractor::draw()
{
	ofPushStyle();
	
	// hue based on mass
	float hue       = ofMap(mass, 5, 30, 180, 255);
	ofColor color   = ofColor::fromHsb(hue, 255, 200);
	
	ofSetColor(color);
	
	// radius based on mass
	ofDrawCircle(pos, mass);

	ofPopStyle();
}
	
	
	
	
