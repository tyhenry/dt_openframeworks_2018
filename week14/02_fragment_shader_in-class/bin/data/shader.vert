//
// this is the default vertex shader --

#version 120

varying vec2 texCoordVarying;   // shared variable

void main()
{
    
    // save vertex texture coords
    texCoordVarying = gl_MultiTexCoord0.xy;
    
    // set vertex screen position
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
    
}
