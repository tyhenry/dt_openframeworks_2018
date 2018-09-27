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
	
	// locations to Oscillatorillate
	
	glm::vec2 sinOscillator;
	glm::vec2 cosOscillator;
	glm::vec2 mixOscillator; // we'll mix sin and cos Oscillatorillation over x and y
	
    float amplitude, sinFrequency, cosFrequency;
	
	ofPolyline mixTrail;    // we'll store the mixOscillator positions
                            // over time to draw a trail
		
};
