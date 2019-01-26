#include "ofApp.h"
#include "InkColor.h"
#include "Family.h"
#include "DanceRandomFactory.h"
#include "DanceGravityFactory.h"

void ofApp::setup(){
  //ofSetFrameRate(120); ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  addFamily();
  //ms = new MaskedSurface(s, "images/bread_profile_mask.png");
}

void ofApp::addFamily() {
  for(int i=0; i<5; i++) {
    Ink *ink = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
    IDanceFactory *danceFactory = new DanceRandomFactory(ink);
    s->addPart(new Family(ofVec2f(ofRandom(150,650),ofRandom(15,650)),
                          700,     // Size
                          0.025f,  // Growth speed
                          100000,  // Lifespan
                          1000,    // Element lifespan
                          5,       // Element distance
                          0.0025f,  // Perimeter distortion
                          danceFactory));
  }
}

void ofApp::update(){
  s->update();
}

void ofApp::draw(){
  s->draw();
  ofPushStyle();
  ofSetColor(0, 0, 0);
  string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(fpsStr, 10,10);
  ofPopStyle();
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
