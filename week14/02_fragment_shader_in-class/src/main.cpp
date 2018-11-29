#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    
    //  oF defaults to OpenGL 2.1 -
    //      requires shaders written in GLSL #version 120
    ofSetupOpenGL(1280,720,OF_WINDOW); // <--- setup the GL context
    
    //  use OpenGL 3.3 (better) -
    //      requires GLSL #version 150 (or #version 330)
    
//    ofGLWindowSettings settings;
//    settings.setGLVersion( 3 , 3 );       // OpenGL 3.3
//    settings.setSize(1920,1080);
//    settings.windowMode = OF_WINDOW;      // or OF_FULLSCREEN
//    ofCreateWindow(settings);             // create your window

    
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
