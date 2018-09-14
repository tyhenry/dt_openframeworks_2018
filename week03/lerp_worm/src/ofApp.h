#pragma once

#include "ofMain.h"

// add an extra class quickly:

// super simple Ball class with no functions,
// just position, radius, color and interpolation pct

class Ball {
public:
    
    glm::vec2 pos;
    float radius;
    ofColor color;
    float lerp;     // amount to interpolate when moving
                    // (percentage of distance to target)
};

// now back to our ofApp class as normal

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Ball balls[10];     // array of 10 Balls, see class declaration above
		
};
