#include "ofApp.h"


// our app talks to itself (or other apps on a network) using OSC messages:

// we'll SEND OSC messages to:
const string    SEND_HOST      = "127.0.0.1";   // local, or remote ip
const int       SEND_PORT      = 2222;

// we RECEIVE OSC messages on this port:
const int       RECEIVE_PORT   = 2222;   // listen on this port (at our ip)


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false); // draw trails
    
    // limit our frame rate to 60 fps max, so we don't spam osc messages:
    ofSetFrameRate(60); // should be called ofLimitFrameRate() ...
    
    
    
    // set up receiver:
    // ----------------
    // listen for OSC messages on this port:
    receiver.setup(RECEIVE_PORT);

    
    // set up sender
    // ----------------
    // send messages to this address (host and port):
    sender.setup(SEND_HOST, SEND_PORT);
    
    
    ofLogNotice()
        << "listening for osc messages on port " << RECEIVE_PORT << endl
        << "sending osc messages to host " << SEND_HOST << " @ port " << SEND_PORT;


}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    // receive any incoming mouse data:
    // ----------------

    // get all waiting messages
    while(receiver.hasWaitingMessages()){
        
        // collect the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // mouse-moved message type
        if (m.getAddress() == "/mouse/position"){
            // message address: /topic/name
            
            // mouse x, y arguments are 2 floats
            float mX = m.getArgAsFloat(0);
            float mY = m.getArgAsFloat(1);
            
            // map normalized 0-1 position to screen space
            oscMousePos.x = ofMap(mX, 0, 1, 0, ofGetWidth()*.5, true);
            oscMousePos.y = ofMap(mY, 0, 1, 0, ofGetHeight(), true);
        }
        
        // mouse-button message type
        else if (m.getAddress() == "/mouse/buttons"){

            oscMousePress[0] = m.getArgAsBool(0);     // 0 = left
            oscMousePress[1] = m.getArgAsBool(1);     // 1 = right
            // press = true, release = false
            
        }
    }
    
    
    // send our mouse position
    // ----------------

    ofxOscMessage m;
    m.setAddress("/mouse/position");
    // normalize 0-1 (limiting x to left half of window)
    float mX = ofMap(ofGetMouseX(), 0, ofGetWidth()*.5, 0.f, 1.f, true);
    float mY = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0.f, 1.f, true);
    m.addFloatArg(mX);
    m.addFloatArg(mY);
    sender.sendMessage(m, false);
    
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the local mouse
    // ----------------
    
    // draw bg
    ofSetColor(0, 40);
    ofDrawRectangle(0, 0, ofGetWidth()*.5, ofGetHeight());
    
    // draw mouse pos
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
    ofSetColor(255);
    ofDrawCircle(mousePos, 5);
    ofDrawBitmapStringHighlight("mouse pos: " + ofToString(mousePos), 20, 20);
    
    
    
    // draw received OSC mouse data
    // ----------------
    
    // move to right half of window
    ofTranslate(ofGetWidth() * 0.5, 0);
    
    // draw bg
    ofColor beige = ofColor(240, 240, 220, 40);
    ofSetColor( beige );
    ofDrawRectangle(0,0,ofGetWidth() * 0.5, ofGetHeight());
    
    // osc mouse color + radius based on button states
    ofColor color = ofColor(0);
    float radius = 5;
    if (oscMousePress[0]){        // left press
        color.r = 100;
        radius += 2.5;
    }
    if (oscMousePress[1]){        //right press
        color.b = 100;
        radius += 2.5;
    }
    
    ofSetColor(color);
    ofDrawCircle(oscMousePos, radius);
    
    beige.a = 127;
    ofDrawBitmapStringHighlight("OSC received mouse pos: " + ofToString(oscMousePos), 20, 20, beige, color);
    

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    /*  ofApp::mousePressed() tracks 3 buttons:
        button: 0 = left, 1 = middle, 2 = right
     
        we only care about left and right (0,1)
     */
    if (button > 1) button = 1; //  0 = left, 1 = right
    mousePress[button] = true;  // store local button state

    // write our updated button states as an osc message
    ofxOscMessage m;
    m.setAddress("/mouse/buttons");
    m.addBoolArg(mousePress[0]);
    m.addBoolArg(mousePress[1]);
    sender.sendMessage(m, false);
    
    cout << "mouse button [" << button << "] press" << endl;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    if (button > 1) button = 1;  // 3 button mouse -> 2 button
    mousePress[button] = false;  // store local button state
    
    // write the button release as an osc message
    ofxOscMessage m;
    m.setAddress("/mouse/buttons");
    m.addBoolArg(mousePress[0]);
    m.addBoolArg(mousePress[1]);
    sender.sendMessage(m, false);
    
    cout << "mouse button [" << button << "] release" << endl;


}
