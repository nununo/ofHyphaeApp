#include "ofApp.h"
#include "Mycelium.h"
#include "MyceliumParamsBuilder.h"

void ofApp::setup(){
  settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->framerate);
  //ofSetVerticalSync(true);
  ofSetBackgroundAuto(false);
  ofBackground(settings->canvas.backgroundColor);
  newMycelium();
}

ofApp::~ofApp() {
  delete mycelium;
  delete settings;
}

void ofApp::newMycelium() {
  if (mycelium) {
    delete mycelium;
  }

  MyceliumParams params = MyceliumParamsBuilder(settings->mycelium).create();
  mycelium = new Mycelium(ofVec2f(ofRandom(0+ofGetWidth()/5,ofGetWidth()-ofGetWidth()/5),
                                  ofRandom(0+ofGetHours()/5,ofGetHeight()-ofGetHeight()/5)),
                          settings->mycelium, params);

  ofBackground(settings->canvas.backgroundColor);
}

void ofApp::update(){
  mycelium->update();
}

void ofApp::draw(){
  mycelium->draw();
  drawOSD();
}

void ofApp::drawOSD() {
  ofPushStyle();

  ofSetColor(settings->canvas.backgroundColor);
  ofDrawRectangle(0, 0, 180, 50);

  ofSetColor(settings->osdColor);

  string str = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(str, 10,10);

  MyceliumStats stats = mycelium->getStats();

  str = "hyphae: "+ofToString(stats.hyphaCount);
  ofDrawBitmapString(str, 10,25);

  str = "primalHyphae: "+ofToString(stats.primalHyphaCount);
  ofDrawBitmapString(str, 10,40);
  
  ofPopStyle();
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      newMycelium();
      break;
    
    case 'f':
      ofToggleFullscreen();
      break;
      
    default:
      break;
  }
}
