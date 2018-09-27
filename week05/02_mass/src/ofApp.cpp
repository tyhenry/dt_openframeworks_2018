#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	glm::vec2 center = glm::vec2(ofGetWidth()*.5, ofGetHeight()*.5);

	// init ball vector
	
	const int nBalls = 10;

	for (int i=0; i<nBalls; i++)
	{
        // mass adds "weight" to the balls
        // mass will "resist" force on the ball, adding "inertia"
        
		float mass = ofMap(i,0,nBalls,10,1);    // map mass to ball's index in the vector container
        Ball ball;
        ball.setup(center, mass);
		
        ball.vel = glm::vec2(ofRandom(2), ofRandom(2)); // random starting velocity
		
		balls.push_back(ball);  // add this ball to the vector
	}
	

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// update wind with noise, so it changes smoothly but randomly over time
	
    // ofSignedNoise() will give a number between -1 and 1
    // (ofNoise() gives a number between 0 and 1 - they're otherwise the same)
	wind.x = ofSignedNoise(ofGetElapsedTimef() * .1) * .1;
	wind.y = ofSignedNoise(ofGetElapsedTimef() * .1 + 10000) * .1;	// shift time so wind x and y differ
	
	// apply forces to balls
	
	for (int b = 0; b < balls.size(); b++)
	{

		// apply wind
		
		balls[b].applyForce( wind );
	
		// check walls
		
		ofRectangle walls = ofRectangle( 0,0, ofGetWidth(),ofGetHeight() );
		balls[b].checkWalls(walls);
		
		// apply acceleration
		
		balls[b].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::grey, ofColor::black);
	// gradient backgrounds should be first function of draw()

    for (int i=0; i<balls.size(); i++){
		// alternative vector loop format
		
		balls[i].draw();
	}
	
	// draw wind vector
	
    glm::vec2 center = glm::vec2(ofGetWidth()*.5, ofGetHeight()*.5);
	ofDrawCircle( center, 5);
	ofDrawLine( center, center + wind * 1000);  // scale up the wind vector so its visible

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
