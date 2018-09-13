#pragma once

#include "ofMain.h"


class Ball {
// quick ball class with
// position, radius, color and interpolation pct
    
public:
    
    glm::vec2 pos;
    float radius;
    ofColor color;
    float lerp;     // amount to interpolate when moving (percent of distance to target)
    
};

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
    
    Ball balls[10]; // array of balls
		
};
