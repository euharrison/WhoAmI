#include "characterBase.h"

characterBase::characterBase()
{
    //positions
    
    head.set(0, -80);
    
    shoulder_left.set(-10, -65);
    elbow_left.set(-20, -50);
    hand_left.set(-20, -30);
    leg_left.set(-5, -40);
    knee_left.set(-10, -20);
    foot_left.set(-10, 0);
    
    shoulder_right.set(10, -65);
    elbow_right.set(20, -50);
    hand_right.set(20, -30);
    leg_right.set(5, -40);
    knee_right.set(10, -20);
    foot_right.set(10, 0);
    
    //material
    
    material.setEmissiveColor(ofColor(255,0,0));
    material.setSpecularColor(ofColor(255,0,0));
    material.setShininess(60);
}

void characterBase::draw()
{
    ofPushMatrix();
    ofTranslate(position);
    
    material.begin();
    texture.getTexture().bind();
    
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
    
    texture.getTexture().unbind();
    material.end();
    
    ofPopMatrix();
}
