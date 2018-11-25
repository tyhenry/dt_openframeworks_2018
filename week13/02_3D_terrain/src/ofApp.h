#pragma once

#include "ofMain.h"
#include "Terrain.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    
    void generateTerrain();

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
		
    Terrain terrain;
    ofEasyCam cam;
    ofLight light;
    
    ofImage heightMap, textureMap;
    
    // gui controls:
    ofxPanel gui;
    // --- terrain mesh
    ofParameterGroup    terrainParams;
    ofParameter<int>    terrainResolution;
    ofParameter<float>  terrainHeight; // from height map
    ofParameter<void>   regenerateTerrainButton; // button
    
    // --- draw
    ofParameterGroup    drawParams;
    ofParameter<bool>   bDrawSurface, bTexture, bDrawWireframe, bDrawNormals, bLighting;
    ofParameter<ofColor> lightColor;
    
    // --- noise
    ofParameterGroup    noiseParams;
    ofParameter<bool>   bNoise;         // enable noise
    ofParameter<glm::vec2>  noiseFreq;  // spatial frequency
    ofParameter<float>  noiseSpeed, noiseAmp;   // time, height
    
};
