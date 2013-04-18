#include "characterBase.h"


void characterBase::updateSkeleton(ofPoint skeletonPoints[20])
{
	for (int i = 0; i < 20; i++)
	{
		skeletonPoints[i].x = ofMap(skeletonPoints[i].x, 0, 320, -500, 500);
		skeletonPoints[i].y = ofMap(skeletonPoints[i].y, 0, 240, -300, 300);
		skeletonPoints[i].z = ofMap(skeletonPoints[i].z, 500, 4000, -5, -15);
	}

	for (int i = 0; i < 20; i++)
	{
		//TODO distorcoes de posicoes para colocar os bracos, pernas etc no meio de dois pontos ao inves de ser nos vertices do esqueleto
		shapes[i]->position.x = skeletonPoints[i].x;
		shapes[i]->position.y = skeletonPoints[i].y;
		shapes[i]->position.z = skeletonPoints[i].z;
	}
}

void characterBase::draw()
{
    ofPushMatrix();
    ofTranslate(position);
 
    for (int i = 0; i < 20; i++) {
        shapes[i]->draw();
    }
    
    ofPopMatrix();
}