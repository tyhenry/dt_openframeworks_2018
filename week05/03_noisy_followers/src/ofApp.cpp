#include "ofApp.h"

//--------------------------------------------------------------
// ofApp definitions:
//--------------------------------------------------------------

void ofApp::setup(){
	
	ofBackground(0);
	
	int numArrows = 100;
	
	for (int i=0; i<numArrows; i++){
        
        // make new arrow
		
		Arrow arrow;
		
        arrow.pos   = glm::vec3(0,0,0);
		arrow.speed = ofMap(i, 0,numArrows, .008, .04);	    // set interpolation "speed", slow to fast
		arrow.size  = ofMap(i, 0,numArrows, 5, 1);		    // set size, large to small
		
		float hue   = ofMap(i, 0, numArrows, 155, 255);     // blue to red
		arrow.color = ofColor::fromHsb(hue, 255, 255);	    // hue, saturation, brightness
		
		arrows.push_back(arrow);
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
    // mouse is target
    
    glm::vec3 target = glm::vec3(ofGetMouseX(), ofGetMouseY(), 0);
	
    
    // make each arrow follow it's own "noisy" target (target + arrow noise)
	
	for (auto& arrow : arrows){             // alternative syntax for looping through vector
		
        
        // add some noise to the target, unique for each arrow
        
        glm::vec3 noise;
        float frequency     = 10. * arrow.speed;   // noise frequency / speed based on arrow's speed
        float amplitude     = 400.;                // noise amplitude / range will be -400 to 400
        
        // signed noise has range -1 to 1

		noise.x = ofSignedNoise(ofGetElapsedTimef() * frequency) * amplitude;
		noise.y = ofSignedNoise((ofGetElapsedTimef()+1000) * frequency) * amplitude;
		
        glm::vec3 noisyTarget = target + noise;
		
		arrow.follow(noisyTarget);
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	for (auto& arrow : arrows) {
		
		arrow.draw();
		
		if (ofGetMousePressed()){
			ofSetColor(arrow.color);
            ofDrawLine(arrow.pos, glm::vec2(ofGetMouseX(), ofGetMouseY()));
		}
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
