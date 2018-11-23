#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    //ofSetSmoothLighting(false);   // use blocky lighting
    
    // plane mesh
    plane.set(500, 500, 80, 80, OF_PRIMITIVE_TRIANGLES);
    // size x y, resolution x y, mesh mode
    plane.rotateDeg(-30, 1,0,0);    // rotate
    
    updateNormals();  // call this to update the normals whenever the mesh is altered
    
    light.setup();
    light.setDirectional();
    light.setDiffuseColor( ofColor::wheat );
    light.setPosition(0, 200, 200);
    light.rotateDeg(225, 0, 1, 0);  // turn around to face plane + extra
    light.enable();
    

    // print some mesh info:
    ofMesh& mesh = plane.getMesh();
    cout
        << "mesh stats: " << endl
        << "vertices: " << mesh.getVertices().size() << endl
        << "indices: " << mesh.getIndices().size() << endl
        << "normals: " << mesh.getNormals().size() << endl
        << "mesh mode: " << mesh.getMode() << endl;
    
    
    bLighting   = true;
    bNormals    = true;
    bWireframe  = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // generate noise waves on mesh
    float time = ofGetElapsedTimef();

    ofMesh& mesh = plane.getMesh();
    for (int i=0; i<mesh.getVertices().size(); i++){

        glm::vec3& vertex   = mesh.getVertices()[i];
        glm::vec3 noisePos  = vertex / 200.f;
        noisePos.z          = time * .5f;       // use time for z

        // add noise depth
        vertex.z = ofNoise(noisePos) * 100.f;

    }
    updateNormals();

    // animate mesh rotation
//    plane.rotateDeg(.1, 0, 1, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofEnableDepthTest();
    
    if (bLighting) ofEnableLighting();
    plane.draw();           // draw mesh surface
    if (bLighting) ofDisableLighting();
    
    if (bWireframe){
        ofPushStyle();
        ofSetColor(0,100,255);
        plane.drawWireframe();
        ofPopStyle();
    }

    // draw normals:
    if (bNormals){
        ofPushMatrix();
        ofPushStyle();
        ofSetColor(255,0,255);
        ofMultMatrix( plane.getGlobalTransformMatrix() );
        for (int i=0; i<plane.getMesh().getVertices().size(); i++){
            auto& v = plane.getMesh().getVertices()[i];
            auto& n = plane.getMesh().getNormals()[i];
            ofDrawLine(v, v+n*10);
        }
        ofPopStyle();
        ofPopMatrix();
    }
    
    // draw light using light color
    if (bLighting) {
        ofPushStyle();
        ofSetColor(light.getDiffuseColor());
        light.draw();
        ofPopStyle();
    }
    
    
    ofDisableDepthTest();
    cam.end();
    
    
    // draw info
    stringstream ss;
    ss
        << "use [L]ighting: \t" << bLighting << endl
        << "draw [N]ormals: \t" << bNormals << endl
        << "draw [W]ireframe: \t" << bWireframe;
    
    ofDrawBitmapStringHighlight( ss.str(), 20,20 );
    

}

//--------------------------------------------------------------
void ofApp::updateNormals(){
    
    auto& mesh  = plane.getMesh();
    
    if (plane.getMesh().getMode() != OF_PRIMITIVE_TRIANGLES){
        // make sure mesh is using correct mode
        cout << "mesh must use ofPrimitiveMode: OF_PRIMITIVE_TRIANGLES to update normals!" << endl;
        return;     // abort if incorrect
    }
    
    auto& verts = mesh.getVertices();

    if (mesh.getNormals().size() != verts.size()){
        // just double checks that # normals == # vertices
        mesh.clearNormals();
        mesh.addNormals( vector<glm::vec3>(verts.size()) );
        cout << "resized mesh normals to " << mesh.getNormals().size() << endl;
    }
    
    for( int i=0; i+2 < mesh.getIndices().size(); i+=3 ){
        
        const int ia = mesh.getIndices()[i];
        const int ib = mesh.getIndices()[i+1];
        const int ic = mesh.getIndices()[i+2];
        
        // normal is cross product of two edges
        glm::vec3 e1 = verts[ia] - verts[ib];
        glm::vec3 e2 = verts[ic] - verts[ib];
        glm::vec3 no = glm::normalize(glm::cross(e2,e1));
        
        // depending on your clockwise / winding order, you might want to reverse the e2 / e1 above if your normals are flipped.
        
        mesh.getNormals()[ia] = no;
        mesh.getNormals()[ib] = no;
        mesh.getNormals()[ic] = no;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key == 'l'){
        bLighting = !bLighting;
    }
    else if (key == 'n'){
        bNormals = !bNormals;
    }
    else if (key == 'w'){
        bWireframe = !bWireframe;
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
