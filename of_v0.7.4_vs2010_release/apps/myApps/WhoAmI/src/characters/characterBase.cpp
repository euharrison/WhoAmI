#include "characterBase.h"


void characterBase::update()
{

}

void characterBase::draw()
{
    ofPushMatrix();
    ofTranslate(position);
 
    for (int i = 0; i < 20; i++) {
        shapes[i]->draw();
    }
    
    ofPopMatrix();
}