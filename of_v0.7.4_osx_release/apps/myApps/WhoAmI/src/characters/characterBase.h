#pragma once

#include "ofMain.h"
#include "shapeBase.h"


#define TOTAL_SHAPES 14

#define HEAD            0
#define BODY            1

#define ARM_LEFT        2
#define FOREARM_LEFT    3
#define HAND_LEFT       4
#define THIGH_LEFT      5
#define LEG_LEFT        6
#define FOOT_LEFT       7

#define ARM_RIGHT       8
#define FOREARM_RIGHT   9
#define HAND_RIGHT      10
#define THIGH_RIGHT     11
#define LEG_RIGHT       12
#define FOOT_RIGHT      13


class characterBase
{
    
public:
    
    ofPoint position;
    
    shapeBase * shapes[TOTAL_SHAPES];
    
    void update();
    void draw();
    
    
};
