#include "stickman.h"

stickman::stickman()
{
	for(int i = 0; i < 20; i++) {
		shapes[i] = new block();
		shapes[i]->updateMesh(10, 40, 10);
		shapes[i]->updateMaterial(0, 0, 255);
	}
}

void stickman::update()
{
	float value_y = shapes[NUI_SKELETON_POSITION_FOOT_LEFT]->position.y - shapes[NUI_SKELETON_POSITION_HAND_LEFT]->position.y;
	float value_y2 = shapes[NUI_SKELETON_POSITION_FOOT_LEFT]->position.y - shapes[NUI_SKELETON_POSITION_HAND_LEFT]->position.y;
	
	float size = (abs(value_y)+abs(value_y2))/2.f/2.f;

	
	float value_x = shapes[NUI_SKELETON_POSITION_HAND_LEFT]->position.x - shapes[NUI_SKELETON_POSITION_HAND_RIGHT]->position.x;
	
	float r = abs(value_x)/3.f;


	for(int i = 0; i < 20; i++) {
		shapes[i]->updateMesh(10, size, 10);
		shapes[i]->rotation.z = r;
	}

}