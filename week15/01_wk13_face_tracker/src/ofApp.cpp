#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    webcam.listDevices();      // prints all webcams to console
    webcam.setup(640, 480);    // open default webcam @ 640x480
    
    // ofxCv::ObjectFinder
    //  can find some objects (e.g. faces) in images
    //  + keep track of found objects as they move (if video)
    
    finder.setup("haarcascade_frontalface_default.xml");
    // load a "Haar cascade" object detector file -
    // ours will find faces - check bin/data/ folder for more:
    //  - cat face, full body, license plate, clock, etc.
    //  see how it works: https://www.youtube.com/watch?v=hPCTwxF0qf4&feature=youtu.be&t=57
    
    finder.setPreset( ObjectFinder::Preset::Fast );
    // other presets: Accurate (slow), Sensitive (finds more)
    
    finder.getTracker().setPersistence( 30 );
    // the tracker will forget a face if gone for 30 frames
    
    
    // an ofConePrimitive (3d cone mesh) will be our hat:
    
    hat.set( 100, 200, 10, 20 );
    // 100 radius, 200 tall, 10 x, 20 y resolution
    
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    webcam.update();            // update live camera
    
    if (webcam.isFrameNew()) {  // process new frames
        
        finder.update(webcam);     // update the face tracker
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    ofEnableDepthTest();
    
    // draw webcam center screen:
    glm::vec2 webcamSize = glm::vec2(webcam.getWidth(),webcam.getHeight());
    glm::vec2 webcamPos  = ofGetWindowSize()*0.5 - webcamSize*0.5;
    ofTranslate( webcamPos );
    
    webcam.draw(0,0);   // draw the camera image

    // draw on faces
    for (int i=0; i<finder.size(); i++){
        
        // get box around the face:
        ofRectangle face = finder.getObjectSmoothed(i); // smoothed over time
        // or face = finder.getObject(i); <-- raw face position
        
        ofPushStyle();
        
        // assign color by face ID
        int faceID  = finder.getLabel(i);
        float hue   = (faceID * 55) % 255;  // offset hue by id
        ofSetColor( ofColor::fromHsb(hue, 255,255));
        
        // draw face box
        
        ofNoFill();
        ofDrawRectangle( face );
        
        // draw hat
        
        ofPushMatrix();
        ofTranslate( face.getCenter().x, face.getTop() - hat.getHeight()*0.4);
        hat.setScale( (face.width * .5) / hat.getRadius() );    // scale hat to face
        hat.drawFaces();
//        hat.drawWireframe();
        ofPopMatrix();
        
        // draw face "label"
        
        ofPushMatrix();
        ofTranslate( face.getCenter().x-30, face.getBottom()+10 );
        stringstream ss;
        ss << " face: " << finder.getLabel(i);   // face id #
        ofDrawBitmapStringHighlight( ss.str(), 0,0, ofColor::fromHsb(hue, 255,255), ofColor(0) );
        ofPopMatrix();
        
        // draw face velocity
        
        glm::vec2 vel = toOf( finder.getVelocity(i));
        ofPushMatrix();
        ofTranslate( face.getCenter() );
        ofFill();
        ofDrawCircle( 0,0, 2 );
        ofDrawLine( glm::vec2(0), vel * -3 );   // scale velocity for visual
        ofPopMatrix();
        
        ofPopStyle();
        
    }
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
