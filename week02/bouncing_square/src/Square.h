#pragma once
#include "ofMain.h"

class Square {
public:
    void setup(float posX, float posY, float width, float height);
    void update();
    void draw();
    
    // some extra "utility" functions -
    // return the center coordinates
    float getCenterX();
    float getCenterY();
    
    float x, y, w, h;
    float dirX, dirY;
    
};

