#pragma once

#include "ofMain.h"
#include "Ball.h"	// include our ball class

// we declare this number outside of our class
// it's a "global constant" for our app:

const int numBalls = 5;    // 'const' means numBalls can never change


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

    Ball balls[numBalls];
    
    glm::vec2 gravity;
		
};
