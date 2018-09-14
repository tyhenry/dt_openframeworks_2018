#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetCircleResolution(100);     // prettier circles
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // make a ball follow the mouse --
    // and slow down when it gets closer

    // we use "interpolation" -- "lerp" for short:
    // it means we move just a percentage of the way between two points
    // -- this creates a slowing or "easing" effect
    
    
    glm::vec2 destination;                  // mouse is destination point
    destination.x   = ofGetMouseX();
    destination.y   = ofGetMouseY();
    
    float percent   = .05;                  // we'll move the ball 5% closer to mouse
    
    // "interpolation" equation:

    glm::vec2 diff = destination - pos;     // calc vector from current position
                                            // to mouse (destination)
    
    pos += percent * diff;                  // move 5% of that
    

    
    // style the ball with brightness and size
        
    float dist = glm::distance(destination,pos);      // distance to mouse
    
    // as distance increases, brightness increases:
    brightness = ofMap(dist, 0, 500, 100, 200);

    // as distance increases, size decreases:
    radius = ofMap(dist, 0, 500, 30, 10);
    
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
