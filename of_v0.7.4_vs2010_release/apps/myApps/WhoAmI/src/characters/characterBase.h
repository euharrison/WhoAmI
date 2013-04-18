#pragma once

#include "ofMain.h"
#include "shapes\shapeBase.h"

#define UMBIGO 0

class characterBase
{
    
public:
    
    ofPoint position;
    shapeBase * shapes[20];

	virtual void update(){};

	void updateSkeleton(ofPoint skeletonPoints[20]);
    void draw();
    
};