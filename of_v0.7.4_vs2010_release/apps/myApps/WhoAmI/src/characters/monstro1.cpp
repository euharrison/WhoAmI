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