#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    
    gravity = glm::vec2(0,0); 	// start with no gravity
	
    ball.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // mouse position alters gravity / wind
    gravity.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), -.3, .3);
    gravity.y = ofMap(ofGetMouseY(), 0, ofGetHeight(), -.3, .3);


    ball.update(gravity);

}

//--------------------------------------------------------------
void ofApp::draw(){

    ball.draw();
    
    // draw some info on screen
    string gravityInfo = "'gravity' force (x,y): " + ofToString(gravity, 2);
    ofDrawBitmapString(gravityInfo, 20, 20);

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
