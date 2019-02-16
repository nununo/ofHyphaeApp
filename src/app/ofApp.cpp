#include "ofApp.h"
#include "Mycelium.h"

void ofApp::setup(){
  settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->framerate);
  //ofSetVerticalSync(true);
  ofDisableAlphaBlending();
  s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()), settings->canvas, settings->mycelium);
  
  this->conidiaInk = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 2);

  addMycelium();
}

ofApp::~ofApp() {
  delete conidiaInk;
}

void ofApp::addMycelium() {
  for(int i=0; i<1; i++) {
    s->addMycelium(ofVec2f(ofRandom(0+ofGetWidth()/5,ofGetWidth()-ofGetWidth()/5),
                                        ofRandom(0+ofGetHours()/5,ofGetHeight()-ofGetHeight()/5)),
                                conidiaInk);
  }
}

void ofApp::update(){
  s->update();
}

void ofApp::draw(){
  s->draw();
  drawOSD();
}

void ofApp::drawOSD() {
  ofPushStyle();
  ofSetColor(settings->osdColor);

  string str = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(str, 10,10);

  MyceliaStats stats = s->getMyceliaStats();

  str = "mycelia: "+ofToString(stats.myceliaCount);
  ofDrawBitmapString(str, 10,25);

  str = "hyphae: "+ofToString(stats.hyphaCount);
  ofDrawBitmapString(str, 10,40);

  str = "conidia: "+ofToString(stats.conidiumCount);
  ofDrawBitmapString(str, 10,55);

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
