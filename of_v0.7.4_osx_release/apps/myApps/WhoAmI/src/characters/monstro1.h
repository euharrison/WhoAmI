#pragma once

#include "ofMain.h"
#include "characterBase.h"
#include "block.h"

#define MAX_RESHAPES 3
class monstro1 : public characterBase
{
    
public:
    
    monstro1();
    
    void update();

    void reshape();

};
