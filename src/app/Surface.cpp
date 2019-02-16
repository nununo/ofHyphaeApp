//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.h"

Surface::Surface(const ofVec2f size, const CanvasSettings settings, const MyceliumSettings myceliumSettings) {
  this->size = size;
  this->settings = settings;

  this->mycelia = new Mycelia(myceliumSettings);

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, settings.shaderFilename);
  shader.linkProgram();

  initializeFbo(&fboHyphae, ofColor(0,0,0,0));
  initializeFbo(&fboConidia, ofColor(0,0,0,255));
}

Surface::~Surface() {
  delete mycelia;
}

void Surface::initializeFbo(ofFbo *fbo, ofColor backgroundColor) {
  fbo->allocate(size.x, size.y);
  fbo->begin();
  ofPushStyle();
  ofClear(backgroundColor);
  ofPopStyle();
  fbo->end();
}

void Surface::update() {
  mycelia->update();
}

void Surface::drawPartsToFbo() {
  fboHyphae.begin();
  mycelia->drawHyphae();
  fboHyphae.end();

  fboConidia.begin();
  mycelia->drawConidia();
  fboConidia.end();
}

void Surface::draw() {
  drawPartsToFbo();

  ofClear(settings.backgroundColor);
  ofPushStyle();
  ofEnableAlphaBlending();
  shader.begin();
  shader.setUniformTexture("conidiaTex", fboConidia.getTexture(), 2 );
  fboHyphae.draw(0, 0);
  shader.end();
  ofDisableAlphaBlending();
  ofPopStyle();
}
