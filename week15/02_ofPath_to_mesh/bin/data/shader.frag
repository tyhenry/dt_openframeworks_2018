//
//  fragment shader --
//      - color spectrum based on texture coords
//      - mix with an image texture

#version 120        // we are using OpenGL 2.1 (oF default)

// from vertex shader:
varying vec2 texCoordVarying;   // texture coords

// from ofApp:
uniform sampler2DRect tex;      // texture
uniform vec2 texRes;            // texture resolution (i.e. 1024x1024)
uniform float texMix;           // color mix amount (0-1)

void main()
{
    // generate color spectrum based on texture coordinates:
    
    vec2 tc     = texCoordVarying / texRes;         // normalize to 0-1 range
    float dist  = distance( tc, vec2(0.5) ) * 2.;   // distance from center of texture
    vec4 color  = vec4( dist, 1.-dist, 0., 1. );
    
    // mix color with actual sampled texture color:
    vec4 texColor   = texture2DRect( tex, texCoordVarying );
    color       = mix(color, texColor, texMix);     // mix (lerp between) two colors
    
    // assign color to our pixel
    gl_FragColor    = color;
    
}



