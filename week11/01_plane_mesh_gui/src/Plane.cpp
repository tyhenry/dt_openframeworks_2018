//
//  Plane.cpp
//  wk11_mesh
//
//  Created by Tyler Henry on 11/6/18.
//

#include "Plane.hpp"


Plane::Plane(){
    
}

// --------------------------------
void Plane::setup(float width, float height, float cols, float rows){
    
    // create a 3D grid mesh using ofMesh class
    
    // loop through grid rows and columns to make points
    
    for (int r = 0; r<rows; r++){
        for (int c=0; c<cols; c++){
            
            glm::vec3 pos;      // grid centered at 0,0,0
            
            float halfWidth     = width * 0.5;
            float halfHeight    = height * 0.5;
            
            pos.x = ofMap(r, 0, rows-1, -halfWidth, halfWidth);
            pos.y = ofMap(c, 0, cols-1, halfHeight, -halfHeight);    // Y+ is up in 3D!
            pos.z = 0;    // add depth later
            
            // add the point to the mesh
            mesh.addVertex(pos);
            
            // add a color for the point
            mesh.addColor(ofColor());
            
            // add triangle indices to make a square
            if (r < rows-1 && c < cols-1){
                // skip last row / col
                
                /*
                 add indices:
                 
                 make triangles to form a grid -
                 
                 1 grid square   =>     2 triangles
                 
                 A-------B          A-------B        B
                 |     / |          |     /        / |
                 |   /   |    =>    |   /   +    /   |
                 | /     |          | /        /     |
                 C-------D          C        C-------D
                 
                 A - current point
                 B - next grid column
                 C - next grid row
                 D - next grid row + col
                 
                 triangles, ordered clockwise:
                 A,B,C... B,D,C
                 
                 */

                // get current index in grid / vertices
                int index = r * cols + c;
                
                // triangle 1
                mesh.addIndex(index);               // A    - this pt
                mesh.addIndex(index + 1);           // B    - + col
                mesh.addIndex(index + cols);        // C    - + row
                
                // triangle 2
                mesh.addIndex(index + 1);           // B
                mesh.addIndex(index + 1 + cols);    // D
                mesh.addIndex(index + cols);        // C
            }
        }
    }
    
    // set default vertex radius
    vertexRadius = 1.f;
    
}


// --------------------------------
void Plane::updateNoise(){
    
    float time = ofGetElapsedTimef();
    
    for (int i=0; i<mesh.getVertices().size(); i++){
        
        // animate noise waves on vertex.z position
        
        glm::vec3& vertex = mesh.getVertices()[i];
        //  '&' - vertex is a 'reference' to the actual point in the mesh (not a copy)
        
        
        //  calc a noise value from -1 to 1
        float noise =
        ofSignedNoise ( vertex.x * noiseScale.get().x,    // x pos
                        vertex.y * noiseScale.get().y,    // y pos
                        time * noiseFreq    // time (z) to animate
                       );
        
        //  change vertex z depth based on noise and amplitude setting
        vertex.z = noise * noiseAmp;
    
    }
}


// --------------------------------
void Plane::updateColors(){
    
    // map colors based on vertex z / depth
    
    for (int i=0; i<mesh.getVertices().size(); i++){
        
        // 1 color per vertex
        glm::vec3& vertex = mesh.getVertices()[i];
        
        // get depth as percent of noise range
        float depthPercent = ofMap(vertex.z, -noiseAmp, noiseAmp, 0, 1, true);    // map 0-1

        // lerp color
        ofColor color = colorFar.get().getLerped( colorNear.get(), depthPercent );
        
        mesh.setColor(i, color);        // set mesh color
    }

}

// draw surface
// --------------------------------
void Plane::draw(){
    
    ofPushMatrix();
    
    //  we inherit from ofNode to keep track of
    //  3D position, scale and rotation
    ofTranslate( getPosition() );
    ofScale( getScale() );
    /*
            or translate, rotate and scale all at once
                using ofNode's entire 'transformation matrix':
     
            ofMultMatrix( getGlobalTransformMatrix() );
     */
    if (drawOrigin) ofDrawAxis(100);

    mesh.draw();
    
    ofPopMatrix();
}

// draw mesh
// --------------------------------
void Plane::drawWireframe(){
    ofPushMatrix();
    
    // apply ofNode translation, rotation, scale all at once:
    ofMultMatrix( getGlobalTransformMatrix() );
    if (drawOrigin) ofDrawAxis(100);

    mesh.drawWireframe();
    
    ofPopMatrix();
}

// draw points
// --------------------------------
void Plane::drawVertices(){
    
    // custom draw vertices:
    
    ofPushMatrix();
    ofMultMatrix( ofNode::getGlobalTransformMatrix() );
    if (drawOrigin) ofDrawAxis(100);
    
    for (int i=0; i<mesh.getVertices().size(); i++){
        ofPushStyle();
        // draw points as spheres
        glm::vec3 point   = mesh.getVertices()[i];
        
        if (mesh.getNumColors() > i){   // check for color
            ofSetColor( mesh.getColors()[i] );
        }
        ofDrawSphere( point, vertexRadius );

        ofPopStyle();
        
    }
    ofPopMatrix();
}





