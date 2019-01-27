#include "ofApp.h"
#include "InkColor.h"
#include "Mycelium.h"
#include "SpeciesRandomFactory.h"
#include "SpeciesGravityFactory.h"

void ofApp::setup(){
  //ofSetFrameRate(120); ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()));
  addFamily();
  //ms = new MaskedSurface(s, "images/bread_profile_mask.png");
}

void ofApp::addFamily() {
  for(int i=0; i<1; i++) {
    Ink *ink = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
    ISpeciesFactory *danceFactory = new SpeciesRandomFactory(ink);
    s->addPart(new Mycelium(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), /* ofRandom(250,600),ofRandom(250,600)*/
                          700,     // Size
                          0.025f,  // Growth speed
                          100000,  // Lifespan
                          1000,    // Conidium lifespan
                          5,       // Conidium distance
                          0.0025f, // Perimeter distortion
                          100000,  // Hypha max lifespan
                          1.0f,  // Hypha distortion
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
