//
//  VectorField.cpp
//  wk09_vector_field
//
//  Created by Tyler Henry on 10/23/18.
//

#include "VectorField.hpp"

VectorField::VectorField()
{
    rows = 0;
    cols = 0;
    width = 0;
    height = 0;
}

VectorField::VectorField(int _rows, int _cols, float _width, float _height)
{
    rows = _rows;
    cols = _cols;
    width = _width;
    height = _height;
    
    for (int i=0; i<rows*cols; i++){
        field.push_back( glm::vec2(0) );
    }

}

void VectorField::setFieldRandomly()
{
    for (int i=0; i<field.size(); i++){
        field[i].x = ofRandom(-0.5, 0.5);
        field[i].y = ofRandom(-0.5, 0.5);
    }
}

void VectorField::setFieldNoisily(float scale)
{
    for (int row=0; row<rows; row++){
        for (int col=0; col<cols; col++){
            
            int index = row * cols + col;
            
            glm::vec2 vec;
            float time = ofGetElapsedTimef() * 0.5;
            float noise = ofNoise( row * 0.1, col * 0.1, time );
            float angle = ofMap(noise, 0, 1, 0, TWO_PI);
            vec = glm::vec2( cos(angle), sin(angle) );
            
            vec *= scale;
            field[index] = vec;
        }
    }
}

glm::vec2 VectorField::getForceAtPos(glm::vec2 pos)
{
    if (pos.x < 0 || pos.x > width || pos.y < 0 || pos.y > height){
        return glm::vec2(0);
    }
    
    float row = ofMap(pos.x, 0, width, 0, rows-1);
    float col = ofMap(pos.y, 0, height, 0, cols-1);
    int index = round(row) * cols + round(col);

    return field[index];
}


void VectorField::draw(float scale)
{
    
    ofPushStyle();
    ofSetColor(255);
    
    for (int row=0; row<rows; row++){
        for (int col=0; col<cols; col++){
            
            glm::vec2 pos;
            pos.x = ofMap(col, 0, cols-1, 0, width);
            pos.y = ofMap(row, 0, rows-1, 0, height);
            
            int index = row * cols + col;
            glm::vec2 vec = field[index];
            ofDrawCircle(pos, 1);
            ofDrawLine(pos, pos + vec * scale);
        }
    }
    
    ofPopStyle();
    
}
