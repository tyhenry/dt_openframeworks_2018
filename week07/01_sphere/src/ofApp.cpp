#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    glm::vec2 centerScreen = ofGetWindowSize() * 0.5;
    
    spherePos   = glm::vec3( centerScreen, 0.0 );
    radius      = 300.0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    spherePos.x += ofSignedNoise( time ) * 20.0;
    spherePos.y += ofSignedNoise( time + 100.0 ) * 20.0;
    spherePos.z -= 1.;                                          // move "into" screen
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawSphere(spherePos, radius);
    
    ofDrawBitmapStringHighlight("press space to toggle wireframe", 20, 20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        ofNoFill();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == ' '){
        ofFill();
    }
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
