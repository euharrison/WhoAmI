#include "randomShape.h"

randomShape::randomShape()
{
	count = ofRandom(3.1415f);
	vel = ofRandom(0.01) + 0.005;
}

void randomShape::updateMesh(float width, float height, float depth)
{
	mesh.clear();
    
	int random1 = ofRandom(-40,40);
	int random2 = ofRandom(-40,40);
	int random3 = ofRandom(-40,40);
	int random4 = ofRandom(-40,40);
	int random5 = ofRandom(-40,40);
	int random6 = ofRandom(-40,40);
	int random7 = ofRandom(-40,40);
	int random8 = ofRandom(-40,40);

    ofVec3f vertices[] = {
        ofVec3f(+width+random1,-height,+depth), ofVec3f(+width,-height+random2,-depth), ofVec3f(+width,+height,-depth+random3), ofVec3f(+width,+height+random4,+depth),
        ofVec3f(+width,+height+random4,+depth), ofVec3f(+width,+height,-depth+random3), ofVec3f(-width,+height,-depth+random5), ofVec3f(-width+random6,+height,+depth),
        ofVec3f(+width,+height+random4,+depth), ofVec3f(-width+random6,+height,+depth), ofVec3f(-width,-height,+depth+random7), ofVec3f(+width+random1,-height,+depth),
        ofVec3f(-width,-height,+depth+random7), ofVec3f(-width+random6,+height,+depth), ofVec3f(-width,+height,-depth+random5), ofVec3f(-width+random8,-height,-depth),
        ofVec3f(-width,-height,+depth+random7), ofVec3f(-width+random8,-height,-depth), ofVec3f(+width,-height+random2,-depth), ofVec3f(+width+random1,-height,+depth),
        ofVec3f(-width+random8,-height,-depth), ofVec3f(-width,+height,-depth+random5), ofVec3f(+width,+height,-depth+random3), ofVec3f(+width,-height+random2,-depth)
    };
    mesh.addVertices(vertices,24);

	
    
	random1 = ofRandom(-20,20);
	random2 = ofRandom(-20,20);
	random3 = ofRandom(-20,20);
	random4 = ofRandom(-20,20);
	random5 = ofRandom(-20,20);
	random6 = ofRandom(-20,20);
	random7 = ofRandom(-20,20);
	random8 = ofRandom(-20,20);

    ofVec3f vertices2[] = {
        ofVec3f(+width+random1,-height,+depth), ofVec3f(+width,-height+random2,-depth), ofVec3f(+width,+height,-depth+random3), ofVec3f(+width,+height+random4,+depth),
        ofVec3f(+width,+height+random4,+depth), ofVec3f(+width,+height,-depth+random3), ofVec3f(-width,+height,-depth+random5), ofVec3f(-width+random6,+height,+depth),
        ofVec3f(+width,+height+random4,+depth), ofVec3f(-width+random6,+height,+depth), ofVec3f(-width,-height,+depth+random7), ofVec3f(+width+random1,-height,+depth),
        ofVec3f(-width,-height,+depth+random7), ofVec3f(-width+random6,+height,+depth), ofVec3f(-width,+height,-depth+random5), ofVec3f(-width+random8,-height,-depth),
        ofVec3f(-width,-height,+depth+random7), ofVec3f(-width+random8,-height,-depth), ofVec3f(+width,-height+random2,-depth), ofVec3f(+width+random1,-height,+depth),
        ofVec3f(-width+random8,-height,-depth), ofVec3f(-width,+height,-depth+random5), ofVec3f(+width,+height,-depth+random3), ofVec3f(+width,-height+random2,-depth)
    };
    mesh2.addVertices(vertices2,24);
    
    static ofVec3f normals[] = {
        ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0), ofVec3f(+1,0,0),
        ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0), ofVec3f(0,+1,0),
        ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1), ofVec3f(0,0,+1),
        ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0), ofVec3f(-1,0,0),
        ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0), ofVec3f(0,-1,0),
        ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1), ofVec3f(0,0,-1)
    };
    mesh.addNormals(normals,24);
	mesh2.addNormals(normals,24);
    
    static ofVec2f tex[] = {
        ofVec2f(1,0), ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1),
        ofVec2f(1,1), ofVec2f(1,0), ofVec2f(0,0), ofVec2f(0,1),
        ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0), ofVec2f(0,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0),
        ofVec2f(0,0), ofVec2f(0,1), ofVec2f(1,1), ofVec2f(1,0)
    };
    mesh.addTexCoords(tex,24);
    mesh2.addTexCoords(tex,24);
    
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

    mesh2.addIndices(indices,36);
    mesh2.setMode(OF_PRIMITIVE_TRIANGLES);

}

void randomShape::updateMaterial(int r, int g, int b)
{
	//TODO desenvolver
    material.setEmissiveColor(ofColor(r,g,b));
    material.setSpecularColor(ofColor(255,255,255));
    material.setShininess(60);   
}

void randomShape::draw()
{
	count += vel;

    beginDraw();
    
	ofPushMatrix();
	ofScale(cos(count), cos(count), cos(count));
    ofGetCurrentRenderer()->draw(mesh,mesh.usingColors(),mesh.usingTextures(),mesh.usingNormals());
	ofPopMatrix();

	ofPushMatrix();
	ofScale(sin(count), sin(count), sin(count));
    ofGetCurrentRenderer()->draw(mesh2,mesh2.usingColors(),mesh2.usingTextures(),mesh2.usingNormals());
    ofPopMatrix();

    endDraw();
}