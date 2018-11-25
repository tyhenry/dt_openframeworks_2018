//
//  Terrain.hpp
//  02_3D_terrain
//
//  Created by Tyler Henry on 11/23/18.
//

#pragma once
#include "ofMain.h"

class Terrain : public ofNode {
    
public:
    
    Terrain();
    Terrain(float width, float depth, float cols, float rows);
    
    
    void applyHeightMap(ofImage& image, float minY, float maxY);
    void mapTexture(ofTexture texture);
    
    void applyNoise( glm::vec2 spatialFreq, float amplitude, float noiseZ = 0.f );
    void updateNormals();
    
    void transformVertices(glm::mat4 transform);
    
    void draw();
    void drawWireframe();
    void drawNormals();
    
    void setNormalsDrawLength(float length, bool update=true) {
        normalLength = length;
        updateNormals();
    }
    
    glm::vec3 getTriangleCenter(glm::vec3 a, glm::vec3 b, glm::vec3 c);
    
    ofMesh& getMesh() { return mesh; }  // return ref to mesh
    
private:
    
    ofMesh mesh;
    
    ofMesh normalLines; // for drawing normals
    float normalLength; // scale for drawing
    
    float _width, _depth;
    int _rows, _cols;
    
    vector<glm::vec3> originalVerts;
    
};
