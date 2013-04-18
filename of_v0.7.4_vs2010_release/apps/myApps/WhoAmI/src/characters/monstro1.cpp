#include "monstro1.h"

monstro1::monstro1()
{
	for(int i = 0; i < 20; i++) {
		shapes[i] = new block();
		shapes[i]->updateMesh(20, 20, 20);
		shapes[i]->updateMaterial(255, 0, 0);
		shapes[i]->rotation.y = 45;
	}
}

void monstro1::update()
{
    characterBase::update();
	
    shapes[NUI_SKELETON_POSITION_HEAD]->rotation.y += 1;
	
	shapes[NUI_SKELETON_POSITION_HAND_LEFT]->rotation.x += 2;
	shapes[NUI_SKELETON_POSITION_HAND_RIGHT]->rotation.x += 2;
	shapes[NUI_SKELETON_POSITION_HAND_LEFT]->rotation.y += 2;
	shapes[NUI_SKELETON_POSITION_HAND_RIGHT]->rotation.y += 2;

	
	float value = ofGetElapsedTimeMillis()/300.f;
	float size = abs(cos(value))*25+15;
	float size2 = abs(sin(value))*25+25;

	shapes[NUI_SKELETON_POSITION_HEAD]->updateMesh(size2, size2, size2);

	shapes[NUI_SKELETON_POSITION_HAND_LEFT]->updateMesh(size, size, size);
	shapes[NUI_SKELETON_POSITION_HAND_RIGHT]->updateMesh(size, size, size);
	shapes[NUI_SKELETON_POSITION_FOOT_LEFT]->updateMesh(size, size, size);
	shapes[NUI_SKELETON_POSITION_FOOT_RIGHT]->updateMesh(size, size, size);

}