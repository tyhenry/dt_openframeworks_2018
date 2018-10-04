#pragma once

#include "ofMain.h"
#include "ParticleSystem.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mouseReleased(int x, int y, int button);

    vector<ParticleSystem> particleSystems;
    glm::vec2 gravity;
    
		
};
