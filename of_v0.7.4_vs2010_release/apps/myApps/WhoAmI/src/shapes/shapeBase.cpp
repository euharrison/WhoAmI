#include "shapeBase.h"


void shapeBase::updateMesh(float width, float height, float depth)
{

}
	
void shapeBase::draw() 
{

}


void shapeBase::beginDraw()
{
    ofPushMatrix();
    
    ofTranslate(position);
    ofRotateX(rotation.x);
    ofRotateY(rotation.y);
    ofRotateZ(rotation.z);
    
    material.begin();
}

void shapeBase::endDraw()
{
    material.end();
    
    ofPopMatrix();
}