#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
    vid.load("/Users/tyler/Documents/of_v0.10.0_osx_release/dt_openframeworks_2018/week12/05_glitch/bin/data/video.mp4");
	vidShift.allocate(vid.getWidth(), vid.getHeight(), OF_IMAGE_COLOR);
    
    vid.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time = ofGetElapsedTimef();
	
	vid.update();
	if (vid.isFrameNew())
	{
        float time          = ofGetElapsedTimef();
        glm::vec2 mouse     = glm::vec2(ofGetMouseX(), ofGetMouseY());
        glm::vec2 mouseNorm = mouse / ofGetWindowSize();    // normalized 0-1
        glm::vec2 vidSize   = glm::vec2(vid.getWidth(), vid.getHeight());
		
        // loop through video frame's pixels
		for (int y=0; y < vidSize.y; y++){
			for (int x=0; x < vidSize.x; x++){
                
                glm::vec2 pos       = glm::vec2(x,y) / vidSize;     // normalize pos
                
                ofColor color       = vid.getPixels().getColor(x,y);
                
                float brightness    = color.getLightness() / 255;   // normalize 0-1
				
                // calc amount to move the pixel
                
                glm::vec2 offset;
                
                offset.x    = cos(time) * mouseNorm.x * brightness * 200;
                offset.y    = sin(time) * mouseNorm.y * brightness * 200;
				
                int newX = int(x + offset.x) % int(vid.getWidth());
                int newY = int(y + offset.y) % int(vid.getHeight());
				
				vidShift.setColor(newX, newY, color);
			}
		}
		vidShift.update();
	}
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	vidShift.draw(0,0, ofGetWidth(), ofGetHeight());

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
