#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	glEnable(GL_DEPTH_TEST);
    
    ofSetSmoothLighting(true);
    
    ofSetSphereResolution(64);
    
    cameraPosition.set(ofGetWidth()/2, ofGetHeight()/2+40, 500);
    
    
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,255));
    light.setPosition(200, 200, 200);
    light.enable();    
    
}

//--------------------------------------------------------------
void testApp::update()
{
    m1.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableLighting();
    
    ofPushMatrix();
    ofTranslate(cameraPosition.x, cameraPosition.y, cameraPosition.z);
    
    
    m1.draw();
    
    
    ofPopMatrix();
    ofDisableLighting();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == OF_KEY_UP) {
        m1.reshape();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}