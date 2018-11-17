#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(70, 20, 20);
	
	ofSetSmoothLighting(true);
	ofSetFrameRate(60);
    
    // volcano is an ofConePrimitive (combines ofMesh and ofNode)
	
    // setup the cone: radius, height, mesh resolution x and y
	volcano.set(250, 400, 80, 70);
	
	// rotate 180 around x axis to point up
    volcano.rotateDeg(180, glm::vec3(1,0,0));
	
	auto& coneVerts = volcano.getMesh().getVertices();
    // 'auto' means 'whatever' type
    // '&' means a reference to the mesh vertices (not a copy)

	for (int i=0; i<coneVerts.size(); i++)
	{
		if (coneVerts[i].y <= -50) {
            // move cone tip down into "volcano"
			coneVerts[i].y = 40;
		}
		
		// add some mesh noise for an organic mountain
        glm::vec3 nPos = coneVerts[i] * 0.01;
		coneVerts[i].x += ofSignedNoise( nPos.x ) * 30.;
		coneVerts[i].y += ofSignedNoise( nPos.y ) * 30.;
		coneVerts[i].z += ofSignedNoise( nPos.z ) * 30.;
	}
	
	
	// create the ground
	ground.set(10000, 10000, 1000, 1000);       // really big
    ground.rotateDeg(-90, glm::vec3(1,0,0));    // turn horizontal
	ground.move(0, -200, 0);                    // move down
	
	// gravity
	gravity = ofVec3f(0,-.003,0);
	
	
	// lights
    
    // volcano fire
	firelight.setPointLight();    // light from a point (light bulb)
	firelight.setPosition(0,200,0);
    firelight.setDiffuseColor( ofColor::red );

	// sun light
	sunlight.setDirectional();    // light from a direction (sun)
	sunlight.setPosition(100,100,-400);    // raise up and offset
    sunlight.lookAt(glm::vec3(0));      // point at volcano
	sunlight.setDiffuseColor( ofColor::wheat);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// spawn new eruption particles
	for (int i=0; i<10; i++)
	{
		Particle p;
		p.vel.x = ofRandom(-1,1);
		p.vel.y = ofRandom(1.5,4);	// up
		p.vel.z = ofRandom(-1,1);
		p.lifespan = ofRandom(7,9);
		p.mass = ofRandom(.7,1.3);
		eruption.push_back(p);
	}
	
	while (eruption.size() > 5000)
	{
		eruption.erase(eruption.begin());
	}
	
	for (int i=0; i<eruption.size(); i++)
	{
		eruption[i].applyForce(gravity);
		eruption[i].update();
	}
	

	// use noise to animate the fire brightness
    float noise = ofNoise(ofGetElapsedTimef() * 2.);
    float hue   = noise * 20.;
    float brt   = noise * 255.;
	firelight.setDiffuseColor( ofColor::fromHsb(hue, 255, brt));

    // animate sun rotation
    sunlight.rotateDeg(.2, 0,1,0);

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::fireBrick, ofColor(30.,10.,0));
	
	ofEnableLighting();
	
	cam.begin();
	ofEnableDepthTest();
	
	firelight.enable();
	
	for (int i=0; i<eruption.size(); i++)
	{
		eruption[i].draw();
	}
	
	sunlight.enable();
	
	ofSetColor( ofColor(73, 48, 35) );
	volcano.draw();
	volcano.drawAxes(100);
	
    ofSetColor( ofColor::darkOliveGreen) ;//ofColor(70,120,10));
	ground.draw();
	ofSetColor(255);
	
	firelight.disable();
	sunlight.disable();
	ofDisableLighting();
	
	ofDisableDepthTest();
	
	// you can draw the lights on top of your scene
     firelight.draw();
     sunlight.draw();
	
	
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
