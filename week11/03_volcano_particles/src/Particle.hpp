//
//  Particle.hpp
//  ParticleSystem
//
//  Created by Tyler on 10/5/17.
//
//

#pragma once
#include "ofMain.h"

class Particle {
	
public:

	Particle();
	~Particle(){}
	
    Particle(glm::vec3 _pos, glm::vec3 _vel, float _life, float _mass);
	
    void applyForce(glm::vec3 force);
	void applyDrag(float amt);
	
	void update();
	void draw();
	
    glm::vec3 pos, vel, acc;
	
	float age = 0; // seconds
	
	float lifespan;	// seconds
	
	float mass;
	

private:
	
	ofMaterial material;	// shininess
	
	float lastUpdateTime = 0;	// track elapsed time
	
};
