#pragma once

#include "ofMain.h"
#include "shapeBase.h"

class block : public shapeBase
{
    
public:
    
    void updateMesh(float width, float height, float depth);
    void draw();
    
};