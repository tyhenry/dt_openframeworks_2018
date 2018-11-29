#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    //  load vertex and fragment shader:
    
    shader.load("shader.vert", "shader.frag");
        // (note: check your console for errors)
    
    //  generate a plane mesh:
    
    glm::vec2 size   = ofGetWindowSize() * 0.6;
    glm::vec2 res    = size * 0.3;     // mesh resolution
    
    plane.set( size.x, size.y, 100, 100 );
    
    //  rotate the plane:
    plane.rotateDeg(60, -1,0,0);

    
    depth = 50.f;  // used in shader
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
//    plane.rotateDeg(.07, 0,1,0);    // spin plane

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float time = ofGetElapsedTimef();
    
    
    
    cam.begin();
    ofEnableDepthTest();
    
    shader.begin(); // start shader
    
    // send time and depth setting to shader
    shader.setUniform1f("time", time);  // set float value
    shader.setUniform1f("depth", depth);
    
//    plane.drawWireframe();  // render mesh structure
    plane.draw();         // or render solid

    shader.end();
    
    ofDisableDepthTest();
    cam.end();
    
    
    ofDrawBitmapStringHighlight("Arrow up/down to adjust wave depth: " + ofToString(depth), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_UP){
        depth += 1.f;
    }
    else if (key == OF_KEY_DOWN){
        depth -= 1.f;
    }
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
