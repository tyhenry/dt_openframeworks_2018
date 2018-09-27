//
//  Arrow.hpp
//  05_atan2
//
//  Created by Tyler Henry on 9/26/18.
//

#pragma once
#include "ofMain.h"

// declare simple Arrow class
class Arrow {
    
public:
    
    void setup();
    void update(glm::vec2 target);  // arrow follows a target around the screen
    void draw();
    
    glm::vec2 pos;
    float angle;
    
};

