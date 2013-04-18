#pragma once

#include "ofMain.h" 
#include "shapes\shapeBase.h"

class characterBase
{
    
public:
    
    ofPoint position;
    shapeBase * shapes[20];

	virtual void update(){};
	virtual void updateSkeleton(ofPoint skeletonPoints[20]);
    void draw();
    
};