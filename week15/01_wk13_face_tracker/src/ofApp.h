#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"      // includes OpenCV library
#include "ofxCv.h"          // makes openCV easier to work with

using namespace cv;
using namespace ofxCv;

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
    
    ofVideoGrabber webcam;
    // ofImage, or ofVideoPlayer etc...
    
    ofxCv::ObjectFinder finder; // generic object finder
    // we'll use this as a face detector
    
    ofConePrimitive hat;
    
		
};
