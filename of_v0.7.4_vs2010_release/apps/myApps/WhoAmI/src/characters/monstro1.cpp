#include "monstro1.h"

monstro1::monstro1()
{
	for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
		shapes[j] = new block();
		shapes[j]->updateMesh(20, 20, 20);
	}
}

void monstro1::update()
{
    characterBase::update();
    
    shapes[ARM_LEFT]->rotation.y += 2;
}

void monstro1::reshape() 
{
    for (int i = 0; i < MAX_RESHAPES; i++) {
        float x = ofRandom(5.0)+1.0;
        shapes[(size_t)ofRandom(20)]->updateMesh(x, ofRandom(10.0)+5.0, x);
    }
}