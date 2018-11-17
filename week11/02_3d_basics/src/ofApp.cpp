#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // easy sphere
    
    sphere = ofSpherePrimitive(1000, 50);
    // 1000 = radius, 50 = level of detail
    
    sphere.setPosition(0, 0, 0);
    
    
    // make a triangle mesh from 3 points
    
    glm::vec3 pt0 = glm::vec3( 0, 250, 0 );     // center, top
    glm::vec3 pt1 = glm::vec3( 289, -250, 0);   // right, bottom
    glm::vec3 pt2 = glm::vec3( -289, -250, 0);  // left, bottom
    
    // triangle is an ofMesh which can make triangle geometry:
    
    triangle.addVertex(pt0);
    triangle.addColor(ofColor::red);    // vertex 0 red
    
    triangle.addVertex(pt2);
    triangle.addColor(ofColor::green);  // vertex 1 green
    
    triangle.addVertex(pt1);
    triangle.addColor(ofColor::blue);   // vertex 2 blue
    
    // add 3 vertex indices in a row to connect the triangle:
    
    triangle.addIndex(0);
    triangle.addIndex(1);
    triangle.addIndex(2);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // rotate sphere around an axis
    //float time = ofGetElapsedTimef() * .01;
    sphere.rotateDeg( .05, glm::vec3(1,-1,0) );
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofEnableDepthTest();
    
    // draw background sphere, in wireframe
    
    ofSetColor(ofColor::purple);
    sphere.drawWireframe();

    triangle.draw();
    
    ofDisableDepthTest();
    cam.end();
    
    // instructions:
    ofDrawBitmapStringHighlight("drag / scroll mouse to control camera", 20, ofGetHeight()-20);
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
