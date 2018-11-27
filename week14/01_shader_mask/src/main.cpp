#include "ofMain.h"
#include "ofApp.h"


//========================================================================
int main( ){
    
    
    /*
     OpenGL window setup:
     
     oF loads openGL 2.3 by default -- widely supported but very old

     to load a newer version of openGL (eg. 3.3 or 4.1):
     
     remove ofSetupOpenGL() below and
     uncomment following lines
     
    */
    
    ofSetupOpenGL(1280,960,OF_WINDOW); // <-- default openGL 2.3 setup
    
    // OR use newer OpenGL 3.3 or 4.1:
    
//     ofGLWindowSettings settings;
//     settings.setGLVersion(3,3);    // OpenGL v3.3 (macOS max: 4.1)
//     settings.setSize(1280,960);
//     settings.windowMode = OF_WINDOW;
//     ofCreateWindow(settings);
    
    
    
    // start the app:
    ofRunApp(new ofApp());
    
    
    /*
     NOTE on OpenGL versions:
     ------------------------
     
     different OpenGL versions
     use different GLSL (shader) code versions:
     
     OpenGL 2     --> GLSL version 150
     OpenGL 3.3   --> GLSL version 330
     OpenGL 4.1   --> GLSL version 410
     
     more info:
     https://github.com/mattdesl/lwjgl-basics/wiki/GLSL-Versions#glsl-versions
     */
    

}



