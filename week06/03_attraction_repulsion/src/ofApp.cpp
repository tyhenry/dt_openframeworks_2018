#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
    // make a grid of "mover" objects
    
	for (int y=0; y< ofGetHeight(); y+=20){         // space the "movers" 20 pixels apart
		for (int x=0; x< ofGetWidth(); x+=20){
			
            // make Mover with position on grid, random mass
            Mover mover = Mover(glm::vec2(x,y), ofRandom(1,5));
			movers.push_back(mover);
			
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	
	glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
	
	for (int i=0; i<movers.size(); i++){
	
		glm::vec2 attraction, repulsion;
		
		glm::vec2 dir = mousePos - movers[i].pos;
		
        float distance = glm::length(dir);
		
        if (distance > 0) {         // avoid dividing by 0!
            
            glm::vec2 normalizedDir = dir / distance;      // normalize to get length to 1
            
            if (distance < 100) {           // repulsion
                
                repulsion = -normalizedDir;
                
            } else if ( distance < 200) {    // attraction
                
                attraction = normalizedDir;
            }
        }
		
		movers[i].applyForce(attraction);
		movers[i].applyForce(repulsion);
		movers[i].applyDampingForce(0.05);
		movers[i].update();
		
		movers[i].bounceWindowEdges();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (int i=0; i<movers.size(); i++){
		movers[i].draw();
	}

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
