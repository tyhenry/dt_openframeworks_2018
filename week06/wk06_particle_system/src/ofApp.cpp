#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    glm::vec2 pos = glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
//    glm::vec2 vel = glm::vec2(ofRandom(-.1,.1), ofRandom(-.1,.1));
//    float mass = ofRandom(0,10);
//
//    particle = Particle(pos, vel, mass);

    ofBackground(0);
    gravity = glm::vec2(0, .05);
    
    ParticleSystem particleSystem = ParticleSystem(pos);
    particleSystems.push_back(particleSystem);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<particleSystems.size(); i++){
        particleSystems[i].update(gravity);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<particleSystems.size(); i++){

        particleSystems[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
//    ParticleSystem ps = ParticleSystem(glm::vec2(x,y));
//    particleSystems.push_back(ps);
    
    particleSystems.push_back(ParticleSystem(glm::vec2(x,y)));

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
