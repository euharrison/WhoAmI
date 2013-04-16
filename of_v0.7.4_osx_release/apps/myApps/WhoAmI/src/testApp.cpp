#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	glEnable(GL_DEPTH_TEST);
    
    ofSetSmoothLighting(true);
    
    ofSetSphereResolution(64);
    
    cameraPosition.set(ofGetWidth()/2, ofGetHeight()/2+40, 500);
    
    
    ofEnableLighting();
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,255));
    light.setPosition(200, 200, 200);
    light.enable();
    
    tex.addShader(new GenTextureFragShader("tissue.frag"));
    
    camera.setAspectRatio(1024.0/768.0);
    camera.setPosition(0, 50, -100);
    camera.lookAt(ofVec3f(0, 50, 0));
    
    mesh.addTexCoord(ofVec2f(0, 0));
    mesh.addVertex(ofVec3f(-50, -50, 0));
    mesh.addTexCoord(ofVec2f(512, 0));
    mesh.addVertex(ofVec3f(50, -50, 0));
    mesh.addTexCoord(ofVec2f(0, 512));
    mesh.addVertex(ofVec3f(-50, 50, 0));
    mesh.addTexCoord(ofVec2f(512, 512));
    mesh.addVertex(ofVec3f(50, 50, 0));
    vbo.setMesh(mesh, GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    tex.applySequence();
    ofTexture &tx = tex.getTexture();
    camera.begin();
        //m1.draw();
    tx.bind();
        //ofRect(-50, -50, 100, 100);
    vbo.draw(GL_TRIANGLE_STRIP, 0, 4);
    tx.unbind();
    camera.end();
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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