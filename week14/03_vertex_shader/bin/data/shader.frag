//
//  basic fragment shader --
//      color spectrum based on texture coords

#version 120        // we are using OpenGL 2.1 (oF default)

// from vertex shader:
varying vec2 texCoordVarying;       // texture coords

void main()
{
    
    vec2 tc    = texCoordVarying;   // should be 0-1 range
    
    //  map to color values (also 0-1)
    vec4 color = vec4( tc.x, tc.y, 0., 1.);
    
    // assign color to our pixel
    gl_FragColor    = color;
    
}



