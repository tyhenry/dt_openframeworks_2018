#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // set up GUI - using addon ofxGui
    
    gui.setup();
    
    // add / setup ofParameters
    // gui.add( parameter.set ( "name", default, min, max ) );
    
    gui.add( drawFaces.set("draw faces", true) );
    gui.add( drawWireframes.set("draw wires", false) );
    gui.add( drawVertices.set("draw vertices", false) );
    gui.add( scale.set("scale", 1.0, 0.0, 3.0) );
    gui.add( pos.set("position", glm::vec3(0), glm::vec3(-200), glm::vec3(200)) );
    
    // add parameters from Plane class
    gui.add( mesh.noiseScale.set("noise scale", glm::vec2(.01), glm::vec2(0.), glm::vec2(.05)));
    gui.add( mesh.noiseFreq.set("frequency", 0.5, 0., 2.));
    gui.add( mesh.noiseAmp.set("amplitude", 40., 0., 100.));
    
    gui.add( mesh.colorNear.set("color near", ofColor::fuchsia, ofColor(0,0), ofColor(255,255,255,255)));
    gui.add( mesh.colorFar.set("color far", ofColor::navy, ofColor(0,0,0,0), ofColor(255,255,255,255)));
    gui.add( mesh.drawOrigin.set("draw origin", false));

    
    // create plane mesh
    mesh.setup(600,600, 100,100);    // width, height, rows, cols
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    mesh.updateNoise();
    mesh.updateColors();
    
    // update mesh parameters from gui
    mesh.setPosition(pos);
    mesh.setScale(scale);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofEnableDepthTest();
    
    if (mesh.drawOrigin) ofDrawAxis(100.f);
    
    if (drawFaces){
        mesh.draw();
    }
    if (drawWireframes){
        mesh.drawWireframe();
    }
    if (drawVertices){
        mesh.drawVertices();
    }
    
    ofDisableDepthTest();
    
    cam.end();
    
    gui.draw();
    
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
