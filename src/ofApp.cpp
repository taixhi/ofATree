#include "ofApp.h"
#include "line.hpp"
#include "flower.hpp"
vector<Line> lines;
vector<Line> immutableLines;
vector<Line> nLines;
vector<Flower> flowers;
int generation = 1;
int frame = 0;
int maxGeneration = 6;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(239, 241, 228);
    ofEnableAntiAliasing();
    if(lines.size() == 0){
        Line line = Line(ofGetWindowWidth()/4, ofGetWindowHeight(), ofGetWindowWidth()/4, 100, 32);;
        Line line2 = Line(ofGetWindowWidth()*3/4, ofGetWindowHeight(), ofGetWindowWidth()*3/4, 200, 32);;
        lines.push_back(line);
        lines.push_back(line2);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i  < flowers.size(); i++){
        if(frame % 20 == 0){
            flowers[i].update();
        }
    }
    if(frame > 240 && generation < 6){
        nLines.clear();
        for(int i = 0; i < lines.size(); i++){
            vector<Line> tempLines;
            vector<Flower> tempFlowers;
            tie(tempLines, tempFlowers) = lines[i].generate(PI/4, generation);
            immutableLines.push_back(tempLines.front());
            tempLines.erase(tempLines.begin());
            nLines.insert(nLines.end(), tempLines.begin(), tempLines.end());
            flowers.insert(flowers.end(), tempFlowers.begin(), tempFlowers.end());
        }
        lines = nLines;
        generation = generation+1;
        frame = 0;
    }else if(frame > 2400 && generation >= 6){
        lines.clear();
        flowers.clear();
        immutableLines.clear();
        Line line = Line(ofGetWindowWidth()/4, ofGetWindowHeight(), ofGetWindowWidth()/4, 100, 32);;
        Line line2 = Line(ofGetWindowWidth()*3/4, ofGetWindowHeight(), ofGetWindowWidth()*3/4, 200, 32);;
        lines.push_back(line);
        lines.push_back(line2);
        generation = 0;
    }else{
        frame++;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < immutableLines.size(); i++){
        immutableLines[i].draw();
    }
    for(int i = 0; i < lines.size(); i++){
        lines[i].draw();
    }
    for(int i = 0; i < flowers.size(); i++){
        flowers[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        lines.clear();
        immutableLines.clear();
        Line line = Line(ofGetWindowWidth()/4, ofGetWindowHeight(), ofGetWindowWidth()/4, 100, 32);;
        Line line2 = Line(ofGetWindowWidth()*3/4, ofGetWindowHeight(), ofGetWindowWidth()*3/4, 200, 32);;
        lines.push_back(line);
        lines.push_back(line2);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    nLines.clear();
    for(int i = 0; i < lines.size(); i++){
        vector<Line> tempLines;
        vector<Flower> tempFlowers;
        tie(tempLines, tempFlowers) = lines[i].generate(PI/4, generation);
        flowers.insert(flowers.end(), tempFlowers.begin(), tempFlowers.end());
        immutableLines.push_back(tempLines.front());
        tempLines.erase(tempLines.begin());
        nLines.insert(nLines.end(), tempLines.begin(), tempLines.end());
    }
    lines = nLines;
    generation = generation+1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
