//
//  Ball.cpp
//  01_vector_of_balls
//


#include "Ball.hpp"


void Ball::setup(glm::vec2 position, float size, float bounce){
    
    // init ball variables
    
    pos             = position;
    radius          = size;
    bounceFactor    = bounce;
    
    vel = glm::vec2(0,0);   // no velocity yet
    acc = glm::vec2(0,0);   // no acceleration yet
    
    // set color from bounciness:
    
    ofColor color1 = ofColor(80,40,175);        // purple
    ofColor color2 = ofColor(255,10,220);       // pink
    color = color1.lerp(color2, bounceFactor);  // bounceFactor is 0-1, like a percent
    
}

void Ball::update(){
    
    // move
    
    vel += acc;     // apply acceleration
    pos += vel;     // apply velocity
    
    acc *= 0;       // clear acceleration after!
    
}

void Ball::draw(){
    
    ofSetColor(color);      // set custom color
    ofDrawCircle(pos, radius);
    ofSetColor(255);        // restore global white color
}

// utility functions:

void Ball::setVelocity(glm::vec2 velocity){
    vel = velocity;
}

void Ball::addForce(glm::vec2 force){
    acc += force;       // add acceleration force
}

// bounce the ball off walls inside a box:

void Ball::bounce(float wallLeft, float wallRight, float wallTop, float wallBottom){
    
    if (pos.x < wallLeft + radius){         // too far left, out of bounds!
        
        pos.x = wallLeft + radius;          // reset position to edge
        
        // bounce
        vel.x *= -bounceFactor;               // bounceFactor is number 0.0 - 1.0
                                                // < 1.0 slows ball on bounce
                                                // 1.0 is perfect bounce
                                            // - sign flips direction
    }
    else if (pos.x > wallRight - radius){   // right side bounce
        
        pos.x = wallRight - radius;
        vel.x *= -bounceFactor;
    }
    
    if (pos.y < wallTop + radius){      // top and bottom bounces
        pos.y = wallTop + radius;
        vel.y *= -bounceFactor;
        
    } else if (pos.y > wallBottom - radius){
        pos.y = wallBottom - radius;
        vel.y *= -bounceFactor;
    }
    
}

