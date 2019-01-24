#include "ofApp.h"
#include "InkColor.h"
#include "Family.h"

void ofApp::setup(){
  //ofSetFrameRate(120); ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  addFamily();
  //ms = new MaskedSurface(s, "images/bread_profile_mask.png");
}

void ofApp::addFamily() {
  s->addPart(new Family(ofVec2f(s->getWidth()/2,s->getHeight()/2), // ofVec2f(ofRandom(150,650),ofRandom(15,650)),
                        700,    // Size
                        0.025f,  // Growth speed
                        100000, // Lifespan
                        1000,    // Element lifespan
                        5      // Element distance
                        ));
}

void ofApp::update(){
  s->update();
}

void ofApp::draw(){
  s->draw();
  ofSetColor(255, 255, 255,255);
  string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(fpsStr, 10,10);
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      // Space adds a new family (currently hiding the previous one because for now
      // this is just for convenience
      addFamily();
      break;
      
    default:
      break;
  }
}
