#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	sphere = ofSpherePrimitive(200, 20);    // radius, resolution
	
    // store the original mesh faces before we modify them
    
    // our sphere mesh is made of triangles
	triangles = sphere.getMesh().getUniqueFaces();
    modTriangles = triangles;
    
    sphere.rotateDeg(30, glm::vec3(1,0,0));

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// sin wave offsets faces
	float offset = ofMap( sin(ofGetElapsedTimef() * 0.5), -1, 1, 0, 500);
	
	// expand faces
	for(int i = 0; i < triangles.size(); i++ ) {
		
        // the "normal" of a triangle is a vector pointing away from its face
        glm::vec3 faceNormal  = triangles[i].getFaceNormal();    // unit vector / length 1
        
        // set color per face
        float hue            = ofMap(i, 0, triangles.size(), 0, 255);
        ofColor color        = ofColor::fromHsb(hue, 255, 255);
		
        // modify mesh triangle vertex position and color
		for(int j = 0; j < 3; j++ ) {
            
            glm::vec3 newPos = triangles[i].getVertex(j) - faceNormal * offset;
			modTriangles[i].setVertex(j, newPos);
			modTriangles[i].setColor(j, color);
		}
	}
	
	sphere.getMesh().setFromTriangles( modTriangles );
    
    // rotate sphere as a whole
    sphere.rotateDeg(0.1, glm::vec3(0,1,0));
    sphere.rotateDeg(0.01, glm::vec3(0,0,1));

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	cam.begin();
	ofEnableDepthTest();
	
	ofDrawAxis(100);
	
	sphere.draw();
    
	ofDisableDepthTest();
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
