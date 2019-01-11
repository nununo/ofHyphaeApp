#include "ofApp.h"
#include "InkColor.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(30);
  ofSetVerticalSync(true);
  Ink *ink = new InkColor(ofColor(0,0,255));
  Family *f = new Family(ink, ofVec2f(200,100), 50);
  Surface *s = new Surface(f, "images/test_texture_retina.jpg", ofVec2f(ofGetWidth(), ofGetHeight()));
  ms = new MaskedSurface(s, "images/bread_profile_mask_retina.png");

}

//--------------------------------------------------------------
void ofApp::update(){
  ofLog() << ofGetWidth();
  ms->update();
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  ms->draw();
}
