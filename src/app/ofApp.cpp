#include "ofApp.h"
#include "HyphaeParamsBuilder.h"

void ofApp::setup(){
  this->settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->canvas.framerate);
  this->builder = new HyphaeParamsBuilder(settings->hyphae);
  this->osd = new OSD(settings);
  //ofSetVerticalSync(true);
  ofSetBackgroundAuto(false);
  ofBackground(settings->canvas.backgroundColor);
  restart();
}

ofApp::~ofApp() {
  delete hyphae;
  delete settings;
  delete builder;
  delete osd;
}

void ofApp::restart() {
  if (hyphae) {
    delete hyphae;
  }
  currentParams = builder->create();
  hyphae = new Hyphae(currentParams);
  ofBackground(settings->canvas.backgroundColor);
}

void ofApp::update(){
  hyphae->update();
}

void ofApp::draw(){
  hyphae->draw();
  osd->draw(currentParams, hyphae->getStats());
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
