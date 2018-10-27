//
//  PaddleCircles.cpp
//  collision_example
//
//  Created by Tyler Henry on 10/26/18.
//

#include "PaddleCircles.hpp"


// paddle constructors:

PaddleCircles::PaddleCircles()
{
    pos = glm::vec2(0);
    angleRadians = 0;
    
    // initialize the paddle
    setup();
}

PaddleCircles::PaddleCircles(glm::vec2 _pos, float angleDegrees)
{
    pos     = _pos;
    // convert degrees to radians for later:
    angleRadians   = ofDegToRad(angleDegrees);
    
    // initialize the paddle
    setup();
}

// make the paddle, using circles:

void PaddleCircles::setup()
{
    // clear current setup if needed:
    circlePositions.clear();
    circleRadii.clear();
    
    // construct the circles:
    
    // find the direction the paddle is pointing in:
    // angle to vector --> glm::vec2(cos(radians), sin(radians))
    glm::vec2 direction;
    direction.x = cos(angleRadians);
    direction.y = sin(angleRadians);
    
    for (int i=0; i<30; i++)
    {
        // decreasing circle size:
        float radius = ofMap(i, 0,29, 20,5);
        // increasing circle distance from paddle pos:
        float distance = ofMap(i, 0,29, 0,200);
        
        glm::vec2 circlePos = pos + direction * distance;
        
        // store the circle position and radius:
        circlePositions.push_back(circlePos);
        circleRadii.push_back(radius);
    }
}

// draw the paddle:

void PaddleCircles::draw()
{
    for (int i=0; i<circlePositions.size(); i++)
    {
        ofDrawCircle(circlePositions[i], circleRadii[i]);
    }
}

// rotate the paddle:

void PaddleCircles::rotate(float degrees)
{
    angleRadians += ofDegToRad(degrees);
    setup();    // reconstruct the paddle, basically
}

//

bool PaddleCircles::testCollision(glm::vec2 ballPos, float ballRadius)
{
    bool collided = false;
    // check each circle of the paddle for collision:
    for (int i=0; i<circlePositions.size(); i++)
    {
        glm::vec2 diff = circlePositions[i] - ballPos;
        float distance = glm::length(diff);
        if (distance <= circleRadii[i] + ballRadius)
        {
            // collision!
            collided = true;
            break;  // exit for loop here! we don't want to continue checking
        }
    }
    return collided;    // return the result
}









