#include "ofApp.h"

// some constants for later -
// - minimum / maximum valid float values:
const float FLOAT_MIN = std::numeric_limits<float>::min();
const float FLOAT_MAX = std::numeric_limits<float>::max();


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(127);
    
    // make any ofPath shape
    
    // example: make a daisy -- 8 petals
    path = generateDaisy( 8, ofGetHeight()*.5, 50 );

    
    // convert ofPath to an ofMesh:
    
    mesh = path.getTessellation();
        // "tessellation" calcs mesh triangles
    
    // note: this function is easy, but has limitations!
    //  the kinds of meshes it generates don't play well with vertex shaders
    //      - fragment shaders and textures should be fine
    
    cout << "mesh stats: " << endl  // print info on our mesh
         << "- vertices:  \t" << mesh.getVertices().size() << endl
         << "- indices:   \t" << mesh.getIndices().size() << endl
        << "- texcoords: \t" << mesh.getTexCoords().size() << endl;
    
    
    
    // note --
    //  path.getTessellation() doesn't create texture coordinates
    //      here's one technique to do that manually:
    
    
    // calc a 2D bounding rectangle around mesh
    
    // find the minimum and maximum x,y values of mesh:
    float left      = FLOAT_MAX;        // find least x
    float top       = FLOAT_MAX;        // find least y
    float right     = FLOAT_MIN;        // find greatest x
    float bottom    = FLOAT_MIN;        // find greatest y
    
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        glm::vec3 vertex = mesh.getVertices()[i];
        left    = min(left, vertex.x);  // store lower val
        top     = min(top, vertex.y);
        right   = max(right, vertex.x); // store higher val
        bottom  = max(bottom, vertex.y);
    }
    
    // store rectangle bounds
    bounds = ofRectangle( glm::vec2(left,top), glm::vec2(right,bottom));
    
    
    
    // map texture coordinates to mesh points
    //    based on bounds:
    
    image.load("fractal.jpg");      // our texture
    float imgW  = image.getWidth();
    float imgH  = image.getHeight();
    
    for (int i=0; i<mesh.getVertices().size(); i++)
    {
        glm::vec3 vertex = mesh.getVertices()[i];
        
        // map the x,y bounds to image coordinates:
        float x = ofMap(vertex.x, left, right, 0, imgW);
        float y = ofMap(vertex.y, top, bottom, 0, imgH);
        
        mesh.addTexCoord( glm::vec2(x,y) );
    }

    
    
    // print info:
    cout << "added " << mesh.getTexCoords().size() << " texcoords";
    
    
    
    // load a shader --
    //   shader.frag will color the mesh with a gradient + image
    //   shader.vert doesn't do anything
    
    shader.load("shader.vert", "shader.frag");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (startTime == 0) startTime = ofGetElapsedTimef();
    
    
    if (animating) {
        float time = ofGetElapsedTimef() - startTime;
            // time since first update()
        
        // animate colors:
        colorMix = cos(time*.2) * -0.5 + 0.5;
            // oscillates 0-1
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    ofEnableDepthTest();
    
    
    glm::vec2 imageSize = glm::vec2( image.getWidth(), image.getHeight() );
    
    
    // draw the path mesh with a custom gradient + texture:
    
    shader.begin();
    shader.setUniformTexture( "tex", image.getTexture(), 0);
    shader.setUniform2f( "texRes", imageSize ); // resolution
    shader.setUniform1f( "texMix", colorMix);   // lerp color
    
    mesh.draw();
    shader.end();
    
//    ofSetColor(0, 170);
//    mesh.drawWireframe();   // show the mesh wireframe
    
    
    ofSetColor(255,0,255);
    ofNoFill();
    ofDrawRectangle( bounds );  // draw mesh bounds
    ofFill();
    
    ofDisableDepthTest();
    cam.end();
    
    
    string message;
    if (animating) {
        message = "press 'a' to toggle animating color mix: ";
    } else {
        message = "press UP/DOWN to adjust color mix: ";
    }
    ofDrawBitmapStringHighlight( message + ofToString(colorMix), 20, 20);
}


// example to generate an ofPath "daisy" / "rosette" shape:
//--------------------------------------------------------------

ofPath ofApp::generateDaisy( int numPetals, float petalLength, float centerRadius ){
    
    ofPath daisy;
    
    // make a circle, but modulate the radius to make "petals"
    
    for( float degree = 0; degree < 360; degree += 1.0 )
    {
        // angle in radians
        float angle   = ofDegToRad(degree);
        
        // oscillate -1 to 1 per petal
        float radius    = sin(angle * numPetals);
        
        // scale from -1:1 to inner radius / petal length
        radius  = ofMap(radius, -1, 1, centerRadius, petalLength);
        
        glm::vec2 pt;   // calc point along modulated circle
        pt.x        = radius * cos( angle );
        pt.y        = radius * sin( angle );
        
        if (degree == 0) {
            daisy.moveTo(pt);    // move to starting point
        }
        else {
            daisy.curveTo(pt);   // or curve to next point
        }
    }
    daisy.close();   // finish the shape (complete the outline)
    return daisy;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'a' || key == 'A'){
        animating = !animating; // toggle color animation
    }
    else if (!animating){
        
        // manually adjust color mix:
        if (key == OF_KEY_DOWN){
            colorMix -= .01;    // shift mix towards gradient
            colorMix = ofClamp(colorMix, 0, 1);  // limit 0-1
        }
        else if (key == OF_KEY_UP){
            colorMix += .01;    // shift mix towards texture
            colorMix = ofClamp(colorMix, 0, 1);  // limit 0-1
        }
    }
}

