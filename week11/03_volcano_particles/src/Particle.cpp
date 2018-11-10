//
//  Particle.cpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#include "Particle.hpp"

Particle::Particle()
{
    pos			= glm::vec3();
	vel.x		= ofRandom(-1,1);
	vel.y		= ofRandom(-1,1);
	vel.z		= ofRandom(-1,1);
	lifespan		= ofRandom(5,10); // seconds
	mass		    = ofRandom(1,3);
	lastUpdateTime  = ofGetElapsedTimef();
}

Particle::Particle(glm::vec3 _pos, glm::vec3 _vel, float _life, float _mass)
{
	pos			= _pos;
	vel			= _vel;
	lifespan    = _life;
	mass		= _mass;
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::applyForce(glm::vec3 force)
{
	acc += force / mass;
}

void Particle::applyDrag(float amt)
{
    float speed = glm::length(vel);
    if (speed > 0) {
        applyForce( -vel / speed * amt );
    }
}

void Particle::update()
{
	vel += acc;
	pos += vel;
	acc *= 0;
	
    // update age
	age += ofGetElapsedTimef() - lastUpdateTime;    // + time diff
	lastUpdateTime = ofGetElapsedTimef();
}

void Particle::draw()
{
	ofPushStyle();
	
	ofColor fire	= ofColor(255, 120, 0);
	ofColor smoke	= ofColor(34, 32, 30);

	float lerp		= ofClamp(age/lifespan, 0, 1);
	ofColor color	= fire.getLerped( smoke, lerp);
	ofSetColor( color );
	
	material.setEmissiveColor( color );
	material.begin();
	
	float radius		= ofMap(age, 0, lifespan, 1, 15);
	
	ofDrawSphere(pos, radius);
	
	material.end();
	
	ofPopStyle();
}

