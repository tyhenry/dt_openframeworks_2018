#pragma once
#include "ofMain.h"

class Ball {
public:
    void setup(glm::vec2 _pos, float _radius);
    void update();
    void draw();
    
    glm::vec2 pos, vel, acc;
    float radius;
    
};

