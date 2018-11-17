#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    ofPlanePrimitive plane;
    ofEasyCam cam;
    
    ofVideoGrabber vid;
	
	// our gui ( using ofxGui addon! )
	ofxPanel	        gui;		// our visible gui panel
	ofParameter<float>	scale;		// slider control
    ofParameter<float>  rotation;   // rotation degrees
    ofParameter<bool>   bRotate;    // auto-rotate mesh toggle
    ofParameter<bool>   bTexture;   // toggle color texture
    ofParameter<bool>   bSolid;     // draw solid mesh surface
	ofParameter<bool>	bWires;		// draw wireframe toggle
	ofParameter<bool>	bAxis;		// draw scene axis toggle
		
};

