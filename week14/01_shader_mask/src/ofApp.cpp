#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    
    image.load("image.jpg");    // image
    mask.load("mask.jpg");      // mask (should be same size!)
    
    plane.set(960,960,2,2);   // 2x2 grid ('quad') mesh
    
    // we'll draw the image on the mesh:
    
    plane.mapTexCoordsFromTexture(image.getTexture());

    
    // load the shader code files (see in bin/data/shaders/)

    maskShader.load("shaders/mask.vert", "shaders/mask.frag");
    
    //  'vert' = vertex shader (sets render geometry)
    //  'frag' = fragment shader (sets pixel color)
    
    //  we mainly use 'mask.frag' to alter color
    //    'mask.vert' is just a template vertex shader

}

//--------------------------------------------------------------
void ofApp::update(){
    
    plane.rotateDeg(.1, 0,1,0); // rotate plane around Y
    
    
    // map mouse to texture coordinates
    
    glm::vec2 mouse    = glm::vec2(ofGetMouseX(), ofGetMouseY());
    glm::vec2 center   = ofGetWindowSize() * .5;
    
    // offset the mask by mouse distance from center
    maskOffset = center - mouse;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw image with mask
    cam.begin();
    ofEnableDepthTest();
    
    // * start shader *
    maskShader.begin();
    // * set shader inputs *
    maskShader.setUniformTexture("tex0", image, 0);
    maskShader.setUniformTexture("texMask", mask, 1);
    maskShader.setUniform2f("maskOffset", maskOffset);
    // * draw something! *
    plane.draw();
    // * done *
    maskShader.end();
    
    ofDisableDepthTest();
    
    ofSetColor(50,127);
    plane.drawWireframe();

    cam.end();

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
