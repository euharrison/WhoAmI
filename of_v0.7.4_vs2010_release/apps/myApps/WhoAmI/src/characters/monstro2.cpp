#include "monstro2.h"

monstro2::monstro2()
{
	for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
		shapes[j] = new block();
		shapes[j]->updateMesh(40, 40, 40);
	}
}

void monstro2::update()
{
    characterBase::update();
    
    shapes[HEAD]->rotation.y += 2;
    
}