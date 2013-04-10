#pragma once

#include "ofMain.h"

class characterBase
{
    
public:
    
    ofPoint position;
    
    ofPoint head;
    
    ofPoint shoulder_left;
    ofPoint elbow_left;
    ofPoint hand_left;
    ofPoint leg_left;
    ofPoint knee_left;
    ofPoint foot_left;
    
    ofPoint shoulder_right;
    ofPoint elbow_right;
    ofPoint hand_right;
    ofPoint leg_right;
    ofPoint knee_right;
    ofPoint foot_right;
    
    
    ofMaterial material;
    
    
    characterBase();
    
    void draw();
    
};
