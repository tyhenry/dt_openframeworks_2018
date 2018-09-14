#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
    ofSetCircleResolution(100);
    
    gravity = glm::vec2(0,0); 	        // start with no gravity
	
    for (int i=0; i<numBalls; i++){                 // numBalls defined in ofApp.h
        
        float radius = ofMap(i, 0, numBalls, 50, 5);
        float bounce = ofMap(radius, 5, 50, 0.9, 0.3);    // assign a bounciness factor (0-1 max range)
        
        balls[i].setup(radius, bounce);                    // initialize
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // mouse position alters gravity / wind
    gravity.x = ofMap(ofGetMouseX(), 0, ofGetWidth(), -.3, .3);
    gravity.y = ofMap(ofGetMouseY(), 0, ofGetHeight(), -.3, .3);

    for (int i=0; i<numBalls; i++){
        balls[i].update(gravity);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int i=0; i<numBalls; i++){
        balls[i].draw();
    }
    
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
