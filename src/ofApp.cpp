#include "ofApp.h"
#include "InkColor.hpp"
#include "Family.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofDisableAlphaBlending();

  glPointSize(1);

  Surface *s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  s->addPart(new Family(ofVec2f(ofGetWidth()/2,ofGetHeight()/2), 600));
  ms = new MaskedSurface(s, "images/bread_profile_mask.png");
  ms = s;
}

//--------------------------------------------------------------
void ofApp::update(){
  ms->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ms->draw();
  ofSetColor(255, 255, 255,255);
  string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(fpsStr, 10,10);
}
