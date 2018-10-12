#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    for (int y=0; y<10; y++) {
        for (int x=0; x<10; x++) {
            float posY = ofMap(y, 0, 9, 0, ofGetHeight());
            float posX = ofMap(x, 0, 9, 0, ofGetWidth());
            Mover mover(glm::vec2(posX, posY));
            
            movers.push_back(mover);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    glm::vec2 mousePos = glm::vec2( ofGetMouseX(), ofGetMouseY() );
    
    for (int i=0; i<movers.size(); i++){
        
        glm::vec2 diff = mousePos - movers[i].pos;
        
        float distance = glm::length(diff);
    
        
        if (distance != 0 && distance < 100) {
            // calc repulsion

            glm::vec2 norm = diff / distance;
            movers[i].applyForce(-norm);
        }

        else if (distance != 0 && distance < 200) {
            // calc attraction

            glm::vec2 norm = diff / distance;
            movers[i].applyForce(norm);
        }
        
        movers[i].applyElasticForce(0.5);
        movers[i].applyDampingForce(0.2);
        movers[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<movers.size(); i++)
    {
        movers[i].draw();
        //ofDrawBitmapStringHighlight(ofToString(movers[i].elasticForce, 2), movers[i].pos);
    }
    
    ofNoFill();
    ofDrawCircle(mouseX, mouseY, 100);
    ofDrawCircle(mouseX, mouseY, 200);
    ofFill();

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
