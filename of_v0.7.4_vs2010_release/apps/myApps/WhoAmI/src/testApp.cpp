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
    
    
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,255));
    light.setPosition(200, 200, 200);
    light.enable();   


#ifdef USE_KINECT
	ofxKinectNui::InitSetting initSetting;
	initSetting.grabVideo = false;
	initSetting.grabDepth = false;
	initSetting.grabAudio = false;
	initSetting.grabLabel = false;
	initSetting.grabSkeleton = true;
	initSetting.grabCalibratedVideo = false;
	initSetting.grabLabelCv = false;
	initSetting.videoResolution = NUI_IMAGE_RESOLUTION_640x480;
	initSetting.depthResolution = NUI_IMAGE_RESOLUTION_320x240;
	kinect.init(initSetting);
	kinect.open();
	kinect.addKinectListener(this, &testApp::kinectPlugged, &testApp::kinectUnplugged);
	
	kinectSource = &kinect;
	angle = kinect.getCurrentAngle();
	bPlugged = kinect.isConnected();
	nearClipping = kinect.getNearClippingDistance();
	farClipping = kinect.getFarClippingDistance();
	currentSkeletonIndex = -1;

	for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
		ofPoint * joint = new ofPoint(9999, 9999, 9999);
		bone.push_back(joint);
	}
#endif	
    
}

//--------------------------------------------------------------
void testApp::update(){
	
#ifdef USE_KINECT
	//kinect
	kinectSource->update();

	// Update kinect coords
	for(int i = 0; i < kinect::nui::SkeletonFrame::SKELETON_COUNT; ++i){
		for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
			if(kinect.skeletonPoints[i][0].z > 0){
				currentSkeletonIndex = i;
				m1.shapes[j]->position.x = ofMap(kinect.skeletonPoints[i][j].x, 0, 310, 0, ofGetWidth());
				m1.shapes[j]->position.y = kinect.skeletonPoints[i][j].y * 3;
				m1.shapes[j]->position.z = ofMap(kinect.skeletonPoints[i][j].z, 0, 40000, 0, 2000);
			}
		}
	}
#endif	

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

//--------------------------------------------------------------
void testApp::kinectPlugged(){
	bPlugged = true;
}

//--------------------------------------------------------------
void testApp::kinectUnplugged(){
	bPlugged = false;
}
