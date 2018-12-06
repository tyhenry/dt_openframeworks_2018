#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    ofPath generateDaisy( int numPetals, float petalLength, float centerRadius );

    void keyPressed(int key);

    
    ofPath path;        // ofPath is a shape
    
    ofMesh mesh;        // store shape as mesh
    ofShader shader;    // apply shaders to mesh
    
    ofImage image;      // mesh texture
    ofEasyCam cam;      // 3D viewpoint
    
    ofRectangle bounds; // the bounds of our mesh
    
    float colorMix;     // color gradient <-> texture mix
    
    // animation:
    bool animating = true;
    float startTime = 0;

};
