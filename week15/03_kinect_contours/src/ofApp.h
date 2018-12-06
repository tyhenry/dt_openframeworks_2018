#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void exit();

	ofxKinect kinect;

	ofxCv::ContourFinder contourFinder;

	vector<ofPolyline> contours;

	ofParameter<float> nearDepth, farDepth;			// Kinect depth range (millimeters)
	ofParameter<float> threshold, minArea, maxArea, smoothFactor;	// contourFinder

	ofParameterGroup kinectParams, contourParams;
	ofxPanel gui;

		
};
