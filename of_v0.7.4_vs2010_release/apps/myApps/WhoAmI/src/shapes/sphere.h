#pragma once

#include "ofMain.h"
#include "shapeBase.h"

class sphere : public shapeBase
{
    
public:

	float radius;

    sphere();

    void updateMesh(float width, float height, float depth);
	void updateMaterial(int r, int g, int b);
    void draw();
    
};