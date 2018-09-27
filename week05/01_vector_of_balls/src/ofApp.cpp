#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCircleResolution(100);
    
    // define the box the ball will bounce inside
    
    boxLeft     = 100;
    boxRight    = ofGetWidth() - 100;
    boxTop      = 100;
    boxBottom   = ofGetHeight() - 100;
    
    
    // create 3 balls (click to add more: ofApp::mouseReleased())
    
    for (int i=0; i<3; i++){
        
        // add a ball to the 'balls' vector
        
        Ball ball;
        
        float bounciness    = ofRandom(0,1);                    // how bouncey ball will be
        float size          = ofMap(bounciness, 0, 1, 30, 5);   // size based on bounciness
        
        glm::vec2 pos;
        pos.x               = ofRandom(boxLeft, boxRight);      //  random x pos in box
        pos.y               = (boxTop + boxBottom) * 0.5;       //  center in box y
        
        ball.setup(pos, size, bounciness);                      // set up the ball
        
        glm::vec2 vel;
        vel.x               = ofRandom(-10,10);                   // random velocity
        vel.y               = ofRandom(-5,0);
        ball.setVelocity(vel);
        
        balls.push_back(ball);                  // vector::push_back() adds an element to the vector
        
    }
    
    // setup gravity
    gravity = glm::vec2(0, 0.05);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i=0; i<balls.size(); i++){         // size() gives number of elements in vector

        balls[i].addForce(gravity);             // call this before update()
        
        balls[i].update();
        
        balls[i].bounce(boxLeft, boxRight, boxTop, boxBottom);  // bounce inside the box
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw the balls
    
    for (int i=0; i<balls.size(); i++){
        balls[i].draw();
    }
    
    // draw outlined box
    
    ofNoFill();     // draw in outlines temporarily
    
    float boxWidth      = boxRight - boxLeft;
    float boxHeight     = boxBottom - boxTop;
    ofDrawRectangle(boxLeft, boxTop, boxWidth, boxHeight);
    
    ofFill();       // reset fill mode
    
    
    // ugly text instructions onscreen at x,y 20,20:
    
    ofDrawBitmapString("click inside box to make a ball", 20, 20);
    
    ofDrawBitmapString(ofToString(balls.size()) + " balls", 20, 40);

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
    
    // check if click inside box
    if (x >= boxLeft && x <= boxRight){
        if (y >= boxTop && y <= boxBottom){
            
            // add a new ball
            Ball ball;
            float bounciness    = ofRandom(0,1);
            float size          = ofMap(bounciness, 0,1, 30, 5);
            glm::vec2 pos       = glm::vec2(x,y);
            glm::vec2 vel       = glm::vec2( ofRandom(-10,10), ofRandom(-10,-5) );   // random velocity
            
            ball.setup(pos, size, bounciness);
            ball.setVelocity(vel);
            
            balls.push_back(ball);
        }
        
    }
    

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
