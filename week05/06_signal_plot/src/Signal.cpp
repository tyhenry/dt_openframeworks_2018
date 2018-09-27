//
//  Signal.cpp
//  06_signal_plot
//
//  Created by Tyler Henry on 9/26/18.
//

#include "Signal.hpp"

void Signal::setup(){
    pos     = glm::vec2(0,0);
    prevPos = pos;
    color   = ofColor(255);
}

void Signal::update(float x, float y)
{
    prevPos = pos;
    pos     = glm::vec2(x,y);
}

void Signal::draw() {
    
    ofPushStyle();        // store current "style" settings (global draw color, etc.)
    ofSetColor(color);    // set global color to signal color
    
    ofDrawLine(prevPos.x, prevPos.y, pos.x, pos.y);
    ofPopStyle();        // restore old "style" settings
    
}

void Signal::resetPos(float x, float y)
{
    pos = glm::vec2(x,y);
    prevPos = pos;
}
