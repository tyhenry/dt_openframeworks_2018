
//
//  wave vertex shader --
//      alters the z position of the vertices
//          using sin wave over time

#version 120

// variables

varying vec2 texCoordVarying;   // shared texture coords

// from ofApp

uniform float time;             // eg. ofGetElapsedTimef()
uniform float amp;            // scale the waves
uniform float frequency;        // wave frequency
uniform vec2 texRes;            // texture resolution (i.e. 1024x1024)


void main()
{
    // save vertex texture coords
    texCoordVarying = gl_MultiTexCoord0.xy;
    
    // get vertex position
    vec4 pos    = gl_Vertex;   // vec4 = x,y,z (and w...)
    
    // manipulate depth based on sin wave
    
    vec2 tc     = texCoordVarying / texRes;         // normalize to 0-1 range
    float dist  = distance( tc, vec2(0.5) ) * 2.;   // distance from center of texture
    pos.z      -= dist * amp;
    
//    float depth = dist * amp;
    
//    float wave  = sin( dist * frequency + time ) * depth;       // make a wave from center
//    wave       *=  dist * 2.;                                   // wave depth increases from center
//
//    pos.z      -= depth;     // apply wave to vertex z
    
    // set vertex screen position
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * pos;
    
}
