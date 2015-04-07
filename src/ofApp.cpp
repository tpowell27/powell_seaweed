#include "ofApp.h"

/*
 Travis Powell
 Makin Seaweed-
    This project makes a stalk of seaweed floating to and fro.
*/

//--------------------------------------------------------------
void ofApp::setup(){
    
//  Starting point for the two x variables that move
    posx1 = 400;
    posx2 = 450;
    
//  Sets the speed for each moving x variable
    speed1 = 1.5;
    speed2 = 2;
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){

//  Moves the x postition varieble based on the speed values
    posx1+=speed1;
    posx2+=speed2;
    
//  Sets the boundaries for the movement of the two x variables
    if(posx1<=200) {
        speed1*=-1;
    }
    if(posx1>=600) {
        speed1*=-1;
    }
    if(posx2<=200) {
        speed2*=-1;
        speed1*=-1;
    }
    if(posx2>=600) {
        speed2*=-1;
        speed1*=-1;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //ofCircle(posx1,20,30);
    
//  Sets the color for the vertical polyline.
    color1.setHue(139);
    color1.setSaturation(255);
    color1.setBrightness(190);
    ofSetColor(color1);
    
//  Draws the vertical polyline
    currentPolyline.curveTo(posx1,50);
    currentPolyline.curveTo(posx1,50);
    currentPolyline.curveTo(posx2,200);
    currentPolyline.curveTo(400,600);
    currentPolyline.curveTo(400,850);
    currentPolyline.curveTo(400,850);
    currentPolyline.draw();
    polylines.push_back(currentPolyline) ;
    currentPolyline.clear();

//  Starting counter for the brightness of the horizontal polylines
    int bright = 255;
    
//  Determines where the horizontal lines need to be drawn along the vertical polyline-
//      numpoints is the number of points along the vertical polyline
//
    for (int i=0; i<polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        polyline.draw();
        
        float numPoints = polylines.size();
        for (int p=0;p<500;p+=5) {
            normalLength = (p*-1)/2.3;
            
//          Sets the color for the horizontal bars with decreasing
//              brightness from top to bottom
            bright--;
            color2.setHue(100);
            color2.setSaturation(255);
            color2.setBrightness(bright);
            ofSetColor(color2);

//          Sets the size for the horizontal polylines in descending order from top to bottom
//              point sets the space between each point
//              normal is the size of each individual horizontal polyline
            ofVec3f point = polyline.getPointAtPercent(p/500.0);
            float floatIndex = p/500.0*(numPoints-1);
            ofVec3f normal = polyline.getNormalAtIndexInterpolated(floatIndex)*normalLength;
            ofLine(point-normal/2,point+normal/2);
        }
    }
    polylines.pop_back() ;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
