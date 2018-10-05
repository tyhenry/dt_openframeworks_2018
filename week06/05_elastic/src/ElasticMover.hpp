//
//  ElasticMover.hpp
//  05_elastic
//
//  Created by Tyler Henry on 10/4/18.
//

#pragma once
#include "ofMain.h"

class ElasticMover {
    
public:
    
    // constructors
    ElasticMover();
    ElasticMover(glm::vec2 _pos, float _mass);
    
    // functions
    void applyForce(glm::vec2 force);
    void applyDampingForce(float strength);
    void applyElasticForce();   // elastic brings pos back to origPos

    void bounceWindowEdges();   // keep Mover on screen
    
    void update();
    void draw();
    
    // variables
    glm::vec2 origPos, pos, vel, acc;    // store original pos
    float mass;
    
};
