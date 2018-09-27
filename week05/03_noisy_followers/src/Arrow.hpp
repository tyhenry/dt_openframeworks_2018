//
//  Arrow.hpp
//  03_noisy_followers
//
//  Created by Tyler Henry on 9/24/18.
//

#pragma once
#include "ofMain.h"

class Arrow {
public:
    
    Arrow( float arrowSize = 10., float arrowSpeed = 1. );        // construct a new arrow
    
    void follow(glm::vec3 target);                      // arrow follows a target
    void draw();                                        // draw
    
    glm::vec3 pos;
    
    float angle;        // angle in degrees
    
    float size;
    float speed;        // speed, 0-1
    
    ofColor color = ofColor::white;
    
};
