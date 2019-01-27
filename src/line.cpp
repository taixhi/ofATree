//
//  line.cpp
//  aTree
//
//  Created by Taichi Kato on 25/1/19.
//

#include "line.hpp"
#include "ofApp.h"
#include "flower.hpp"

void Line::setup(){
    
}
void Line::draw(){
    ofSetColor(46, 189, 189, alpha);
    ofSetLineWidth(thickness);
    ofDrawLine(x1, y1, x2, y2);
}
void Line::update(){
    
}
Line::Line(int a, int b, int c, int d, int g){
    alpha = ofRandom(128,255);
    thickness = g;
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
}

tuple<vector<Line>, vector<Flower>> Line::generate(float angle, int generation){
    int len = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    int v = 40;
    //     \       /
    //    C \     / B
    //       \   /
    //        \ /
    //         |
    //         |
    //         | A
    //         |
    vector<Line> lines;
    int midX = abs(x1 + x2)/2;
    int midY = abs(y1 + y2)/2;
    vector<Flower> flowers;
    //Line A
    lines.push_back(Line(x1, y1, midX, midY, thickness));
    //Line B
    int bX = (x2-midX)*cos(angle)-(y2-midY)*sin(angle)+midX + ofRandom(-v, v);
    int bY = (y2-midY)*cos(angle)+(x2-midX)*sin(angle)+midY + ofRandom(-v,v);
    if((midY-bY) > -40){
        lines.push_back(Line(midX, midY, bX, bY, thickness/3*2));
        if(generation == 5){
            flowers.push_back(Flower(bX, bY, 10, ofColor(255, 0, 0, 128)));
        }
    }
    //Line C
    int cX = (x2-midX)*cos(-angle)-(y2-midY)*sin(-angle) + midX + ofRandom(-v, v);
    int cY = (y2-midY)*cos(-angle)+(x2-midX)*sin(-angle) + midY + ofRandom(-v, v);
    if((midY-cY) > -40){
        lines.push_back(Line(midX, midY, cX, cY, thickness/3*2));
        if(generation == 5){
            flowers.push_back(Flower(cX, cY, 10, ofColor(255, 0, 0, 128)));
        }
    }
    return(make_tuple(lines, flowers));
}
