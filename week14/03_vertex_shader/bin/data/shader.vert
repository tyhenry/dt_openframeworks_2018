
//
//  wave vertex shader --
//      alters the z position of the vertices
//          using sin wave over time

#version 120

// variables

varying vec2 texCoordVarying;   // shared texture coords

// from ofApp

uniform float time;             // eg. ofGetElapsedTimef()
uniform float depth;            // scale the waves

void main()
{
    
    // save vertex texture coords
    texCoordVarying = gl_MultiTexCoord0.xy;
    
    // get vertex position
    vec4 pos = gl_Vertex;   // vec4 = x,y,z (and w...)
    
    
    // manipulate depth based on sin wave
    //  wave travels along x
    
    float x = texCoordVarying.x * 15.f;  // arbitrary scale
    
    pos.z += sin( x + time ) * depth;
    
    // set vertex screen position
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
    
}
