#pragma once

#include "ofxKinectNui.h"
#include "ofMain.h"
#include "monstro1.h"

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
    ofVec3f cameraPosition;
    
    monstro1 m1;
	

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
	
	//integration kinect
	vector<ofPoint *> bone;
	int currentSkeletonIndex;
};
