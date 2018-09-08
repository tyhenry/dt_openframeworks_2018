#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);    // set background black

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    // circle
    
    ofSetColor(255,0,0);        // set drawing color red
    ofDrawCircle(200,100, 50);      // x,y: 200,100     circle radius: 50
    
    // rectangle
    
    ofSetColor(0,255,0);        // green
    ofDrawRectangle(200,300, 200,400);      // x,y: 100,300    width,height: 200,400
    
    // triangle
    
    ofSetColor(0,0,255);        // blue

    ofDrawTriangle(600,100, 700,200, 500,200);       // point1 x,y   point2 x,y     point3 x,y
    
    // simple text
    
    ofColor purple = ofColor(255,0,255);       // another way to create colors
    ofSetColor(purple);
    ofDrawBitmapString("hello world!", ofGetWidth() * 0.5, ofGetHeight() - 100);
        // center and bottom
    

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
