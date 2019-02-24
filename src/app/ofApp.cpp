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
  restart();
}

void ofApp::restart() {
  HyphaeParamsBuilder builder;
 currentParams = builder.create(*settings.get());
  hyphae.reset(new Hyphae(currentParams));
  ofBackground(settings->canvas.backgroundColor);
}

void ofApp::update(){
  if (!hyphae->isAlive()) {
    restart();
  }
  hyphae->update();
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
      restart();
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
