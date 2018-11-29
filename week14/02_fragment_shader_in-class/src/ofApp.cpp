#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(100);
    
    // setup webcam:
    webcam.setup(640,480);
    
    // setup 'quad' mesh:
    quad.set(640, 480, 2, 2);       // 4 (2x2) vertices
    quad.mapTexCoordsFromTexture(webcam.getTexture()); // map webcam texture coordinates

    
    // load the shader (vertex and fragment files)
    shader.load("shader.vert", "shader.frag");
    
    
    // allocate an `fbo` - offscreen drawing canvas
    fbo.allocate(640,480, GL_RGBA);     // 4 channel color (RGBA)
    fbo.begin();
    ofClear(0,0,0,255);     // set all pixels opaque black
    fbo.end();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    webcam.update();
    
    quad.rotateDeg(0.05, 0,1,0);   // spin 3D quad mesh
    
    
    // draw mouse into our off-screen 'fbo' canvas
    
    fbo.begin();
    
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    ofDrawCircle(mousePos, 20);
    
    fbo.end();
    
    // ------ (you can draw into an fbo anywhere (update or draw))

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    fbo.draw(0,0);    // draw the current mouse canvas on screen

    
    // draw 3D quad using camera:
    
    
    cam.begin();
    ofEnableDepthTest();
    
    // draw mask shader on the quad surface:
    
    shader.begin();
    
    //  set shader inputs ('uniforms')
    shader.setUniformTexture("tex0", webcam.getTexture(), 0);
    shader.setUniformTexture("texMask", fbo.getTexture(), 1);
    
    quad.draw();        // draw shader on quad surface
    
    shader.end();
    
    
    ofDisableDepthTest();
    
    
//    quad.drawWireframe();     // draw the quad structure

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
