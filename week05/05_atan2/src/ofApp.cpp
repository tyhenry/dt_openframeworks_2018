#include "ofApp.h"

//--------------------------------------------------------------
// end Arrow class definitions


// begin ofApp definitions
//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    glm::vec2 target = glm::vec2(ofGetMouseX(),ofGetMouseY());
    arrow.update(target);	// set target to mouse pos
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
    
	arrow.draw();
	
	
	// draw axes
	
	ofVec3f mousePos = ofVec3f(ofGetMouseX(), ofGetMouseY());
	
	ofSetColor(ofColor::red);
    ofDrawLine( arrow.pos, glm::vec2(ofGetWidth(), arrow.pos.y));	// x-axis
	
	ofSetColor(ofColor::green);
    ofDrawLine( arrow.pos, glm::vec2(arrow.pos.x, ofGetHeight()));  // y-axis (points down!)
	
	// draw arrow vector
	
	ofSetColor(ofColor::lightBlue);
    ofDrawLine(mousePos.x, mousePos.y, arrow.pos.x, arrow.pos.y);   // draw direction line
	
	// angle arc
	
	ofPolyline arc;
	arc.arc(arrow.pos.x, arrow.pos.y, 75, 75, 0, arrow.angle);
    // make an arc:
    // ofPolyline::arc(x, y, radius x, radius y, angle begin, angle end)
    // https://openframeworks.cc/documentation/graphics/ofPolyline/#show_arc
	
    arc.draw();
	
	// angle labels
	
	float angle360 = arrow.angle;
	if (angle360 < 0) angle360 = 360 + angle360; // shift negative degrees to 0-360 range
	
	string degLbl = ofToString(angle360, 1) + " degrees";
	string radLbl = ofToString(ofDegToRad(angle360) / PI, 2) + " PI radians";
	
    ofDrawBitmapString( degLbl, arrow.pos + glm::vec2(75, 75));
    ofDrawBitmapString( radLbl, arrow.pos + glm::vec2(75, 90));
	
	ofSetColor(255);
}




