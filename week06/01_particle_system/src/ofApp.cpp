#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // create one particle system at center screen -- see ParticleSystem.cpp + ParticleSystem.hpp

    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);     // center screen
    ParticleSystem particleSystem = ParticleSystem(pos);
    
    particleSystems.push_back(particleSystem);
    
    // setup general gravity force
    
    gravity = glm::vec2(0, .15);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].applyForce(gravity);
        particleSystems[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    // create a new particle system at mouse position on click
    
    particleSystems.push_back( ParticleSystem(glm::vec2(x,y)) );

}
