#pragma once

#include "ofMain.h"
#include "shapes\shapeBase.h"


#define HEAD            0
#define ARM_LEFT        1
#define FOREARM_LEFT    2
#define HAND_LEFT       3


class characterBase
{
    
public:
    
    ofPoint position;
    
    shapeBase * shapes[20];
    
    void update();
    void draw();
    
    
};