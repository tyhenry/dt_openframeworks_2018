//
//  Ball.hpp
//  01_vector_of_balls
//

#pragma once
#include "ofMain.h"

class Ball {
public:
    
    void setup(glm::vec2 position, float size, float bounce = 0.9);     // "bounciness" (0-1)
    void update();
    void draw();
    
    void setVelocity(glm::vec2 velocity);
    void addForce(glm::vec2 force);
    
    void bounce(float wallLeft, float wallRight, float wallTop, float wallBottom);
    
    glm::vec2 pos;      // position
    glm::vec2 vel;      // velocity
    glm::vec2 acc;      // acceleration
    
    ofColor color;
    float radius;
    float bounceFactor;     // "bounciness" amount, from 0.0 to 1.0
                            // 0.0 is no bounce, ball stops at edges
                            // 1.0 ball bounces "perfectly", no slow-down
    
};
