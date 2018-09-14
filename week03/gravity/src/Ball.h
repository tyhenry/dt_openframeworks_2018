// Ball.h

/* #pragma once should always be at the top of your header files
 * it prevents other headers like "ofMain.h" from being included more than once in your app
 * (note that ofMain.h is also included in ofApp.h)
 */

#pragma once		
#include "ofMain.h"

class Ball {

public:

    void setup(float size, float bounceFactor);     // init size and ball's "bounciness"
    void update(glm::vec2 force);                   // apply force
	void draw();
    
    glm::vec2 pos;		// position
    glm::vec2 vel;		// velocity (speed + direction)
    
    float bounce;       // "bounciness" factor, from 0.0 to 1.0
    float radius;       // ball size
    

};
