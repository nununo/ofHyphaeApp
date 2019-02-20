#include "ofApp.h"
#include "Mycelium.h"

void ofApp::setup(){
  settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->framerate);
  //ofSetVerticalSync(true);
  mycelia = new Mycelia(settings->mycelium);
  addMycelium();
  ofSetBackgroundAuto(false);
  ofBackground(settings->canvas.backgroundColor);
}

ofApp::~ofApp() {
  delete mycelia;
  delete settings;
}

void ofApp::addMycelium() {
  mycelia->add(ofVec2f(ofRandom(0+ofGetWidth()/5,ofGetWidth()-ofGetWidth()/5),
                       ofRandom(0+ofGetHours()/5,ofGetHeight()-ofGetHeight()/5)));
}

void ofApp::update(){
  mycelia->update();
}

void ofApp::draw(){
  mycelia->draw();
  drawOSD();
}

void ofApp::drawOSD() {
  ofPushStyle();

  ofSetColor(settings->canvas.backgroundColor);
  ofDrawRectangle(0, 0, 180, 50);

  ofSetColor(settings->osdColor);

  string str = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(str, 10,10);

  MyceliaStats stats = mycelia->getStats();

  str = "mycelia: "+ofToString(stats.myceliaCount);
  ofDrawBitmapString(str, 10,25);

  str = "hyphae: "+ofToString(stats.hyphaCount);
  ofDrawBitmapString(str, 10,40);

  ofPopStyle();
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      // Space adds a new family (currently hiding the previous one because for now
      // this is just for convenience
      addMycelium();
      break;
    
    case 'f':
      ofToggleFullscreen();
      break;
      
    default:
      break;
  }
}
