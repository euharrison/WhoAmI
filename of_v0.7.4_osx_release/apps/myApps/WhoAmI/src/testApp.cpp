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
    
    vidgrabber.setVerbose(true);
    vidgrabber.setDeviceID(0);
    vidgrabber.setDesiredFrameRate(60);
    vidgrabber.setPixelFormat(OF_PIXELS_BGRA);
    vidgrabber.initGrabber(640, 480);
    
    videoshader.load(ofToDataPath("shaders/vid.vert"), ofToDataPath("shaders/vid.frag"));
    videoshader.linkProgram();
    videoshader.setUniform3f("iResolution", ofGetWidth()/640.0, ofGetHeight()/480.0, 0);
}

//--------------------------------------------------------------
void testApp::update()
{
    vidgrabber.update();
    m1.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableLighting();
    
    ofPushMatrix();
    ofTranslate(cameraPosition.x, cameraPosition.y, cameraPosition.z);
    
    videoshader.begin();
    vidgrabber.getTextureReference().bind();
    m1.draw();
    vidgrabber.getTextureReference().unbind();
    videoshader.end();
    
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