//
//  Arrow.cpp
//  05_atan2
//
//  Created by Tyler Henry on 9/26/18.
//

#include "Arrow.hpp"

void Arrow::setup(){
    pos = glm::vec2(0,0);
}

void Arrow::update(glm::vec2 target){
    
    glm::vec2 direction = target - pos;     // get direction vector
    
    pos += (direction) * .03;              // interpolate 3% to target
    
    float angleRadians = atan2(direction.y, direction.x);
    // atan2(y,x) gives angle of vector in radians (like degrees, but different numbering)
    // NOTE that it is atan2(Y, X) - Y comes before X
    
    angle = ofRadToDeg(angleRadians);      // convert radians to degrees
}

void Arrow::draw(){
    
    ofPushMatrix();         // temporarily affect our drawing space
    
    ofTranslate(pos);      // move the origin of the space to the center of the arrow
    ofRotateDeg(angle);    // rotate our space
    
    ofVec3f p1 = ofVec3f(0,0);          // triangle front point
    ofVec3f p2 = p1 - ofVec3f(30,10);   // right point
    ofVec3f p3 = p1 - ofVec3f(30,-10);  // left point
    
    ofDrawTriangle(p1,p2,p3);
    
    ofPopMatrix();          // restore our drawing space back to normal
    
}
