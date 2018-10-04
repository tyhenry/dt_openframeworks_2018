//
//  ParticleSystem.hpp
//  wk06_particle_system
//
//  Created by Tyler Henry on 10/2/18.
//

#pragma once
#include "ofMain.h"
#include "Particle.hpp"

class ParticleSystem {
public:
    
    ParticleSystem();
    ParticleSystem(glm::vec2 _pos);
    
    void update(glm::vec2 force);
    void draw();
    
    glm::vec2 pos;
    
    vector<Particle> particles;
};
