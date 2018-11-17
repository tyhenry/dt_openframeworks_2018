#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    ofxOscSender sender;
    bool mousePress[2]; // track our button states
    
    ofxOscReceiver receiver;
    glm::vec2 oscMousePos;
    bool oscMousePress[2]; // received button states
};
