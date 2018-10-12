#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);
	ofSetFrameRate(60.);
    
    radius = 250.0;

	sphere.setRadius(radius);
    sphere.setResolution(50);
    
    // ofSpherePrimitive contains a "mesh", which is the structure of the 3D shape
    
    ofLog()
    << "sphere mesh contains: " << endl
    
    // count mesh contents :
    << "\t- " << sphere.getMesh().getNumVertices()      << " vertices" << endl
    << "\t- " << sphere.getMesh().getIndices().size()   << " indices" << endl
    << "\t- " << sphere.getMesh().getIndices().size() / 3 << " triangles" << endl
    << "\t- " << sphere.getMesh().getTexCoords().size() << " texture coordinates" << endl;


	ofDisableArbTex();
	video.setup(640,480);

    sphere.rotateDeg(180, glm::vec3(0,0,1));      // rotate the sphere to "face" screen
    sphere.rotateDeg(180, glm::vec3(0,1,0));

	bDrawWireframe = false;
}

//--------------------------------------------------------------
void ofApp::update(){

	float time = ofGetElapsedTimef();

	// we will offset the radius by some noise to move vertices in and out
    
	noiseScale    = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0., 50.);
        // radius offset amount
	noiseFreq     = ofMap(ofGetMouseY(), 0, ofGetHeight(), .1, 3.);
        // speed of noise


	for (int v = 0; v < sphere.getMesh().getNumVertices(); v++)
	{
        glm::vec3 vertex = sphere.getMesh().getVertex(v);
        
        float length = glm::length(vertex);         // test radius > 0
        if (length > 0){
            
            glm::vec3 norm  = vertex / length;
            float noise     = ofSignedNoise(glm::vec3(time * .5) + norm * noiseFreq);
                // 0 - 1
            vertex          = norm * (radius + noise * 50);
                // scale up to radius + noise
            
            sphere.getMesh().setVertex(v, vertex);
        }

	}

    // rotate the sphere a little at a time
    
	ofVec3f rot;
	rot.x = sin(time * .1);             // rotate around X axis
	rot.y = 1.;                         // rotate around Y axis
	rot.z = sin(time * .1 +1000);       // rotate around Z axis
	sphere.rotateDeg(.1, rot);

	// update video camera
	video.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    
    ofPushMatrix();

	ofTranslate(ofGetWidth()*.5, ofGetHeight()*.5); 

	ofEnableDepthTest();            // draw things in back first / in front last

	video.bind();
	sphere.draw();                  // draw the sphere with video texture
	video.unbind();

	if (bDrawWireframe)
	{
		ofSetColor(0, 100, 255);
		sphere.drawWireframe();

		ofSetColor(255, 0, 0);
		sphere.drawVertices();
		sphere.drawNormals(10);
		sphere.drawAxes(sphere.getRadius() + 100);
	}

	ofDisableDepthTest();
    ofPopMatrix();
    
    // draw instructions
    string info = "press space to toggle wireframe\n";
    info += "mouse x - noise scale: " + ofToString(noiseScale, 2) + "\n";
    info += "mouse y - noise frequency: " + ofToString(noiseFreq, 2);
    ofDrawBitmapStringHighlight(info, 20, 20);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == ' ')
	{
		bDrawWireframe = true;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	bDrawWireframe = false;
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
