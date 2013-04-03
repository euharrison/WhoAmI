#include "monstro1.h"

monstro1::monstro1()
{
    
}

void monstro1::draw()
{
    ofPushMatrix();
    ofTranslate(position);
    
    material.begin();
    
    ofSphere(head, 10);
    
    ofSphere(shoulder_left, 5);
    ofSphere(elbow_left, 5);
    ofSphere(hand_left, 5);
    ofSphere(leg_left, 5);
    ofSphere(knee_left, 5);
    ofSphere(foot_left, 5);
    
    ofSphere(shoulder_right, 5);
    ofSphere(elbow_right, 5);
    ofSphere(hand_right, 5);
    ofSphere(leg_right, 5);
    ofSphere(knee_right, 5);
    ofSphere(foot_right, 5);
    
    material.end();
    
    ofPopMatrix();
}
