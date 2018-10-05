#pragma once

#include "ofMain.h"
#include "ElasticMover.hpp"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyReleased(int key);
	
	vector<ElasticMover> movers;
	
	bool bSpin;     // animate / spin the spiral?
		
};
