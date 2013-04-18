#pragma once

#include "ofxKinectNui.h"
#include "ofMain.h"
#include "characters\characterBase.h"
#include "shapes\block.h"

#define MAX_RESHAPES 3

class monstro1 : public characterBase
{
    
public:
    
    monstro1();
    
    void update();
    void reshape();
    
};