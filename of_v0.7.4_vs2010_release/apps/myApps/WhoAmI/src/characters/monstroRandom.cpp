#include "monstroRandom.h"

monstroRandom::monstroRandom()
{
	for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
		shapes[j] = new randomShape();
		shapes[j]->updateMesh(30, 30, 30);
	}
}

void monstroRandom::update()
{
	shapes[0]->rotation.y += 2;
}