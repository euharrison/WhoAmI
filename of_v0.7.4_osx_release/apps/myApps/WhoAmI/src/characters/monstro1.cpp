#include "monstro1.h"

monstro1::monstro1()
{
    for (int i = 0; i < TOTAL_SHAPES; i++) {
        shapes[i] = new block();
        shapes[i]->updateMesh(2, 2, 2);
    }
    
    shapes[HEAD]->updateMesh(10, 10, 10);
    shapes[BODY]->updateMesh(5, 15, 10);
    
    shapes[ARM_LEFT]->updateMesh(1, 10, 1);
    shapes[FOREARM_LEFT]->updateMesh(2, 10, 2);
    shapes[HAND_LEFT]->updateMesh(5, 5, 5);
}

void monstro1::update()
{
    characterBase::update();
    
    shapes[HEAD]->rotation.y += 1;
}
