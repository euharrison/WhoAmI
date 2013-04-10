#pragma once

#include "ofMain.h"

class shapeBase
{
    
public:
    
    ofPoint position;
    ofPoint rotation;
    
	virtual void updateMesh(float width, float height, float depth) {};
	virtual void draw() {};
    
    
protected:
    
    float width;
    float height;
    float depth;
    
    ofMaterial material;
    ofMesh mesh;
    
    
    void beginDraw();
    void endDraw();
    
};