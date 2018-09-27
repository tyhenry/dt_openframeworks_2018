//
//  Arrow.cpp
//  03_noisy_followers
//
//  Created by Tyler Henry on 9/24/18.
//

#include "Arrow.hpp"

//--------------------------------------------------------------
// Arrow class definitions:
//--------------------------------------------------------------

Arrow::Arrow(float arrowSize, float arrowSpeed){          // constructor
    
    // initialize variables
    
    size  = arrowSize;
    speed = arrowSpeed;
}

//--------------------------------------------------------------
void Arrow::follow(glm::vec3 target){
    
    // call at every update() to animate
    
    glm::vec3 directionVec = target - pos;      // the arrow's direction
    
    pos += directionVec * speed;                // move by interpolating towards target
    
    // calculate arrow's angle:
    
    float radians   = atan2(directionVec.y, directionVec.x);    // atan2 returns vector angle in radians
    angle           = ofRadToDeg(radians);                      // convert radians to degrees
    
}

//--------------------------------------------------------------
void Arrow::draw(){
    
    // arrow - triangle
    
    glm::vec3 p1    = glm::vec3(0);                             // 1. front point
    glm::vec3 p2    = p1 - glm::vec3(size * 3, size, 0);        // 2. right rear pt
    glm::vec3 p3    = p1 - glm::vec3(size * 3, -size, 0);       // 3. left rear pt
    
    ofPushMatrix();
    
    ofTranslate(pos);
    ofRotateDeg(angle);
    
    ofPushStyle();
    ofSetColor(color);
    
    ofDrawTriangle(p1,p2,p3);
    
    ofPopStyle();
    
    ofPopMatrix();
    
}
