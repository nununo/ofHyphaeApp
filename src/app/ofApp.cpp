#include "ofApp.h"
#include "HyphaeParamsBuilder.h"

void ofApp::setup(){
  settings.reset(new Settings("settings/settings.xml"));
  osd.reset(new OSD(settings.get()));
  //ofSetVerticalSync(true);
  ofSetFrameRate(settings->canvas.framerate);
  ofSetBackgroundAuto(false);
  ofBackground(settings->canvas.backgroundColor);
  restart();
}

void ofApp::restart() {
  HyphaeParamsBuilder builder(settings->hyphae);
 currentParams = builder.create();
  hyphae.reset(new Hyphae(currentParams));
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
