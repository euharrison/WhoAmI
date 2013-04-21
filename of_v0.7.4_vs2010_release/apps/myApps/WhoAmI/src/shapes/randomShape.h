#pragma once

#include "ofMain.h"
#include "shapeBase.h"

class randomShape : public shapeBase
{
    
public:

    randomShape();

    void updateMesh(float width, float height, float depth);
	void updateMaterial(int r, int g, int b);
    void draw();
    
	
    ofMesh mesh2;

	ofSphere particle;

	float count;
	float vel;
};