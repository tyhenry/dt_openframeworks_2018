#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	camW = 640;
	camH = 480;
	
	webcam.setup(camW, camH);
	
	/*
        we are going to copy the red green and blue channels
        from the camera into 3 separate images
	
        allocate 3 ofImages (one for each channel) -
        give width, height, and color format for the pixels
     */
	
	redImg.allocate(camW, camH, OF_IMAGE_COLOR);
	greenImg.allocate(camW, camH, OF_IMAGE_COLOR);
	blueImg.allocate(camW, camH, OF_IMAGE_COLOR);
    
    // now we can write pixel color data into the images

}

//--------------------------------------------------------------
void ofApp::update(){
	
	webcam.update();
	
	if (webcam.isFrameNew())
	{
		// loop through pixels
		for (int y=0; y<webcam.getHeight(); y++) {
			for (int x=0; x<webcam.getWidth(); x++) {
				
				// grab the pixel color at x,y
				ofColor color = webcam.getPixels().getColor(x,y);
                
                // invert the color
                if (bInvert) {
                    color.r = 255-color.r;
                    color.g = 255-color.g;
                    color.b = 255-color.b;
                }
				
				// separate color channels
            
				redImg.setColor(x,y, ofColor(color.r, 0, 0));
				greenImg.setColor(x,y, ofColor(0, color.g, 0));
				blueImg.setColor(x,y, ofColor(0, 0, color.b));
				
			}
		}
		
		// call ofImage update() after you modify pixel data -
        // update() copies pixel data to graphics card (so you can draw())
		
		redImg.update();
		greenImg.update();
		blueImg.update();

	}
	

}

//--------------------------------------------------------------
void ofApp::draw(){
    
	// draw images and rectangles with center as origin
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	// draw using "add" overlay blending effect
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	// spread the RGB images on screen based on mouse
    glm::vec2 center    = ofGetWindowSize() * 0.5;
    glm::vec2 mouse     = glm::vec2(ofGetMouseX(), ofGetMouseY());
    glm::vec2 radius    = mouse - center;
    
    float time = ofGetElapsedTimef();
    spread.x = cos(time) * radius.x * 0.5;
    spread.y = sin(time) * radius.y * 0.5;
	
	redImg.draw(center + spread);       // draw R offset from center
	greenImg.draw(center);              // draw G at center
	blueImg.draw(center - spread);      // draw B -offset from center (opposite mouse)
		
    // return to default alpha blending and rectangle draw mode
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofSetRectMode(OF_RECTMODE_CORNER);
    
    // draw instructions
	stringstream ss;
    ss << "press space key to invert image [" << (bInvert ? "on" : "off") << "]";
	ofDrawBitmapStringHighlight(ss.str(), 20,20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	bInvert = !bInvert;

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
