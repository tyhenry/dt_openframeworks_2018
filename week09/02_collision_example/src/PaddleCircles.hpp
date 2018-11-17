//
//  PaddleCircles.hpp
//  collision_example
//
//  Created by Tyler Henry on 10/26/18.
//

#pragma once
#include "ofMain.h"

// a pinball paddle
// made out of a bunch of circles

class PaddleCircles {
public:
    
    PaddleCircles();
    PaddleCircles(glm::vec2 _pos, float angleDegrees);
    
    void setup();
    
    void draw(); 
    
    // rotate the paddle around the base
    void rotate(float degrees);
    
    // test if a pinball is colliding
    bool testCollision(glm::vec2 ballPos, float ballRadius);
    
    glm::vec2 getDirection();   // angle -> vector
    glm::vec2 getNormal();
    
    glm::vec2 pos;
    float angleRadians;
    
    // store each circle's postiion and radius:
    vector<glm::vec2>   circlePositions;
    vector<float>       circleRadii;
    
    
};
