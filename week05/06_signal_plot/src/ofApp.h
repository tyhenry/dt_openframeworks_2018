#pragma once

#include "ofMain.h"
#include "Signal.hpp"

// ofApp

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
	
	Signal sineSignal;		        // sin wave
	Signal sineHighFreqSignal;	    // hi-frequency sin wave
	
	Signal amSignal;		// amplitude modulated sin wave
	Signal fmSignal;		// frequency modulated sin wave
	
	float xPos;				// current x pos of all signals
	float lastFrameTime;	// track timestamp of last frame
};
