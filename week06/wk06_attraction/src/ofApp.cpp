#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    glm::vec2 centerScreen =
        glm::vec2(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
    particle1.mass = 10.0;
    particle1.pos  = centerScreen;
    particle2.mass = 15.0;
    particle2.pos  = centerScreen;

}

//--------------------------------------------------------------
void ofApp::update(){

    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    
    glm::vec2 diff1 = mousePos - particle1.pos;
    glm::vec2 diff2 = mousePos - particle2.pos;
    
    particle1.addForce(diff1 * 0.01);
    particle2.addForce(diff2 * 0.01);
    
    particle1.addDampingForce(0.1);
    particle2.addDampingForce(0.1);
    
    cout << particle1.pos << endl;
    
    particle1.update();
    particle2.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    particle1.draw();
    particle2.draw();

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
