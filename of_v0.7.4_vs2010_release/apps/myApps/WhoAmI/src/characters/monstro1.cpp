#include "monstro1.h"

monstro1::monstro1()
{
    shapes[HEAD] = new block();
    shapes[HEAD]->updateMesh(10, 10, 10);
    
    shapes[ARM_LEFT] = new block();
    shapes[ARM_LEFT]->updateMesh(5, 10, 1);
    
    shapes[FOREARM_LEFT] = new block();
    shapes[FOREARM_LEFT]->updateMesh(5, 10, 1);
    
    shapes[HAND_LEFT] = new block();
    shapes[HAND_LEFT]->updateMesh(5, 10, 1);
}

void monstro1::update()
{
    characterBase::update();
    
    shapes[ARM_LEFT]->rotation.y += 2;
    
}