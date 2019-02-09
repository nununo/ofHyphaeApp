#include "ofApp.h"
#include "Mycelium.h"

void ofApp::setup(){
  settings = new Settings("settings/settings.xml");
  ofSetFrameRate(settings->framerate);
  //ofSetVerticalSync(true);
  ofSetWindowPosition(10, 10);
  ofSetWindowShape(settings->canvas.width, settings->canvas.height);
  ofDisableAlphaBlending();
  s = new Surface(ofVec2f(ofGetWidth(), ofGetHeight()), settings->canvas);
  
  this->conidiaInk = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 2);

  addFamily();
}

ofApp::~ofApp() {
  delete conidiaInk;
}

void ofApp::addFamily() {
  for(int i=0; i<1; i++) {
    s->addMycelium(new Mycelium(ofVec2f(ofGetWidth()/2, ofGetHeight()/2), /* ofRandom(250,600),ofRandom(250,600)*/
                                settings->mycelium,
                                conidiaInk));
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
  string fpsStr = "frame rate: "+ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(fpsStr, 10,10);
  ofPopStyle();
}

void ofApp::keyPressed(int key) {
  switch (key) {
    case ' ':
      // Space adds a new family (currently hiding the previous one because for now
      // this is just for convenience
      addFamily();
      break;
    
    case 'f':
      ofToggleFullscreen();
      break;
      
    default:
      break;
  }
}
