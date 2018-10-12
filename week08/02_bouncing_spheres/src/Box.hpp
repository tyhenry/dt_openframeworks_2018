//
//  Box.hpp
//  00_bouncing_spheres
//
//  Created by Tyler Henry on 10/6/18.
//

#pragma once
#include "ofMain.h"

class Box {
    
public:
    
    // Box class
    // store / draw a 3D box
          
    Box(glm::vec3 _pos = glm::vec3(0,0,0), float _size = 1000)
    :   // initialize data:
        pos     (_pos),
        size    (_size)
    {
    }
    
    // "inline" functions are defined in header:
    
    inline void draw() {
        ofDrawBox(pos, size);       // draw a 3d box
    }
    
    inline float getLeft() {
        return pos.x - size * 0.5;
    }
    inline float getRight() {
        return pos.x + size * 0.5;
    }
    inline float getTop() {
        return pos.y + size * 0.5;  // in 3D space, +y is up!
    }
    inline float getBottom() {
        return pos.y - size * 0.5;
    }
    inline float getFront() {
        return pos.z - size * 0.5;  // in 3D space, +z is forward
    }
    inline float getBack() {
        return pos.z + size * 0.5;
    }
    
    glm::vec3 pos;
    float size  = 100;              // default to 100
    
};
