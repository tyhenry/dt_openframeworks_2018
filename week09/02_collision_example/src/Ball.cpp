#include "Ball.h"

// --------------------------------------------------------
void Ball::setup(glm::vec2 _pos, float _radius){
    
    pos = _pos;
    radius = _radius;
    
}

// --------------------------------------------------------
void Ball::update(){
    
    pos += vel;
    
    // bounce:
    
    if(pos.x > ofGetWidth()){
        
        pos.x = ofGetWidth();
        vel.x *= -1;
        
    }
    else if (pos.x < 0){

        pos.x = 0;
        vel.x *= -1;
    }
    
    
    if(pos.y > ofGetHeight()){

        pos.y = ofGetHeight();
        vel.y *= -1;
    }
    else if (pos.y < 0){

        pos.y = 0;
        vel.y *= -1;
    }

}

// --------------------------------------------------------
void Ball::draw(){
    ofDrawCircle(pos, radius);
}

// --------------------------------------------------------
void Ball::reflect(glm::vec2 line){
    
    /*
      v
       \
        \   *
         \ /
     -----|-----> line
     
     http://www.3dkingdoms.com/weekly/weekly.php?a=2
     
     reflected vector = V - 2*(V dot N)*N
     
     V = original vector (ball velocity)
     N = "normal" of the line (a "normal" is a perpendicular unit vector)
     
     note: (V dot N) is the "dot product" of V and N vectors
            ( (x,y) dot (a,b) ==> x * a + y * b )
     
    
     1. find the normal of the line:
     
           n
           ↑
        -------> vector (line)
     
        normal of vector(x,y) = (-y,x) / length
        https://stackoverflow.com/a/1243676
    
     */
    float length = glm::length(line);
    if (length != 0){
        // normal of line = (y,-x) / length
        glm::vec2 normal = line * glm::vec2(1,-1) / length;
        // reflected vector = -2*(V dot N)*N + V
        vel = 2*glm::dot(vel,normal)*normal - vel;
        
    }
    
    
}
