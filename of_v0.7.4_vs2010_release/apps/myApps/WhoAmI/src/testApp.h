#pragma once

#include "ofxKinectNui.h"
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "characters\monstro1.h"
#include "characters\monstro2.h"
#include "characters\stickman.h"

#define USE_KINECT

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
    
	ofLight light;
	ofLight spotLight;
    
	vector<characterBase*> characteres;
	int current;

	int numFramesFoundSkeleton;
	ofPoint skeletonFake[20];
    
    ofVideoGrabber vidgrabber;
    ofShader videoshader;


	//Kinect
	void kinectPlugged();
	void kinectUnplugged();
		
	ofxKinectNui kinect;
	ofxBase3DVideo* kinectSource;

	bool bPlugged;
	bool bUnplugged;
		
	unsigned short nearClipping;
	unsigned short farClipping;
	int angle;
	
};
