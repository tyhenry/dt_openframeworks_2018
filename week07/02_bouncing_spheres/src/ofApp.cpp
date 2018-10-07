#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetFrameRate(60.f);
	ofBackground(0);
	
	// make the spheres
	
	const int nSpheres = 100;
	
	for (int i=0; i<nSpheres; i++)
	{
        
        // random velocity
        glm::vec3 velocity;
        velocity.x  = ofRandom(-5,5);
        velocity.y  = ofRandom(-5,5);
        velocity.z  = ofRandom(-5,5);

        // radius based on speed of velocity
        float radius    = ofMap(glm::length(velocity), 0, 10, 20, 3);
        
        glm::vec3 pos   = glm::vec3(0,0,0); // start at 0,0,0
        
        Sphere sphere = Sphere(pos, radius);
        sphere.setVelocity(velocity);
        
		spheres.push_back(sphere);
	}
    
    // define the box containing spheres
    
    box = Box(glm::vec3(0,0,0), ofGetHeight());     // cube with size == height of window
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (int i=0; i<spheres.size(); i++)
	{
		spheres[i].update();
        spheres[i].bounceWalls(box.getLeft(), box.getRight(), box.getTop(), box.getBottom(), box.getFront(), box.getBack());
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	camera.begin();
	ofEnableDepthTest();
	
	ofFill();
	for (int i=0; i<spheres.size(); i++)
	{
		spheres[i].draw();
	}
	
	ofNoFill();
	
    box.draw();
	ofDrawAxis( 100 );
	
	ofDisableDepthTest();
	camera.end();
    
    string info = "click and drag left button to rotate camera\n";
    info += "click and drag right button (or scroll wheel) to zoom";
    ofDrawBitmapStringHighlight(info, 20,20);
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
