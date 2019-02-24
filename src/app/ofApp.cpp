#include "ofApp.h"
#include "HyphaeParamsBuilder.h"
#include "OSD.h"

void ofApp::setup(){
  settings.reset(new Settings("settings/settings.xml"));
  osd.reset(new OSD());
  //ofSetVerticalSync(true);
  ofSetFrameRate(settings->canvas.framerate);
  ofSetBackgroundAuto(false);
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
        lifecycleStage = mourn;
        mourningFrames = settings->canvas.mourningTime * settings->canvas.framerate;
      }
      break;
    
    case mourn:
      if (mourningFrames > 0) {
        mourningFrames--;
      } else {
        lifecycleStage = idle;
      }
      break;
    
    case fadeout:
      break;
    
    case idle:
      newHyphae();
      break;
  }
}

void ofApp::draw(){
  hyphae->draw();
  drawOSD();
}

void ofApp::drawOSD() {
  OSD osd;
  osd.draw(*settings.get(), currentParams, hyphae->getStats());
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
    
    case 's':
      ofLog() << "seed: " << currentParams.seed;

    default:
      break;
  }
}
