//
//  mask fragment shader --
//
//  multiply one texture's alpha channel
//      by another texture's brightness


#version 120        // we are using OpenGL 2.1 (oF default)


//  declare variables:


//  `varying` = supplied by vertex shader

varying vec2 texCoordVarying;       // 2D texture coordinates


//  `uniform` = supplied by oF app (these are constants)

uniform sampler2DRect tex0;         // oF image texture
uniform sampler2DRect texMask;      // 2nd mask texture




void main()             // main() is the start (like C++)
{
    
    //  sample the 2 input textures
    
    vec4 color      = texture2DRect( tex0, texCoordVarying );
    vec4 mask       = texture2DRect( texMask, texCoordVarying );
    
    //  color is a vec4 (r,g,b,a) with range 0.-1.

    
    
    // mask:
    
    // calc mask brightness - average the r,g,b channels:
    
    float maskAmt   = ( mask.r + mask.g + mask.b ) / 3.0;
    
    // apply mask to image alpha
    
    color.a         *= maskAmt;  // multiply
    
    
    
    // assign our final pixel color:
    
    gl_FragColor    = color;
    
    
    
    // NOTE:
    // uncomment code below to help debug broken shaders
    
    // draw color spectrum across 640x480 texture coords:
    
//    vec2 tc           = texCoordVarying;
//    tc.x              = tc.x / 640.0;       // normalize 0-1
//    tc.y              = tc.y / 480.0;
//    gl_FragColor      = vec4(tc.x, tc.y, 0., 1.);

    
    // or set all pixels red:
    
//    gl_FragColor      = vec4(1.,0.,0.,1.);

    
    
}



