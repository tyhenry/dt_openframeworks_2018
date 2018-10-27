#include "Ball.h"

// --------------------------------------------------------
void Ball::setup(glm::vec2 _pos, float _radius){
    
    pos = _pos;
    radius = _radius;
    
}

// --------------------------------------------------------
void Ball::update(){
    
    pos += vel;
    
    // bounce:
    
    if(pos.x > ofGetWidth()){
        
        pos.x = ofGetWidth();
        vel.x *= -1;
        
    }
    else if (pos.x < 0){

        pos.x = 0;
        vel.x *= -1;
    }
    
    
    if(pos.y > ofGetHeight()){

        pos.y = ofGetHeight();
        vel.y *= -1;
    }
    else if (pos.y < 0){

        pos.y = 0;
        vel.y *= -1;
    }

}

// --------------------------------------------------------
void Ball::draw(){
    ofDrawCircle(pos, radius);
}
