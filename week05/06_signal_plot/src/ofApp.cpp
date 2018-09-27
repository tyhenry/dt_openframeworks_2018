#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetBackgroundAuto(false); // dont clear background
	
	ofBackground(0);
	
	xPos            = 100;
    lastFrameTime   = ofGetElapsedTimef();

	
	sineSignal.color	        = ofColor::cyan;
	sineHighFreqSignal.color	= ofColor::magenta;
	amSignal.color		        = ofColor::magenta;
	fmSignal.color		        = ofColor::magenta;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	float time	= ofGetElapsedTimef();			// get time in seconds
	
	xPos += (time - lastFrameTime) * 60.;		// move 60 pixels horizontally per second
	lastFrameTime = time;
    
    if (xPos > ofGetWidth()){   //  if signal plots have gone off-screen...
        
        ofClear(0); // clear background
        
        xPos = 100; // reset x position
        
        sineSignal.resetPos(xPos, sineSignal.pos.y);        // reset x pos, keep y pos
        sineHighFreqSignal.resetPos(xPos, sineHighFreqSignal.pos.y);
        
        amSignal.resetPos(xPos, amSignal.pos.y);
        fmSignal.resetPos(xPos, fmSignal.pos.y);
        
    }
	
	
	// plot signals
    
    
    float range = 50;       // the y-amplitude range in pixels of the signals
	
	
	// -- sin
	
	float sinTime	        = sin (time);	    // sin of time
	
	sineSignal.update(xPos, sinTime * range);	// -50 to 50 range
	
	
	// -- high-freq sin
	
	float sinHighFreqTime	= sin (time * 20.);		// higher frequency (20 x) sin of time
	
	sineHighFreqSignal.update(xPos, sinHighFreqTime * range);
	
	
    
	// -- amplitude modulated signal
	
	float amSin    = sin (time * 20.) * sinTime;
    // modulate HF sin wave amplitude by sin of time
	
	amSignal.update(xPos, amSin * range);
	
	
    
	// -- frequency modulated signal
	
	float fmSin	= sin ( sinTime * 20. );
    // modulate frequency by sin of time
	
	fmSignal.update(xPos, fmSin * range);
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	

	
	
	// draw signals
    
    // sin of time
    
    ofTranslate(0, 100);         // move drawing "origin" down screen 50 pixels
    
    sineSignal.draw();
    
    ofDrawBitmapStringHighlight("sin (time)", 20, -60, ofColor::black, sineSignal.color);
	
	
	// hi-freq sin of time
	
	ofTranslate(0, 200);        // move down screen
	
	sineHighFreqSignal.draw();
	
	ofDrawBitmapStringHighlight("sin (time * 20)", 20, -60, ofColor::black, sineHighFreqSignal.color);
	
	
	// amplitude modulation
	
	ofTranslate(0, 200);
	
	sineSignal.draw();
	amSignal.draw();
	
	ofDrawBitmapStringHighlight("amplitude modulated:\n sin (time * 20) * sin(time)", 10, -80, ofColor::black, amSignal.color);
	
	
	// frequency modulation
	
	ofTranslate(0, 200);
	
	sineSignal.draw();
	fmSignal.draw();
	
	ofDrawBitmapStringHighlight("frequency modulated:\n sin ( sin(time) * 20 )", 20, -80, ofColor::black, fmSignal.color);
	
	
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
