#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofBackground(0);

	// start Kinect:

	kinect.init();		// 1. initialize Kinect (setup)
	kinect.open();		// 2. open connection

	// setup Kinect parameters
	nearDepth.set("near depth", 500, 500, 4000);	// depth range in millimeters
	farDepth.set("far depth", 2000, 500, 4000);		// kinect depth limits: 50cm near, 4 meters far


	// setup contour finder parameters
	threshold.set("threshold", 40, 0, 255);			// kinect grayscale -> black / white
	minArea.set("minArea", 100., 1., 1000.);		// min blob size
	maxArea.set("maxArea", 200000, 100, 300000);	// max blob size
	smoothFactor.set("smoothing", 5., 0., 40.);		// contour smoothing


	// add params to gui

	kinectParams.setName("kinect");				// kinect param group 
	kinectParams.add(nearDepth);
	kinectParams.add(farDepth);

	contourParams.setName("contour finder");	// contour param group
	contourParams.add(threshold);
	contourParams.add(minArea);
	contourParams.add(maxArea);
	contourParams.add(smoothFactor);

	gui.setup();
	gui.add(kinectParams);
	gui.add(contourParams);

	

}

//--------------------------------------------------------------
void ofApp::update(){

	// apply current parameters

	kinect.setDepthClipping(nearDepth, farDepth);

	contourFinder.setThreshold( threshold );
	contourFinder.setMinArea( minArea );
	contourFinder.setMaxArea( maxArea );

	
	// update Kinect

	kinect.update();

	if (kinect.isFrameNew()) {

		// find contours on new frames only

		// blur the kinect image to remove noise:

		ofxCv::blur(kinect.getDepthPixels(), 10);
		contourFinder.findContours( kinect.getDepthPixels() );

		// store contours as polylines

		contours = contourFinder.getPolylines();

		// smooth the polyline

		if (smoothFactor > 0.) {
			for (int i = 0; i < contours.size(); i++) {
				contours[i] = contours[i].getSmoothed(smoothFactor);
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){


	ofPushMatrix();

	ofScale(2.);		// scale up

	ofPushStyle();

	ofSetColor(255,100);
	kinect.drawDepth(0,0);
	
	// contourFinder.draw();	// auto draw contour finder

	// custom draw contours as ofPolylines
	ofSetLineWidth(10.);
	for (int i = 0; i < contours.size(); i++) {
		
		// contourFinder tracks the contours (blobs) over time --
		// each blob is labelled with a number ID:
		int id = contourFinder.getLabel(i);

		// generate a color from the id
		float hue = id * 30 % 255;
		ofSetColor( ofColor::fromHsb(hue,255,255) );

		contours[i].draw();

		// print the label
		ofDrawBitmapStringHighlight( ofToString(contourFinder.getLabel(i)), contours[i].getCentroid2D());	// draw at center
	}
	ofPopStyle();


	ofPopMatrix();

	gui.draw();

}

//--------------------------------------------------------------
void ofApp::exit(){

	// close the Kinect stream on app exit:
	kinect.close();
}
