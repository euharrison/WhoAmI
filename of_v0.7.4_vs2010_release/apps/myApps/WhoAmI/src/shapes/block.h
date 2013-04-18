#pragma once

#include "ofMain.h"
#include "shapeBase.h"

class block : public shapeBase
{
    
public:

    block();

    void updateMesh(float width, float height, float depth);
	void updateMaterial(int r, int g, int b);
    void draw();
    
};