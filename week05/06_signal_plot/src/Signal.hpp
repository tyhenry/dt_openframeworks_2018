//
//  Signal.hpp
//  06_signal_plot
//
//  Created by Tyler Henry on 9/26/18.
//

// simple Signal class just contains a current position, and the previous position
// and can draw a line between the two

#pragma once
#include "ofMain.h"

class Signal {
public:
    
    void setup();
    
    void update(float x, float y);
    
    void draw();
    
    void resetPos(float x, float y);
    
    glm::vec2 pos, prevPos;     // current position, last frame's position
    
    ofColor color;
};
