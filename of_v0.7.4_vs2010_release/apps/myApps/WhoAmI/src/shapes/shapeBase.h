#pragma once

#include "ofMain.h"

class shapeBase
{
    
public:
    
    ofPoint position;
    ofPoint rotation;
    
	virtual void updateMesh(float width, float height, float depth) {};
	virtual void updateMaterial(int r, int g, int b) {};
	virtual void draw() {};
    
    
protected:
    
    float width;
    float height;
    float depth;
    
    ofMaterial material;
    ofMesh mesh;
    ofShader shader;
    
    
    void beginDraw();
    void endDraw();
    
};