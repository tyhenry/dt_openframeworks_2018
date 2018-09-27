#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	amplitude = 300; // this will be the range of our oscillations (-300 to 300)
	
    sinOscillator = glm::vec2(0, -amplitude);
    cosOscillator = glm::vec2(-amplitude, 0);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time = ofGetElapsedTimef();
	
    // map oscillation frequency to mouse position
	sinFrequency = ofMap(ofGetMouseX(), 0, ofGetWidth(), 1., 3.);
	cosFrequency = ofMap(ofGetMouseY(), 0, ofGetHeight(), 1., 3.);
	
    // calculate oscillations
	float sinTime = sin(time * sinFrequency) * amplitude;
	float cosTime = cos(time * cosFrequency) * amplitude;
	

    sinOscillator   = glm::vec2(-amplitude, sinTime);	// sin oscillates on y
    cosOscillator	= glm::vec2(cosTime, -amplitude);	// cos oscillates on y
	
    mixOscillator   = glm::vec2(cosTime, sinTime);      // circular oscillation
	
    // make a trail using ofPolyline
    // https://openframeworks.cc/documentation/graphics/ofPolyline/
    
    mixTrail.addVertex(mixOscillator.x, mixOscillator.y);
    
	if (mixTrail.getVertices().size() > 5000) {
		mixTrail.clear(); // reset
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    // print instructions on screen:
    string message = " press mouse button to draw lines";
    message += "\n\n move mouse to change oscillation frequencies";
    message += "\n cos frequency (X oscillation): " + ofToString(cosFrequency);
    message += "\n sin frequency (Y oscillation): " + ofToString(sinFrequency);
    ofDrawBitmapString(message, 20, 20);
    
    
	
    // now, move our drawing "origin" (0,0) from the top right of the window
    // to center of window temporarily:
	ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5);
	
    // draw the trail:
	ofSetColor(ofColor::purple);
	ofSetLineWidth(5);
	mixTrail.draw();
	
    // draw the oscillators:
	ofSetColor(ofColor::red);
	ofDrawCircle(sinOscillator, 5);
	
	ofSetColor(ofColor::blue);
	ofDrawCircle(cosOscillator, 5);
    
    ofSetColor(255);
    ofDrawCircle(mixOscillator, 5);
    
	
    // draw lines between the oscillators and the circle if mouse is pressed:
	if (ofGetMousePressed())
	{
		ofSetLineWidth(2);
		
		ofSetColor(ofColor::red);
		ofDrawLine(mixOscillator, sinOscillator);
		
		ofSetColor(ofColor::blue);
		ofDrawLine(mixOscillator, cosOscillator);
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
	
	mixTrail.clear();

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
