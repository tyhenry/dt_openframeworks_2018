#pragma once
#include "ofMain.h"

class Ball {
public:
    void setup(glm::vec2 _pos, float _radius);
    void update();
    void draw();
    
    void reflect(glm::vec2 line);
    /*
       v
        \
         \   *
          \ /
      -----|-----> line
     
     http://www.3dkingdoms.com/weekly/weekly.php?a=2
     
     */
    
    glm::vec2 pos, vel, acc;
    float radius;
    
};

