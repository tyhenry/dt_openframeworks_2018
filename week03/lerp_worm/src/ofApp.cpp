#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    ofSetCircleResolution(100);
    
    // create 10 balls
    
    for (int i=0; i<10; i++){
        
        balls[i].radius = ofMap(i, 0,9, 50, 10);
        // radius based on ball array index (start with largest)
        
        balls[i].lerp   = ofMap(balls[i].radius, 10,50, 0.1,.03);
        // the larger the ball, the slower the interpolation speed
        
        // set color
        balls[i].color.r = ofMap(balls[i].radius, 50,10, 0,255);    // smaller --> redder
        balls[i].color.b = ofMap(balls[i].radius, 10,50, 0,255);    // larger --> bluer
        balls[i].color.g = 0;       // no green

    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    glm::vec2 mouse;
    mouse.x = ofGetMouseX();
    mouse.y = ofGetMouseY();
    
    for (int i=0; i<10; i++){
        
        // move towards the mouse
        
        // interpolate ball pos:
        balls[i].pos += (mouse - balls[i].pos) * balls[i].lerp;
        
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<10; i++){
        
        ofSetColor(balls[i].color);
        ofDrawCircle(balls[i].pos, balls[i].radius);
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
