#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);    // set background black
    
    // setup our array of 10 squares, which we declared in ofApp.h
    
    for (int i=0; i<10; i++){   // loop 10 times, increment i each time
        
        // run the square setup function, offsetting x and y positions by (i * 50) pixels
        
        float w = 50;      // width
        float h = 50;      // height
        
        float x = i * 50;
        float y = i * 50;
        
        // we access array elements by index number, like array[index]
        
        squares[i].setup(x, y, w, h);
        
        // set starting movement direction
        
        squares[i].dirX = 5;        // move 5 pixels right per frame to start
        squares[i].dirY = 5;        // move 5 pixels down per frame
        
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0; i<10; i++){
        squares[i].update();        // move and bounce off walls
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i=0; i<10; i++){
        squares[i].draw();          // draw to screen
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    // some extra keyboard commands:
    
    if (key == 'f') {
        
        // press f to toggle fullscreen / window mode
        ofToggleFullscreen();
    }
    
    else if (key == 'p')
        
        // print some info to console:
        
        // number of seconds app has been running
        cout << "Square positions @ " << ofGetElapsedTimef() << " seconds..." << endl;
    
    for (int i=0; i<10; i++){
        // print center positions
        cout << "    square [" << i << "]: " << squares[i].getCenterX() << ", " << squares[i].getCenterY() << endl;
    }
    
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
