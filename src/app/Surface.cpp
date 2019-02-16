//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.h"

Surface::Surface(const ofVec2f size, const CanvasSettings settings) {
  this->size = size;
  this->settings = settings;

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, settings.shaderFilename);
  shader.linkProgram();

  initializeFbo(&fboHyphae, settings.backgroundColor);
  initializeFbo(&fboConidia, ofColor(0,0,0,255));
}

Surface::~Surface() {
  for(auto itr = mycelia.begin(); itr != mycelia.end(); ++itr ) {
    itr = mycelia.erase(itr);
  }
}

void Surface::initializeFbo(ofFbo *fbo, ofColor backgroundColor) {
  fbo->allocate(getWidth(), getHeight());
  fbo->begin();
  ofPushStyle();
  ofClear(backgroundColor);
  ofPopStyle();
  fbo->end();
}

MyceliumStats Surface::getMyceliaStats() {
  MyceliumStats globalStats;
  for(auto &itr: mycelia) {
    auto stats = itr->getStats();
    globalStats.hyphaCount += stats.hyphaCount;
    globalStats.conidiumCount += stats.conidiumCount;
  }
  return globalStats;
}

void Surface::update() {
  for(auto itr = mycelia.begin(); itr != mycelia.end(); ++itr ) {
    if ((*itr)->isAlive()) {
      (*itr)->update();
    } else {
      itr = mycelia.erase(itr);
    }
  }
}

void Surface::drawPartsToFbo() {
  fboHyphae.begin();
  for(auto &itr: mycelia) {
    itr->drawHyphae();
  }
  fboHyphae.end();

  fboConidia.begin();
  for(auto &itr: mycelia) {
    itr->drawConidia();
  }
  fboConidia.end();
}

void Surface::draw() {
  drawPartsToFbo();

  ofPushStyle();
  ofClear(0,0,0);
  ofEnableAlphaBlending();
  shader.begin();
  shader.setUniformTexture("conidiaTex", fboConidia.getTexture(), 2 );
  fboHyphae.draw(0, 0);
  shader.end();
  ofDisableAlphaBlending();
  ofPopStyle();
}
