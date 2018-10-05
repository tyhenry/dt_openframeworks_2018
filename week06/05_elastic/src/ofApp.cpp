#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	
	// make a spiral
	
	glm::vec2 center  = ofGetWindowSize() * .5;               // center screen
	
	int nRotations	= 20;
	float maxAngle	= TWO_PI * nRotations;                  // angle in radians

	for (float theta = 0.; theta < maxAngle; theta += .1)	// increase angle (in radians)
	{
		
		float radius = (theta / maxAngle) * ofGetWidth() * .5;  // increase radius around spiral
		
        glm::vec2 pos;
		pos.x = center.x + (cos(theta) * radius);
		pos.y = center.y + (sin(theta) * radius);
	
		ElasticMover mover = ElasticMover(pos, 1.);
		movers.push_back(mover);
		
	}
	
	bSpin = false;      // turn off spiral spinning

}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    glm::vec2 mousePos = glm::vec2(ofGetMouseX(), ofGetMouseY());
	
	for (int i=0; i<movers.size(); i++)
	{
        
		glm::vec2 diff  = mousePos - movers[i].pos;
        float dist      = glm::length(diff);
		
		if (dist < 100. && dist != 0.)    // apply repulsion if distance is small (and not 0!)
		{
            glm::vec2 diffNorm  = diff / dist;
			glm::vec2 repulsion = diffNorm * -.5;
			movers[i].applyForce(repulsion);
		}
		
		movers[i].applyElasticForce();      // bounce back to starting position
		
		movers[i].applyDampingForce(0.05);
		
		movers[i].update();
		
		
		// add a circular spin (rotate the mover's orig pos and pos)
		
		float rotRad = .03;
		
		if (bSpin)
		{
			glm::vec2 center	= ofGetWindowSize()*.5;
			
			// rotate pos of Mover
			
			glm::vec2 vec	= movers[i].pos - center;
			float theta		= atan2(vec.y, vec.x) - rotRad;         // new angle for spiral
            float radius	= glm::length(vec);
			
			movers[i].pos.x = center.x + (cos(theta) * radius);     // calc new position
			movers[i].pos.y = center.y + (sin(theta) * radius);
            
            // rotate origPos of Mover
            
            glm::vec2 oVec  = movers[i].origPos - center;
            float oTheta    = atan2(oVec.y, oVec.x) - rotRad;
            float oRadius   = glm::length(oVec);
            
            movers[i].origPos.x = center.x + (cos(oTheta) * oRadius);
            movers[i].origPos.y = center.y + (sin(oTheta) * oRadius);
			
		}
		
		
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofBackgroundGradient(ofColor::indigo, ofColor::orchid);
	
	for (int i=0; i<movers.size(); i++)
	{
		if (i < movers.size() -1)
		{
			ofDrawLine(movers[i].pos, movers[i+1].pos);
		}
		movers[i].draw();
	}
	
	// draw instructions
	
	ofColor lblCol(0); // black
	if (bSpin) lblCol = ofColor::darkRed;
	ofDrawBitmapStringHighlight("space: toggle spin", glm::vec2(20,20), lblCol);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	if (key == ' ')
	{
		bSpin = !bSpin;	// toggle wind
	}

}
