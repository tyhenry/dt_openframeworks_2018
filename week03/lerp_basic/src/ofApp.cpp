#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetCircleResolution(100);     // prettier circles
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // make a ball follow the mouse --


    // interpolation - move between two points:
    // current 1-------->---------2 destination
    
    glm::vec2 dest;     // mouse is destination point (#2)
    dest.x = ofGetMouseX();
    dest.y = ofGetMouseY();
    
    float pct = .05;    // move ball 5% closer to mouse
    
    // "interpolation" equation:

    pos += pct * (dest - pos);  // move a bit closer
    


    // style the ball 
        
    float dist = glm::distance(mouse,pos);      // get distance to mouse
    
    // as distance increases, brightness increases:
    brightness = ofMap(dist, 0, 500, 50, 255);

    // as distance increases, size decreases:
    radius = ofMap(dist, 0, 500, 50, 1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(brightness);
    ofDrawCircle(pos, radius);

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
