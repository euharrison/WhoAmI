#include "monstro2.h"

monstro2::monstro2()
{
	for(int i = 0; i < 20; i++) {
		shapes[i] = new sphere();
		shapes[i]->updateMesh(20, 20, 20);
		shapes[i]->updateMaterial(0, 255, 0);
	}
}

void monstro2::update()
{
	float value = shapes[NUI_SKELETON_POSITION_HAND_LEFT]->position.x - shapes[NUI_SKELETON_POSITION_HAND_RIGHT]->position.x;
	
	float size = abs(value)/3.f;

	for(int i = 0; i < 20; i++) {
		shapes[i]->updateMesh(size, size, size);
	}

}