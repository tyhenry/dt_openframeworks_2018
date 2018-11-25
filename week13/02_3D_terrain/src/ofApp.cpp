#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    // setup app parameters:
    // ---------------------
    
    // using ofParameterGroup to organize --
    //      "terrainParams", "drawParams", "noiseParams"
    
    terrainParams.setName("terrain");
    terrainParams.add( terrainResolution.set("resolution", 256, 2, 1024) );
    terrainParams.add( terrainHeight.set("height", 200, 0, 400) );
    // add a button:
    terrainParams.add( regenerateTerrainButton.set("regenerate mesh") );
    // button "callback" function
    regenerateTerrainButton.addListener(this, &ofApp::generateTerrain);
    
    drawParams.setName("draw");
    drawParams.add( bTexture.set("draw texture", true) );
    drawParams.add( bDrawSurface.set("draw surface", true) );
    drawParams.add( bDrawWireframe.set("draw wireframe", false) );
    drawParams.add( bDrawNormals.set("draw normals", true) );
    drawParams.add( bLighting.set("lighting", true) );
    drawParams.add( lightColor.set("light color", ofColor::wheat, ofColor(0,0,0), ofColor(255,255,255)));
    
    noiseParams.setName("noise");
    noiseParams.add( bNoise.set("apply noise", false) );
    noiseParams.add( noiseFreq.set("noise frequency",
        glm::vec2(3,10), glm::vec2(0,0), glm::vec2(20,20)));
    noiseParams.add( noiseSpeed.set("noise speed", .02, 0, .5));
    noiseParams.add( noiseAmp.set("noise height", 50, 0, 200));
    
    // setup + add parameters to gui
    gui.setup();
    gui.add( terrainParams );
    gui.add( drawParams );
    gui.add( noiseParams );
    
    
    // setup terrain
    // -------------
    heightMap.load("crater_depth.jpg");
    textureMap.load("crater_texture.jpg");
    generateTerrain();

    // setup lighting
    // --------------
    light.setDirectional();
    light.setDiffuseColor( ofColor::white );
    light.setPosition(0, 100, 300);
    light.rotateDeg(200, 0,1,0);    // point forward
    light.enable();
    
    // adjust camera distance
    // ---------------
    cam.setAutoDistance(false);
    cam.setDistance(1200);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    float time = ofGetElapsedTimef();
    
    if (bNoise){
        terrain.applyNoise(noiseFreq, noiseAmp, time * noiseSpeed);
    }
    
    light.setDiffuseColor(lightColor.get());

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();             // alter the view:
    ofRotateDeg(80, 0,1,0);     // rotate scene
    
    ofEnableDepthTest();
    
    if (bLighting)      { ofEnableLighting(); }
    else                { ofSetColor(lightColor.get()); } // flat color

    if (bTexture)       { textureMap.bind(); }
    if (bDrawSurface)   { terrain.draw(); }
    if (bTexture)       { textureMap.unbind(); }
    
    if (bDrawWireframe) {
        ofSetColor(0,255,127);
        terrain.drawWireframe();
    }
    if (bDrawNormals)   {
        ofSetColor(255,0,255, 127);
        terrain.drawNormals();
    }

    if (bLighting)      {
        ofDisableLighting();
        ofSetColor( lightColor.get() );
        light.draw();
    }
    
    ofDisableDepthTest();
    
    ofPopMatrix();
    
    cam.end();
    
    gui.draw();

}

//--------------------------------------------------------------
void ofApp::generateTerrain() {
    
    // initialize the terrain mesh
    
    terrain = Terrain(2048,2048, terrainResolution, terrainResolution);
    // terrainResolution = number of columns and rows in grid/plane mesh
    
    terrain.applyHeightMap(heightMap, 0, terrainHeight);
    
    terrain.mapTexture(textureMap.getTexture());        // color
    
    terrain.setNormalsDrawLength(5);

    terrain.setPosition(0, -terrainHeight, 0);    // move lower (to ground)
    
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
