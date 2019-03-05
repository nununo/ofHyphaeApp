#include "ofApp.h"
#include "OSD.h"
#include "StepHyphae.h"
#include "StepCountdown.h"
#include "StepFadeToBlack.h"

void ofApp::setup(){
  settings.reset(new Settings("settings/settings.xml"));
  osd.reset(new OSD(settings.get()));
  steps.reset(new Steps(settings.get()));
  ofSetBackgroundAuto(false);
  ofSetFrameRate(settings->canvas.framerate);
  //ofSetVerticalSync(true);
  ofBackground(settings->canvas.backgroundColor);
  ofHideCursor();
}

void ofApp::update(){
  if (!paused) {
    steps->update();
    if (steps->getHyphaeStats().hyphaCount>=10) {
      togglePaused();
    }
  }
}

void ofApp::draw(){
  if (!paused) {
    steps->draw();
  }
  osd->draw(steps->getHyphaeParams(), steps->getHyphaeStats(), steps->getCurrentStepName(), steps->getSaveScreenEnabled());
}

void ofApp::clearScreen() {
  ofPushStyle();
  ofSetColor(settings->canvas.backgroundColor);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofPopStyle();
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      steps->setGrowing();
      break;

    case 'd':
      steps->setFadeout();
      break;

    case 'f':
      ofToggleFullscreen();
      break;

    case 'o':
      osd->toggleActive();
      break;
      
    case 'b':
      steps->drawHyphaeBorder();
      break;
    
    case 'c':
      clearScreen();
      break;
    
    case 'p':
      togglePaused();
      break;

    case 's':
      steps->toggleSaveScreen();
      break;

    case 'l':
      ofLog() << "seed: " << steps->getHyphaeParams().seed;
      break;

    default:
      break;
  }
}
