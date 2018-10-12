//
//  Mover.cpp
//  w06-attraction-repulsion
//
//  Created by Tyler Henry on 10/9/18.
//

#include "Mover.hpp"


Mover::Mover()
{
    
    origPos = glm::vec2(0,0);
    pos = glm::vec2(0,0);
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    mass = 5;
}

Mover::Mover(glm::vec2 _pos)
{
    
    origPos = _pos;
    pos = origPos;
    vel = glm::vec2(0,0);
    acc = glm::vec2(0,0);
    
    mass = 5;
}

void Mover::applyForce(glm::vec2 force)
{
    acc += force / mass;
}

void Mover::applyDampingForce(float strength)
{
    float speed = glm::length(vel);
    if (speed != 0){
        glm::vec2 dir = vel / speed;
        applyForce( -dir * strength );
    }
}

void Mover::applyElasticForce(float strength)
{
    glm::vec2 diff = origPos - pos;
    float length = glm::length(diff);
    if (length != 0){
        glm::vec2 dir = diff / length;
        elasticForce = dir * strength;
        applyForce( elasticForce );

    }
    
    
}

void Mover::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Mover::draw()
{
    ofPushStyle();
    
    // let's color each mover based on its current speed
    // interpolate ("lerp") between 2 colors (slow to fast -> blue to red)
    float speed     = glm::length( vel );
    float percent   = ofMap(speed, 0, 5, 0.0, 1.0);    // map 0.0 - 5.0 speed to 0.0 - 1.0 percent
    ofColor blue    = ofColor(0,0,255);
    ofColor red     = ofColor(255,0,0);
    ofColor color   = blue.lerp(red, percent);   // lerp from blue to red
    
    ofSetColor(color);
    
    ofDrawCircle(pos, mass * 2.0);      // base radius on mass
    
    ofPopStyle();
}
