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

void monstro1::reshape() {
    for (int i = 0; i < MAX_RESHAPES; i++) {
        float x = ofRandom(5.0)+1.0;
        shapes[(size_t)ofRandom(TOTAL_SHAPES)]->updateMesh(x, ofRandom(10.0)+5.0, x);
    }
}