#include "ofApp.h"
#include "InkColor.h"
#include "Family.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(120);
  ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  Surface *s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  s->addPart(new Family(ofVec2f(500,400),
                        600,    // Size
                        0.025f,  // Growth speed
                        100000, // Lifespan
                        2000,    // Element lifespan
                        10      // Element distance
                        ));
  ms = new MaskedSurface(s, "images/bread_profile_mask.png");
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
