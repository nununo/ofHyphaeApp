#include "ofApp.h"
#include "HyphaeParamsBuilder.h"
#include "OSD.h"

void ofApp::setup(){
  settings.reset(new Settings("settings/settings.xml"));
  osd.reset(new OSD());
  ofSetBackgroundAuto(false);
  ofSetFrameRate(settings->canvas.framerate);
  //ofSetVerticalSync(true);
  ofBackground(settings->canvas.backgroundColor);
}

void ofApp::newHyphae() {
  HyphaeParamsBuilder builder;
  currentParams = builder.create(*settings.get());
  hyphae.reset(new Hyphae(currentParams));
  ofBackground(settings->canvas.backgroundColor);
  lifecycleStage = alive;
}

void ofApp::update(){
  switch (lifecycleStage) {
    case alive:
      if (hyphae->isAlive()) {
        hyphae->update();
      } else {
        lifecycleStage = mourning;
        mourningFrames = settings->canvas.mourningTime * settings->canvas.framerate;
      }
      break;
    
    case mourning:
      if (--mourningFrames <= 0) {
        lifecycleStage = fadeout;
        fadeoutFramesPeriod = (int)(settings->canvas.fadeoutTime * settings->canvas.framerate / 256);
        if (fadeoutFramesPeriod==0) {
          fadeoutFramesPeriod = 1;
        }
        fadeoutFrames = settings->canvas.fadeoutTime * settings->canvas.framerate;
        if (fadeoutFrames<256) {
          fadeoutFrames = 256;
        }
      }
      break;
    
    case fadeout:
      if (--fadeoutFrames <= 0) {
        lifecycleStage = idle;
      }
      break;
    
    case idle:
      newHyphae();
      break;
  }
}

void ofApp::draw(){
  switch (lifecycleStage) {
    case alive:
      hyphae->draw();
      break;
    
    case mourning:
      break;
    
    case fadeout:
      if (ofGetFrameNum() % fadeoutFramesPeriod == 0) {
        ofPushStyle();
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        ofSetColor(settings->canvas.backgroundColor, 1);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        ofPopStyle();
      }
      break;
    
    case idle:
      break;
  }
  drawOSD();
}

void ofApp::drawOSD() {
  osd->draw(*settings.get(), currentParams, hyphae->getStats(), lifecycleStage);
}


void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      newHyphae();
      break;
    
    case 'f':
      ofToggleFullscreen();
      break;

    case 'o':
      osd->toggleActive();
      break;
      
    case 'b':
      hyphae->drawBorder();
      break;
    
    case 'c':
      ofPushStyle();
      ofSetColor(settings->canvas.backgroundColor);
      ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
      ofPopStyle();

    case 's':
      ofLog() << "seed: " << currentParams.seed;

    default:
      break;
  }
}
