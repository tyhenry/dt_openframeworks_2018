#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofBackground(0);
	ofSetFrameRate(30);	    // match app frame rate to webcam
    
    
    // setup webcam
    
    vid.listDevices();    // print your webcams to the console
    vid.setup(640,480);    // or choose cam #0 using: vid.setup(0, 640, 480)
    
    // setup plane mesh
	
    float aspectRatio = vid.getWidth() / vid.getHeight();
    float w = ofGetWidth();         // scale up vid
    float h = w / aspectRatio;      // keep aspect ratio
    
	plane.set(w, h, 128, 128);	    // width x height, 128x128 grid
    plane.mapTexCoordsFromTexture(vid.getTexture());
    // map texture coordinates for video texture
	
	
	// setup gui
	
	gui.setup();
	
	// add float slider control to gui:
    // set( "label", default value, min, max )
    
	gui.add( scale.set("scale", 0.5, 0, 1) );
    gui.add( rotation.set("rotation", 0, 0, 360) );
	
	// add boolean/toggle controls to gui:
    // set( "label", default )
    
    gui.add( bRotate.set("auto-rotate", true) );
    gui.add( bTexture.set("use texture", true) );
	gui.add( bWires.set("draw wireframe", true) );
	gui.add( bAxis.set("draw axis", false) );
	

	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	vid.update();
	
	if (vid.isFrameNew())	// only update if a new webcam frame has arrived
	{
        
        ofMesh& mesh = plane.getMesh();
		
		for (int i=0; i<mesh.getVertices().size(); i++)
		{
			auto& vertex = mesh.getVertices()[i];
			// & = direct reference to mesh vertex,
			// if we edit vertex, we edit mesh!
			
			// add z offsets per image brightness:
				
            // map mesh coords to image coords
            float w     = plane.getWidth();
            float h     = plane.getHeight();
            float imgX  = ofMap(vertex.x, -w*0.5, w*0.5, 0, vid.getWidth()-1);
            float imgY  = ofMap(vertex.y, h*0.5, -h*0.5, 0, vid.getHeight()-1);
            
            ofColor color       = vid.getPixels().getColor(imgX, imgY);
            float brightness    = color.getBrightness();
            
            vertex.z = brightness * scale;
			
		}
	}
	
	if (bRotate)
		rotation -= 0.1;	// animate rotation angle
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofEnableDepthTest();
	
	cam.begin();
	
    ofRotateXDeg(rotation);
	
    if (bTexture) {
        vid.bind(); // draw the webcam texture on the mesh
    }
	plane.draw();
    
    if (bTexture) {
        vid.unbind();   // don't forget to unbind after you bind!
    }
	
    if (bWires){
        ofPushStyle();
        ofSetColor(127,127);
        plane.drawWireframe();
        ofPopStyle();
    }
	
	ofDisableDepthTest();
	
	if (bAxis)
		ofDrawAxis(100);		// draw the axis on top
	
	cam.end();
	

	gui.draw();
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
