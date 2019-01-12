#include "ofApp.h"
#include "InkColor.hpp"
#include "Family.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  Ink *ink = new InkColor(ofColor(0,0,255));
  Surface *s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  s->addPart(new Family(ink, ofVec2f(300,220), 100));
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
