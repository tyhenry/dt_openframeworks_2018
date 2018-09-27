#pragma once

#include "ofMain.h"
#include "Arrow.hpp"


// ofApp
class ofApp : public ofBaseApp{

public:
    
    void setup();
    void update();
    void draw();
    
    // note - I removed the "event" functions for simplicity
    // this is ok if you're not going to use keyboard or mouse events
	
	Arrow arrow;
		
};
