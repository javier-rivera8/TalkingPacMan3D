#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int cntr = 0;
		int talkcntr = 0;
		int eatcntr = 0;
		int eatingcnt = 0;
		int eatanim = 0;
		int minus = 0;
		int hlthBar = 650;
		int hlthcntr = 0;

		bool hear = false;
		bool talk = false;
		bool eat = false;
		bool food = false;
		bool realease = false;
		bool eating = false;
		bool pause = false;

		double posX = 0;
		double posY = 0;
		double xPan = 200;
		double yPan  = ofGetHeight() - 100;

	ofImage pacDown;
	ofImage pacMiddle;
	ofImage pacHear;
	ofImage pacTalk;
	ofImage pacFullOpen;
	ofImage bread;
	ofImage menu;
	ofImage settings;

	ofSoundPlayer troll;
};
