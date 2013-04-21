#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 10);
	glEnable(GL_DEPTH_TEST);
    
	ofEnableLighting();

    ofSetSmoothLighting(true);
    
    ofSetSphereResolution(64);
    
    
    light.setDiffuseColor(ofColor(50,50,50));
    light.setSpecularColor(ofColor(50,50,50));
    light.setPosition(0, 300, 1000);
    light.enable();
    
    spotLight.setDiffuseColor(ofColor(255,255,255));
    spotLight.setSpecularColor(ofColor(255,255,255));
    spotLight.setPosition(0, 0, 1000);
    spotLight.enable();
	spotLight.setSpotlight();
    spotLight.setSpotlightCutOff( 1000 );
    spotLight.setSpotConcentration( 45 );


    
    //vidgrabber.setVerbose(true);
    //vidgrabber.setDeviceID(0);
    //vidgrabber.setDesiredFrameRate(60);
    //vidgrabber.setPixelFormat(OF_PIXELS_BGRA);
    //vidgrabber.initGrabber(640, 480);
    
    //videoshader.load(ofToDataPath("shaders/vid.vert"), ofToDataPath("shaders/vid.frag"));
    //videoshader.linkProgram();
    //videoshader.setUniform3f("iResolution", ofGetWidth()/640.0, ofGetHeight()/480.0, 0);


	characteres.push_back(new monstro1());
	characteres.push_back(new monstro2());
	characteres.push_back(new stickman());

	current = 0;
	numFramesFoundSkeleton = 0;
	
	lastChange = 0;
	

	skeletonFake[0] = ofPoint(183, 83, 27000);
	skeletonFake[1] = ofPoint(182, 78, 27536);
	skeletonFake[2] = ofPoint(182, 44, 27760);
	skeletonFake[3] = ofPoint(182, 27, 27752);
	skeletonFake[4] = ofPoint(167, 54, 27624);
	skeletonFake[5] = ofPoint(151, 72, 27448);
	skeletonFake[6] = ofPoint(144, 91, 26296);
	skeletonFake[7] = ofPoint(142, 99, 26080);
	skeletonFake[8] = ofPoint(196, 54, 27784);
	skeletonFake[9] = ofPoint(213, 72, 28136);
	skeletonFake[10] = ofPoint(225, 89, 27160);
	skeletonFake[11] = ofPoint(229, 97, 26824);
	skeletonFake[12] = ofPoint(176, 90, 26792);
	skeletonFake[13] = ofPoint(176, 142, 27144);
	skeletonFake[14] = ofPoint(178, 189, 26512);
	skeletonFake[15] = ofPoint(180, 194, 25616);
	skeletonFake[16] = ofPoint(190, 89, 26920);
	skeletonFake[17] = ofPoint(198, 136, 27136);
	skeletonFake[18] = ofPoint(203, 168, 27304);
	skeletonFake[19] = ofPoint(205, 176, 26872);
    
	characteres[current]->updateSkeleton( skeletonFake );


	//kinect

	ofxKinectNui::InitSetting initSetting;
	initSetting.grabVideo = false;
	initSetting.grabDepth = false;
	initSetting.grabAudio = true;
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


	//kinect audio

	soundStream.listDevices();
	int bufferSize = 256;
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

}

//--------------------------------------------------------------
void testApp::update()
{
    vidgrabber.update();

	//kinect
	kinectSource->update();
	
	// Update kinect coords
	bool founded = false;
	for(int i = 0; i < kinect::nui::SkeletonFrame::SKELETON_COUNT; ++i){
		if(kinect.skeletonPoints[i][0].z > 0)
		{
			if(numFramesFoundSkeleton==0){
				changeCharacter();
			} 
			if(numFramesFoundSkeleton<5) numFramesFoundSkeleton = 5;
			founded = true;
			
			characteres[current]->updateSkeleton( kinect.skeletonPoints[i] );
		}
	}
	
	if(!founded && numFramesFoundSkeleton>0)
	{
		numFramesFoundSkeleton--;
		if (numFramesFoundSkeleton==0) {
			//saiu
		}
	}


	//audio
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
	if (scaledVol > 0.8) {
		changeCharacter();
	}

	//characteres
	characteres[current]->update();
	

	//light
	spotLight.setPosition(
		characteres[current]->shapes[NUI_SKELETON_POSITION_HEAD]->position.x + 200,
		200,
		2000);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofPushMatrix();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
	//videoshader.begin();
    //vidgrabber.getTextureReference().bind();
    
	characteres[current]->draw();
    
	//vidgrabber.getTextureReference().unbind();
    //videoshader.end();

    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 'f') {
		ofToggleFullscreen();
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

//--------------------------------------------------------------
void testApp::kinectPlugged(){
	bPlugged = true;
}

//--------------------------------------------------------------
void testApp::kinectUnplugged(){
	bPlugged = false;
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels)
{	
	float curVol = 0.0;

	// samples are "interleaved"
	int numCounted = 0;	

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}

	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;

	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );

	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
}

//--------------------------------------------------------------
void testApp::changeCharacter()
{
	float millis = ofGetElapsedTimeMillis();
	if (millis-lastChange > 1000)
	{
		lastChange = millis;

		int tempCur = current;
		while (current == tempCur) {
			current = ofRandom(0, characteres.size());
			if (current >= characteres.size()-1) {
				current = characteres.size()-1;
			}
		}
	}
}