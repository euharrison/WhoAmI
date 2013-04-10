#include "characterBase.h"


void characterBase::update()
{
    ofPoint head(0, -80);
    ofPoint body(0, -45);
    
    ofPoint shoulder_left(-10, -65);
    ofPoint elbow_left(-20, -50);
    ofPoint hand_left(-20, -30);
    ofPoint leg_left(-5, -40);
    ofPoint knee_left(-10, -20);
    ofPoint foot_left(-10, 0);
    
    ofPoint shoulder_right(10, -65);
    ofPoint elbow_right(20, -50);
    ofPoint hand_right(20, -30);
    ofPoint leg_right(5, -40);
    ofPoint knee_right(10, -20);
    ofPoint foot_right(10, 0);    
    
    shapes[HEAD]->position = head;
    shapes[BODY]->position = body;
    
    shapes[ARM_LEFT]->position = shoulder_left + ((elbow_left-shoulder_left)/2.f);
    shapes[FOREARM_LEFT]->position = elbow_left + ((hand_left-elbow_left)/2.f);
    shapes[HAND_LEFT]->position = hand_left;
    shapes[THIGH_LEFT]->position = leg_left + ((knee_left-leg_left)/2.f);
    shapes[LEG_LEFT]->position = knee_left + ((foot_left-knee_left)/2.f);
    shapes[FOOT_LEFT]->position = foot_left;
    
    shapes[ARM_RIGHT]->position = shoulder_right + ((elbow_right-shoulder_right)/2.f);
    shapes[FOREARM_RIGHT]->position = elbow_right + ((hand_right-elbow_right)/2.f);
    shapes[HAND_RIGHT]->position = hand_right;
    shapes[THIGH_RIGHT]->position = leg_right + ((knee_right-leg_right)/2.f);
    shapes[LEG_RIGHT]->position = knee_right + ((foot_right-knee_right)/2.f);
    shapes[FOOT_RIGHT]->position = foot_right;
}

void characterBase::draw()
{
    ofPushMatrix();
    ofTranslate(position);
 
    for (int i = 0; i < TOTAL_SHAPES; i++) {
        shapes[i]->draw();
    }
    
    ofPopMatrix();
}



