#include "block.h"

block::block()
{

}

void block::updateMesh(float width, float height, float depth)
{
	
    
    //TODO implementar a manipulacao do material
    material.setEmissiveColor(ofColor(255,0,0));
    material.setSpecularColor(ofColor(255,0,0));
    material.setShininess(60);
    
    
    
	mesh.clear();
    
    ofVec3f vertices[] = {
        ofVec3f(+width,-height,+depth), ofVec3f(+width,-height,-depth), ofVec3f(+width,+height,-depth), ofVec3f(+width,+height,+depth),
        ofVec3f(+width,+height,+depth), ofVec3f(+width,+height,-depth), ofVec3f(-width,+height,-depth), ofVec3f(-width,+height,+depth),
        ofVec3f(+width,+height,+depth), ofVec3f(-width,+height,+depth), ofVec3f(-width,-height,+depth), ofVec3f(+width,-height,+depth),
        ofVec3f(-width,-height,+depth), ofVec3f(-width,+height,+depth), ofVec3f(-width,+height,-depth), ofVec3f(-width,-height,-depth),
        ofVec3f(-width,-height,+depth), ofVec3f(-width,-height,-depth), ofVec3f(+width,-height,-depth), ofVec3f(+width,-height,+depth),
        ofVec3f(-width,-height,-depth), ofVec3f(-width,+height,-depth), ofVec3f(+width,+height,-depth), ofVec3f(+width,-height,-depth)
    };
    mesh.addVertices(vertices,24);
    
    static ofVec3f normals[] = {
        ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0),
        ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0),
        ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1),
        ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0),
        ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0),
        ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1)
    };
    mesh.addNormals(normals,24);
    
    static ofVec2f tex[] = {
        ofVec2f(1,0), ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1),
        ofVec2f(1,1), ofVec2f(1,0), ofVec2f(0,0), ofVec2f(0,1),
        ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0), ofVec2f(0,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0)
    };
    mesh.addTexCoords(tex,24);
    
    static ofIndexType indices[] = {
        0,1,2, // right top left
        0,2,3, // right bottom right
        4,5,6, // bottom top right
        4,6,7, // bottom bottom left
        8,9,10, // back bottom right
        8,10,11, // back top left
        12,13,14, // left bottom right
        12,14,15, // left top left
        16,17,18, // ... etc
        16,18,19,
        20,21,22,
        20,22,23
    };
    mesh.addIndices(indices,36);
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

}


void block::draw()
{
    beginDraw();
    
    ofGetCurrentRenderer()->draw(mesh,mesh.usingColors(),mesh.usingTextures(),mesh.usingNormals());
    
    endDraw();
}