#include "ofApp.h"
#include "InkColor.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  ofSetBackgroundColor(0xff0000);
  
  Ink *ink = new InkColor(ofColor(0,0,255));
  Family *f = new Family(ink, ofVec2f(300,220), 100);
  Surface *s = new Surface(f, ofVec2f(ofGetWidth(), ofGetHeight()));
  ms = new MaskedSurface(s, "images/bread_profile_mask.png");
}

//--------------------------------------------------------------
void ofApp::update(){
  ms->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ms->draw();
}
