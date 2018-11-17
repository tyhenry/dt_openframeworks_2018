#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    earthImg.load("earth_texture.jpg");
    
    sphere.set(200,3);
    sphere.mapTexCoordsFromTexture(earthImg.getTexture());
    
    gui.setup();
    gui.add( bLight.set("lighting", true));
    gui.add( bFaces.set("draw faces", true));
    gui.add( bTexture.set("draw texture", true));
    gui.add( bWires.set("draw wireframe", true));
    gui.add( bVerts.set("draw vertices", true));
    gui.add( bNormals.set("draw normals", true));
    
    
    // setup sun
    sun.setDirectional();
    sun.setPosition(glm::vec3(-100,20,500));
    sun.lookAt(glm::vec3(0));               // point ofNode -z at earth
    sun.rotateDeg(180, glm::vec3(0,1,0));   // ofLight shines +z!
    sun.setDiffuseColor(ofColor::wheat);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    sphere.rotateDeg(.05, glm::vec3(0,1,0));     // rotate earth
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::wheat, ofColor::darkOrchid);
    ofSetColor(255);
    
    cam.begin();
    ofEnableDepthTest();
    
    if (bLight){
        ofEnableLighting();
        sun.enable();
    }
    
    // draw the sphere surface
    if (bFaces){
        if (bTexture) earthImg.bind();      // bind image texture
        else ofSetColor(170);               // or color flat gray
        
        sphere.drawFaces();                 // aka sphere.draw();
        if (bTexture) earthImg.unbind();    // unbind after binding!
    }
    
    ofSetColor(ofColor::thistle);
    if (bWires) sphere.drawWireframe();
    
    
    /*  below we use custom code to draw
        the mesh vertices and normals of the sphere
    
        first we need to transform the space so the mesh draws
        along with the sphere's internal ofNode rotation:
     */
    
    ofPushMatrix();
    ofMultMatrix( sphere.getGlobalTransformMatrix() );
    
    ofMesh& mesh = sphere.getMesh();    // reference to mesh
    
    if (bVerts) {
        // draw vertices (as spheres)

        ofSetColor(ofColor::plum);
        for (int i=0; i<mesh.getVertices().size(); i++){
            ofDrawSphere(mesh.getVertices()[i], 1);
        }
        // or sphere.getMesh().drawVertices(); // draw points
    }
    
    if (bNormals) {
        // draw face normals from centers of mesh faces
        
        ofSetColor(ofColor::indigo);
        for (auto& face: mesh.getUniqueFaces()){
            /*  faces are triangles -
             
                find center of a triangle:
                2/3 from a point to the middle of opposite edge
             
                          0
                         /|\
                        / c \
                       /_____\
                      2   m   1
             
             */
            auto vert0 = face.getVertex(0);
            auto vert1 = face.getVertex(1);
            auto vert2 = face.getVertex(2);
            auto midpt = (vert1 + vert2)*0.5;
            auto centroid = vert0 + (2./3.)*(midpt-vert0);
            ofDrawLine(centroid, centroid-face.getFaceNormal()*10);
        }
        // or sphere.getMesh().drawNormals(10);   // draw *vertex* normals
    }

    ofPopMatrix();
    
    if (bLight){
        
        sun.disable();
        ofDisableLighting();
        
        ofSetColor(sun.getDiffuseColor());
        sun.draw();     // draw the sun as an ofNode

    }

    ofDisableDepthTest();
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
