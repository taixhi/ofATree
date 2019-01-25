//
//  line.hpp
//  aTree
//
//  Created by Taichi Kato on 25/1/19.
//

#ifndef line_hpp
#define line_hpp

#include <stdio.h>
#include "ofApp.h"
class Line {
public:
    void setup();
    void draw();
    void update();
    
    int x1;
    int y1;
    int x2;
    int y2;
    int thickness;
    int alpha;
    ofColor color;
    Line(int a, int b, int c, int d, int g);
    vector<Line> generate(float angle, int generation);
};

#endif /* line_hpp */
