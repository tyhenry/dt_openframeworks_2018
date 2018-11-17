#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    
    glm::vec2 pos;
    pos.x = ofGetWidth() *0.5;
    pos.y = ofGetHeight() *0.5;

    for (int i=0; i<5000; i++){
        glm::vec2 vel;
        vel.x = ofRandom(-5,5);
        vel.y = ofRandom(-5,5);
        particles.push_back( Particle(pos, vel) );
    }
    
    vectorField = VectorField(50, 50, ofGetWidth(), ofGetHeight());
    
    //vectorField.setFieldRandomly();
    vectorField.setFieldNoisily(0.1);
    
    bDrawField = false;
    bAnimate = false;
    bDrawTrails = false;
    bVectorField = true;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (bAnimate)
        vectorField.setFieldNoisily(0.1);
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].update();
        if (bVectorField)
        {
            glm::vec2 force = vectorField.getForceAtPos(particles[i].pos);
            particles[i].applyForce( force );
            particles[i].applyDrag(0.05);
        }
        
        glm::vec2 pos = particles[i].pos;
        if (pos.x < 0){
            pos.x = ofGetWidth();
        }
        else if (pos.x > ofGetWidth()){
            pos.x = 0;
        }
        if (pos.y < 0){
            pos.y = ofGetHeight();
        }
        else if (pos.y > ofGetHeight()){
            pos.y = 0;
        }
        particles[i].pos = pos;
    }

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    if (bDrawTrails){
        ofPushStyle();
        ofSetColor(0,0,0, 10);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
    }
    
    
    cam.begin();
    ofEnableDepthTest();
    ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    
    for (int i=0; i<particles.size(); i++)
    {
        particles[i].draw();
    }
    
    if (bDrawField){
        vectorField.draw(80);
    }
    
    cam.end();
    ofDisableDepthTest();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' '){
        bDrawField = true;
    }
    else if (key == 'a')
    {
        bAnimate = true;
    }
    else if (key == 't')
    {
        bDrawTrails = true;
        ofSetBackgroundAuto(false);
    }
    else if (key == 'v')
    {
        bVectorField = false;
    }
    

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (key == ' '){
        bDrawField = false;
    }
    else if (key == 'a')
    {
        bAnimate = false;
    }
    else if (key == 't')
    {
        bDrawTrails = false;
        ofSetBackgroundAuto(true);
    }
    else if (key == 'v')
    {
        bVectorField = true;
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
