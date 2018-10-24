//
//  Particle.hpp
//  wk09_vector_field
//
//  Created by Tyler Henry on 10/23/18.
//

#pragma once
#include "ofMain.h"

class Particle {
    
public:
    
    Particle();
    Particle(glm::vec2 _pos, glm::vec2 _vel = glm::vec2(0));
    
    void applyForce(glm::vec2 force);
    void applyDrag(float strength);
    
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    
};
