#pragma once

#include "ofMain.h"

class shapeBase
{
    
public:
    
    ofPoint position;
    ofPoint rotation;
    
    
    
    virtual void updateMesh(float width, float height, float depth) = 0;
    virtual void draw() = 0;
    
    
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
