#pragma once

#include "ofMain.h"

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
    
    
    ofShader maskShader;        // masks one texture using another
    ofPlanePrimitive plane;     // used to draw the shader
		
    ofImage image, mask;
    
    glm::vec2 maskOffset;
    
    ofEasyCam cam;
    
};
