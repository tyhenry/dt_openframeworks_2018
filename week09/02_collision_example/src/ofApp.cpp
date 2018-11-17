#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(200);
    
    glm::vec2 centerScreen = ofGetWindowSize() * 0.5;
    
    
    // setup paddle:
    
    glm::vec2 paddlePos = centerScreen + glm::vec2(-100,300);
    float angle = 0.;
    
    paddle = PaddleCircles(paddlePos, 0.);

    
    // setup collision rectangle:
    
    // rectangle = ofRectangle(posTopLeft, width, height);
    glm::vec2 rectPos = centerScreen - glm::vec2(100,200);
    rectCollider.set(rectPos, 200, 100);
    
    
    // setup pinball:
    
    glm::vec2 ballPos = centerScreen;
    ball.setup(ballPos, 20);
    ball.vel.x = ofRandom(-3,3);
    ball.vel.y = 5.0;
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ball.update();
    
    // rotate the paddle if user is pressing a key
    
    if (rotateAngle != 0){
        paddle.rotate(rotateAngle); // angle set in keyPressed()
    }
    
    
    // "paddle" collision:
    // -----------------
    // paddle is made out of circles for easy circle collision
    // -- see PaddleCircle.cpp --
    
    bool paddleCollided = paddle.testCollision(ball.pos, ball.radius);
    
    if (paddleCollided) {
        ball.reflect(paddle.getDirection());
        paddleColor = ofColor(255,0,0); // set paddle color
    } else { paddleColor = ofColor(0,0,255); }
    
    
    /* rectangle-circle collision:
     / --------------------
     / example: https://yal.cc/rectangle-circle-intersection-test/
     /
     / 1. find point in rectangle closest to circle pos
     / 2. collision if distance between points
     /     less than circle radius
     */

    glm::vec2 nearestPoint; // clamp circle to rect bounds
    nearestPoint.x = ofClamp(ball.pos.x, rectCollider.getLeft(), rectCollider.getRight());
    nearestPoint.y = ofClamp(ball.pos.y, rectCollider.getTop(), rectCollider.getBottom());

    glm::vec2 diff = nearestPoint - ball.pos;  // get distance
    bool rectCollided = glm::length(diff) <= ball.radius;
    
    // set rect color
    if (rectCollided) { rectColor = ofColor(255,0,0); }
    else { rectColor = ofColor(0,0,255); }
    

    // set ball color
    if (paddleCollided || rectCollided) {
        ballColor = ofColor(0,0,255); }
    else { ballColor = ofColor(255,0,0); }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(paddleColor);
    paddle.draw();
    
    ofSetColor(255);
    ofDrawLine(paddle.pos, paddle.pos + paddle.getDirection() * 200);
    ofDrawLine(paddle.pos, paddle.pos + paddle.getNormal() * 100);
    
    ofSetColor(rectColor);
    ofDrawRectangle(rectCollider);
    
    ofSetColor(ballColor);
    ball.draw();
    
    // draw info
    ofSetColor(100);
    ofDrawBitmapString("UP/DOWN to spin the paddle (angle: " + ofToString(ofRadToDeg(paddle.angleRadians)) + ")", 20, 20);
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // hold UP/DOWN keys to rotate paddle a little bit
    
    if (key == OF_KEY_UP){
        rotateAngle = -5;
    }
    else if (key == OF_KEY_DOWN){
        rotateAngle = 5;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    // release UP/DOWN keys to set rotate back to 0
    
    if (key == OF_KEY_UP || key == OF_KEY_DOWN){
        rotateAngle = 0;
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
