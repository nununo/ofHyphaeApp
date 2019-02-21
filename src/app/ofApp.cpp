#include "ofApp.h"
#include "HyphaeParamsBuilder.h"

void ofApp::setup(){
  this->settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->canvas.framerate);
  this->builder = new HyphaeParamsBuilder(settings->hyphae);
  //ofSetVerticalSync(true);
  ofSetBackgroundAuto(false);
  ofBackground(settings->canvas.backgroundColor);
  restart();
}

ofApp::~ofApp() {
  delete hyphae;
  delete settings;
  delete builder;
}

void ofApp::restart() {
  if (hyphae) {
    delete hyphae;
  }
  hyphae = new Hyphae(builder->create());
  ofBackground(settings->canvas.backgroundColor);
}

void ofApp::update(){
  hyphae->update();
}

void ofApp::draw(){
  hyphae->draw();
  drawOSD();
}

void ofApp::drawOSD() {
  ofPushStyle();

  ofSetColor(settings->canvas.backgroundColor);
  ofDrawRectangle(0, 0, 180, 50);

  ofSetColor(settings->canvas.osdColor);

  string str = "framerate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(str, 10,10);

  str = "hyphae: "+ofToString(hyphae->count());
  ofDrawBitmapString(str, 10,25);

  str = "primalHyphae: "+ofToString(hyphae->primalCount());
  ofDrawBitmapString(str, 10,40);
  
  ofPopStyle();
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      restart();
      break;
    
    case 'f':
      ofToggleFullscreen();
      break;
      
    default:
      break;
  }
}
