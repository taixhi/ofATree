//
//  flower.hpp
//  aTree
//
//  Created by Taichi Kato on 27/1/19.
//

#ifndef flower_hpp
#define flower_hpp

#include <stdio.h>
#include "ofApp.h"
class Flower {
public:
    void setup();
    void draw();
    void update();
    
    int frame;
    
    int x;
    float x_velocity;
    float x_acceleration;
    int y;
    float y_velocity;
    float y_acceleration;
    int radius;
    float radius_velocity;
    float radius_acceleration;
    int maxRadius;
    bool isFalling;
    ofColor color;
    Flower(int x, int y, int r, ofColor c);
};

#endif /* flower_hpp */
