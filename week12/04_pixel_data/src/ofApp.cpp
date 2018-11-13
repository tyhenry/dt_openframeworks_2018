#include "ofApp.h"

// we're going to create an image from scratch to see how it's done!

const int width     = 100;		// 100 pixels width
const int height    = 100;		// 100 pixels height
const int nChannels = 4;	    // RGBA color

const int nBytes    = width * height * nChannels;   // raw pixel data, stored in bytes

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
	
	// manually allocate a pixel array

	/*
	 to allocate pixels using ofPixels we would write:
	 
	 ofPixels pixels;
	 pixels.allocate(100,100,OF_IMAGE_COLOR_ALPHA);
     */
    

	// allocate a pixel array of raw bytes
    // (byte = unsigned char = integer from 0 to 255)
	pixelData = new unsigned char[ nBytes ];		// new byte array with "nBytes" # of elements
	
	// print some info on our array:
	
	ofLogNotice() << endl
		<< "allocated pixel array of size: " << nBytes << " bytes" << endl
		<< width << "x" << height <<" * " << nChannels << " channels";
	
	


	
	// let's track these pixels using an ofImage
	// the ofImage will store a pointer to our custom pixels
	
	img.getPixels().setFromExternalPixels(pixelData, width, height, nChannels);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// update our pixels with noise colors over time
	
	float time = ofGetElapsedTimef() * .1;
    
    for (int i=0; i<nBytes; i+=nChannels)        // 4 bytes/4 channels per pixel - RGBA
    {
        int x = (i/nChannels) % width;            // pixel x
        int y = (i/nChannels) / width;            // pixel y
        
        glm::vec2 noisePos       = glm::vec2(x,y) * 0.01f;
        
        pixelData[i]        = ofNoise(noisePos + glm::vec3(time)) * 255;        // red      - 1st byte/channel
        pixelData[i+1]      = ofNoise(noisePos + glm::vec3(time + 10)) * 255;   // green    - 2nd byte/channel
        pixelData[i+2]      = ofNoise(noisePos + glm::vec3(time + 20)) * 255;   // blue     - 3rd byte/channel
        pixelData[i+3]      = ofNoise(noisePos + glm::vec3(time + 30)) * 255;   // alpha    - 4th byte/channel
    }
	
	img.update();		// update the image texture with the new pixel values


}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	ofPushMatrix();
	ofPushStyle();
	
	float fitScale = ofGetWidth() / (width * 2.);
    ofScale(glm::vec3(fitScale));		// scale to fit images side by side
	
	// manually draw the pixels:
	
	for (int i=0; i<nBytes; i+=4)		// 4 == numChannels
	{
		// read color at this pixel
		
		ofColor color;
		color.r = pixelData[i];		// offset pointer by i, get value
		color.g = pixelData[i+1];	// offset by i+1
		color.b = pixelData[i+2];
		color.a = pixelData[i+3];
		
		// calculate the x,y position at this byte
		int x = (i/4) % width;
		int y = (i/4) / width;
		
		// draw the pixel as a box
		ofSetColor(color);
		ofDrawRectangle(x,y,1,1);
		
	}
	ofSetColor(255);
	

	// or auto-draw the pixels using the image texture:
	
	img.draw(width, 0, width, height);
	
	ofPopStyle();
	ofPopMatrix();	// end scaling
	
	

	// add labels
	
	stringstream pixLabel;
    pixLabel
        << "pixel data: " << width << "w x " << height << "h * " << nChannels << " channels" << endl
        << nBytes << " bytes (memory address: " << (void*)pixelData << ")" << endl << endl
        << "scaled to " << width * fitScale << " x " << height * fitScale << endl;
	ofDrawBitmapString(pixLabel.str(),20,height*fitScale+20);   // draw text at bottom of scaled image
	
	stringstream texLabel;
	texLabel
        << "texture " << endl << "(pixels -> GPU)" << endl << endl
        << "scaled to " << width * fitScale << " x " << height * fitScale << endl;
	ofDrawBitmapString(texLabel.str(),width*fitScale+20, height*fitScale+20);
	
	

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	// invert colors when key is pressed
	
//	for (int i=0; i<pix)

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
