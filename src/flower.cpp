//
//  flower.cpp
//  aTree
//
//  Created by Taichi Kato on 27/1/19.
//

#include "flower.hpp"
#include "ofApp.h"

void Flower::setup(){
    
}
void Flower::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, radius);
}
void Flower::update(){
    if(isFalling){
        y_velocity += y_acceleration;
        y += y_velocity;
        x_velocity += x_acceleration;
        x += x_velocity;
    }else{
        if(radius >= maxRadius){
            isFalling = true;
        }else{
            radius_velocity += radius_acceleration;
            radius += radius_velocity;
        }
    }
}

Flower::Flower(int x, int y, int r, ofColor c) : x(x), y(y), color(c){
    frame = 0;
    radius = 0;
    isFalling = false;
    maxRadius = 5;
    y_velocity = 0;
    y_acceleration = ofRandom(5, 12)/30;
    x_velocity =  0;
    x_acceleration = ofRandom(-1, 1)/30;
    radius_velocity =  0;
    radius_acceleration = ofRandom(2,5)/120;
}
