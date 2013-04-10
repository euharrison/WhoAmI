#include "characterBase.h"


void characterBase::update()
{
    ofPoint headPosition;
    
    ofPoint shoulder_left;
    ofPoint elbow_left;
    ofPoint hand_leftPosition;
    ofPoint leg_left;
    ofPoint knee_left;
    ofPoint foot_left;
    
    ofPoint shoulder_right;
    ofPoint elbow_right;
    ofPoint hand_right;
    ofPoint leg_right;
    ofPoint knee_right;
    ofPoint foot_right;
    
    
    headPosition.set(0, -80);
    
    shoulder_left.set(-10, -65);
    elbow_left.set(-20, -50);
    hand_leftPosition.set(-20, -30);
    leg_left.set(-5, -40);
    knee_left.set(-10, -20);
    foot_left.set(-10, 0);
    
    shoulder_right.set(10, -65);
    elbow_right.set(20, -50);
    hand_right.set(20, -30);
    leg_right.set(5, -40);
    knee_right.set(10, -20);
    foot_right.set(10, 0);
    
    
    shapes[HEAD]->position = headPosition;
    
    shapes[ARM_LEFT]->position = shoulder_left + ((elbow_left-shoulder_left)/2.f);
    shapes[FOREARM_LEFT]->position = elbow_left + ((hand_leftPosition-elbow_left)/2.f);
    shapes[HAND_LEFT]->position = hand_leftPosition;
}

void characterBase::draw()
{
    ofPushMatrix();
    ofTranslate(position);
 
    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
    }
    
    ofPopMatrix();
}