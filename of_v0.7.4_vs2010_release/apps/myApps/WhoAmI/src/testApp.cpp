#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	glEnable(GL_DEPTH_TEST);
    
    ofSetSmoothLighting(true);
    
    ofSetSphereResolution(64);
    
    
    light.setDiffuseColor(ofColor(255,255,255));
    light.setSpecularColor(ofColor(255,255,255));
    light.setPosition(200, 200, 200);
    light.enable();   


	characteres.push_back(new monstro1());
	characteres.push_back(new monstro2());
	characteres.push_back(new monstro1());
	characteres.push_back(new monstro2());

	current = 0;
	numFramesFoundSkeleton = 0;


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
#endif	
    
}

//--------------------------------------------------------------
void testApp::update(){
	
#ifdef USE_KINECT
	//kinect
	kinectSource->update();

	// Update kinect coords
	bool founded = false;
	for(int i = 0; i < kinect::nui::SkeletonFrame::SKELETON_COUNT; ++i){
		for(int j = 0; j < kinect::nui::SkeletonData::POSITION_COUNT; ++j){
			if(kinect.skeletonPoints[i][0].z > 0)
			{
				if(numFramesFoundSkeleton==0){
					current = ofRandom(0, characteres.size()-1);
				}
				if(numFramesFoundSkeleton<5) numFramesFoundSkeleton = 5;
				founded = true;

				characteres[current]->shapes[j]->position.x = ofMap(kinect.skeletonPoints[i][j].x, 0, 320, -500, 500);
				characteres[current]->shapes[j]->position.y = ofMap(kinect.skeletonPoints[i][j].y, 0, 240, -300, 300);
				characteres[current]->shapes[j]->position.z = ofMap(kinect.skeletonPoints[i][j].z, 500, 4000, -5, -15);
			}
		}
	}
	
	if(!founded && numFramesFoundSkeleton>0){
		numFramesFoundSkeleton--;

		if(numFramesFoundSkeleton==0){
			//saiu
		}
	}
#endif	

	characteres[current]->update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofEnableLighting();
    
    ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetWidth()/2, 0);
    
	characteres[current]->draw();
    
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
