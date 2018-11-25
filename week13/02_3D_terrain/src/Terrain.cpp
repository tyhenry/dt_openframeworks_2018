//
//  Terrain.cpp
//  02_3D_terrain
//
//  Created by Tyler Henry on 11/23/18.
//

#include "Terrain.hpp"

Terrain::Terrain()
: Terrain(100,100,10,10)    // default values
{
}

// -------------------------------------------
Terrain::Terrain(float width, float depth, float cols, float rows)
:
    _width(width),
    _depth(depth),
    _cols(cols),
    _rows(rows),
    normalLength(10)
{
    // create a plane grid mesh:
    
    mesh = ofMesh::plane(width,depth,cols,rows, OF_PRIMITIVE_TRIANGLES);
    
    // this creates an X-Y plane...
    // ... but a terrain is X-Z, so we rotate all vertices:
    
    // generate a rotation matrix (-90 deg around X axis to lay flat)
    glm::mat4 rotationMatrix =
        glm::rotate( ofDegToRad(-90), glm::vec3(1,0,0) );
    
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        // transform each vertex using rotation matrix:
    
        mesh.getVertices()[i] =
            rotationMatrix * glm::vec4(mesh.getVertices()[i], 1);
        
        /* note:
            matrix multiplication requires a glm::vec4 -- ugly!
                4th value of the glm::vec4 should be 1:
                glm::vec4 myVec4 = glm::vec4( glm::vec3(), 1);
        
           also:
                the matrix comes _first_ when multiplying:
                    newVec = mat * oldVec;
         */
        
    }

    // generate the mesh normals
    updateNormals();
    
    // store these verts for future reference
    originalVerts = mesh.getVertices(); // copy
}

// -------------------------------------------
void Terrain::draw()
{
    // transform space per ofNode
    ofPushMatrix();
    ofMultMatrix( getGlobalTransformMatrix() );
    mesh.draw();
    ofPopMatrix();
}

// -------------------------------------------
void Terrain::drawWireframe()
{
    // transform space per ofNode
    ofPushMatrix();
    ofMultMatrix( getGlobalTransformMatrix() );
    mesh.drawWireframe();
    ofPopMatrix();
}

// -------------------------------------------
void Terrain::drawNormals()
{
    // transform space per ofNode
    ofPushMatrix();
    ofMultMatrix( getGlobalTransformMatrix() );
    normalLines.draw();
    ofPopMatrix();
}

// -------------------------------------------
void Terrain::applyHeightMap(ofImage& image, float minY, float maxY)
{
    // converts brightness of an image to height of terrain
    // (stretches map to fit terrain)
    
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        // mesh grid position:
        int col = i % _cols;
        int row = i / _cols;
        
        // image position:
        float x = ofMap(col, 0, _cols, 0, image.getWidth()-1, true);
        float y = ofMap(row, 0, _rows, image.getHeight()-1, 0, true);
            // invert y (2D -> 3D)
        
        // get brightness at image pixel:
        float b = image.getColor(x,y).getLightness();
        float height = ofMap(b, 0, 255, minY, maxY, true);
        
        mesh.getVertices()[i].y = height;
    }
    // alter the original verts to match
    originalVerts = mesh.getVertices();
    updateNormals();
}

// -------------------------------------------
void Terrain::mapTexture(ofTexture texture)
{
    mesh.clearTexCoords();
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        // mesh grid position:
        int col = i % _cols;
        int row = i / _cols;
        
        // texture position:
        float x = ofMap(col, 0, _cols, 0, texture.getWidth()-1, true);
        float y = ofMap(row, 0, _rows, texture.getHeight()-1, 0, true);
            // invert y (2D -> 3D)
        
        mesh.addTexCoord( glm::vec2(x,y) );
    }
}

// -------------------------------------------
void Terrain::applyNoise( glm::vec2 spatialFreq, float amplitude, float noiseZ )
{
    // spatial frequency increases roughness - noise x,y
    
    // noiseZ offsets noise - eg.
    //   noiseZ = ofGetElapsedTimef(); // animate
    
    for (int i=0; i<mesh.getVertices().size(); i++){
        
        glm::vec3& vert = mesh.getVertices()[i];
        
        glm::vec3 noisePos;
        noisePos.x = vert.x / _width * 0.5 * spatialFreq.x;
        noisePos.y = vert.z / _depth * 0.5 * spatialFreq.y;
        
        noisePos.z = noiseZ;  // apply z offset (eg. time)
        
        float noise = ofSignedNoise( noisePos ) * amplitude;
        
        vert.y = originalVerts[i].y + noise;
    }
    
    // vertices modified, update normals:
    updateNormals();
}

// -------------------------------------------
void Terrain::updateNormals()
{
    
    // make sure mesh is using correct triangle mode
    if (mesh.getMode() != OF_PRIMITIVE_TRIANGLES)
    {
        ofLogError("Terrain") << "Mesh must use ofPrimitiveMode: OF_PRIMITIVE_TRIANGLES to generate normals!";
        return;     // abort if incorrect
    }
    
    auto& verts = mesh.getVertices();
    
    
    normalLines.clear();    // extra line mesh for drawing normals
    normalLines.setMode(OF_PRIMITIVE_LINES);        // lines
    int normalIndex = 0;    // we'll use this later
    
    
    // generate vertex normals:
    // ------------------------
    
    // this code is based mainly on Zach Lieberman's
    // ofxMeshUtils addon:
    // https://github.com/ofZach/ofxMeshUtils/blob/master/src/ofxMeshUtils.cpp#L32-L58
    
    
    // reset current normals
    mesh.clearNormals();
    mesh.addNormals( vector<glm::vec3>(verts.size()) );
    // 1 normal per vertex

    
    // loop through the triangles
    for( int i=0; i+2 < mesh.getIndices().size(); i+=3 )
    {
        
        // 3 vertices per triangle
        const int va = mesh.getIndices()[i];
        const int vb = mesh.getIndices()[i+1];
        const int vc = mesh.getIndices()[i+2];
        
        // calculate triangle face normal:
        // cross product of two edges
        glm::vec3 e1 = verts[va] - verts[vb];
        glm::vec3 e2 = verts[vc] - verts[vb];
        glm::vec3 nml = glm::normalize(glm::cross(e2,e1));
        
        // depending on your clockwise / winding order, you might want to reverse the e2 / e1 above if your normals are flipped.
        
        // distribute face normal to 3 vertex normals:
        mesh.getNormals()[va] += nml;    // *add* face normal
        mesh.getNormals()[vb] += nml;    // to each vertex -
        mesh.getNormals()[vc] += nml;    // averages faces
        
        // extra --
        // store the face normal as a line
        // in normalLines mesh for drawing
        // -- normalLines mesh uses OF_PRIMITIVE_LINES mode
        
        glm::vec3 faceCenter = getTriangleCenter(verts[va],verts[vb],verts[vc]);
        glm::vec3 normalEnd = faceCenter + nml * normalLength;
        
        // 1 line = 2 vertices, 2 indices
        normalLines.addVertex(faceCenter);
        normalLines.addVertex(normalEnd);
        normalLines.addIndex(normalIndex);
        normalLines.addIndex(normalIndex+1);
        normalIndex += 2;   // increment
    }
}

void Terrain::transformVertices(glm::mat4 transform)
{
    /*
     modify all the vertices by some transformation matrix:
     glm::mat4 represents scale, rotation, and translation (move)

     
        // to rotate mesh 180 deg (3.14 radians) around Y:
        glm::mat4 transform = glm::rotate( PI, glm::vec3(0,1,0) );
     
     */
    
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        // transform each vertex using matrix multiplication:
        
        glm::vec4 vert = glm::vec4( mesh.getVertices()[i], 1 );
        mesh.getVertices()[i] = transform * vert;
        
        /*
         note - matrix multiplication requires a glm::vec4() -- ugly!
         
         fourth value of the glm::vec4 should be 1 --
           glm::vec4 myVec4 = glm::vec4( glm::vec3(), 1);
         
         also:
         the matrix comes _first_ when multiplying:
         newVec = matrix * oldVec;
         */
        
    }
    
    // generate the mesh normals
    updateNormals();
    
    // store these verts for future reference
    originalVerts = mesh.getVertices(); // copy
    
}


// helper function:
// -------------------------------------------
glm::vec3 Terrain::getTriangleCenter(glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
    // center of a triangle:
    // 2/3 from point to center of opposite edge
    glm::vec3 edgePt = (b + c) * 0.5;     // middle b_c edge
    return a * .333f + edgePt * .667f;    // lerp 2/3 a --> edgePt
}


