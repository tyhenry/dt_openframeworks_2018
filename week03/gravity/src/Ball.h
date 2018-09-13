// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once		
#include "ofMain.h"		// ofMain.h lets our Ball "see" openFrameworks

class Ball {

public:		// other classes can access the following functions & variables:

	void setup();
    void update(glm::vec2 force); 	// update the ball with a force each time
	void draw();
    
	float radius;		// size
    
    glm::vec2 pos;		// position
    glm::vec2 vel;		// velocity (speed + direction)

    glm::vec2 acc;		// accelleration (force)

	ofColor color;

};