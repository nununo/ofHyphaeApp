#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofSetVerticalSync(true);

  Family *f = new Family("images/mold01.jpg", ofVec2f(200,100), 50);
  Surface *s = new Surface(f, "images/test_texture.jpg", ofVec2f(ofGetWidth(), ofGetHeight()));
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
