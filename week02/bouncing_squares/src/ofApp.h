#pragma once

#include "ofMain.h"
#include "Square.h"     // add the square class to our project

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    Square squares [10];        // declare an array of 10 squares
    // note: arrays have a fixed size
    
    //vector<Square> square;    <-- this is like an array, but better - we'll learn it next week
    
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
    
};
