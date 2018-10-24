//
//  Particle.cpp
//  wk09_vector_field
//
//  Created by Tyler Henry on 10/23/18.
//

#include "Particle.hpp"


Particle::Particle()
{
    pos = glm::vec2(0);
    vel = glm::vec2(0);
    acc = glm::vec2(0);
}

Particle::Particle(glm::vec2 _pos, glm::vec2 _vel)
{
    pos = _pos;
    vel = _vel;
    acc = glm::vec2(0);
}

void Particle::applyForce(glm::vec2 force)
{
    acc += force;
}

void Particle::applyDrag(float strength)
{
    //vel *= 0.9;
    float speed = glm::length(vel);
    if (speed != 0){
        glm::vec2 invertDir = -vel / speed;
        invertDir *= strength;
        applyForce(invertDir);
    }
}

void Particle::update()
{
    vel += acc;
    pos += vel;
    acc *= 0;
}

void Particle::draw()
{
    ofPushStyle();
    
    float rotation = ofRadToDeg(atan2(vel.y, vel.x));
    
    float hue = ofMap(rotation, -180,180, 0, 255, true);
    float sat = ofMap(glm::length(vel), 0, 10, 127.5, 255, true);
    float brt = 255;
    
    ofColor color = ofColor::fromHsb(hue,sat,brt);
    ofSetColor(color);
    ofDrawCircle(pos, 5);
    ofPopStyle();
}





