#include "sphere.h"

sphere::sphere()
{

}

void sphere::updateMesh(float width, float height, float depth)
{
	radius = width;
}

void sphere::updateMaterial(int r, int g, int b)
{
	//TODO desenvolver
    material.setEmissiveColor(ofColor(r,g,b));
    material.setSpecularColor(ofColor(255,255,255));
    material.setShininess(60);   
}

void sphere::draw()
{
    beginDraw();
    
	ofGetCurrentRenderer()->drawSphere(0,0,0,radius);
    
    endDraw();
}