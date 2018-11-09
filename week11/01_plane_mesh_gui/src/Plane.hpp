//
//  Plane.hpp
//  wk11_mesh
//
//  Created by Tyler Henry on 11/6/18.
//

#pragma once
#include "ofMain.h"


/*
 *  Plane is a mesh grid in 3D
        it inherits : from ofNode
 */

class Plane : public ofNode {
    
 /*
  
    ofNode is built into oF, and helps orient 3D objects in space
      it keeps track of our object's position, scale, and rotation
        as temporary "transformations" we can apply:
 
 */


public:
    
    Plane();
    
    void setup(float width, float height, float cols, float rows);
    
    void updateNoise();     // make waves on the grid
    void updateColors();     // set color based on point depth
    
    void draw();            // draw as a surface
    void drawWireframe();   // draw mesh lines
    void drawVertices();    // draw points
    
    ofMesh mesh;
    
    // ofParameters allow us to control variables
    // using ofxGui addon:
    
    ofParameter<float> noiseAmp;
    ofParameter<float> noiseFreq;
    ofParameter<glm::vec2> noiseScale;
    
    // draw settings
    ofParameter<ofColor> colorNear, colorFar;
    ofParameter<float>  vertexRadius;  // sphere drawing radius
    ofParameter<bool>   drawOrigin;
};
