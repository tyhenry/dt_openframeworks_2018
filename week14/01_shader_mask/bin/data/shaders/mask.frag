//
// 	'mask.frag'
//
//	applies mask brightness to image alpha


#version 120    //  declare GLSL version
                //  120 matches OpenGL 2.3 (oF default)


//  declare input variables:

// 'varyings' supplied by 'mask.vert' shader

varying vec2 texCoordVarying;   // 2D texture coordinate

//  'uniforms' supplied by oF app (like function parameters)

uniform sampler2DRect tex0;		// 'sampler2DRect' = image texture
uniform sampler2DRect texMask;	// mask texture
uniform vec2 maskOffset;        // move mask


//  main function:
//  --------------

void main()                     // runs once on each pixel
{

    //  sample the image texture at this coordinate -
    
    vec4 color          = texture2DRect(tex0, texCoordVarying);
    
    //  sample mask at offset coords:

    vec2 maskTexCoord   = texCoordVarying + maskOffset;
    vec4 maskColor 	    = texture2DRect(texMask, maskTexCoord);
    
    //  colors are vec4(r,g,b,a), values range 0-1
    //  average the mask's rgb channels to get mask brightness

    float maskLuma	= (maskColor.r + maskColor.g + maskColor.b) / 3.0;

    
    // multiply image alpha by mask
    
    color.a *= maskLuma;    // apply mask

    
    // return the output color:
    // -----------------------
    
    gl_FragColor = color;       // set this pixel color

}
