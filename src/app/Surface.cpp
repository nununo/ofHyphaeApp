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
  
  mask.load(settings.maskFilename);
  mask.resize(getWidth(), getHeight());

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, settings.shaderFilename);
  shader.linkProgram();

  fbo.allocate(getWidth(), getHeight());
  fbo.begin();
  ofClear(settings.backgroundColor);
  fbo.end();
}

Surface::~Surface() {
  for(auto itr = mycelia.begin(); itr != mycelia.end(); ++itr ) {
    itr = mycelia.erase(itr);
  }
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
  fbo.begin();
  for(auto &itr: mycelia) {
    itr->draw();
  }
  fbo.end();
}

void Surface::draw() {
  drawPartsToFbo();

  ofPushStyle();
  ofClear(0,0,0);
  ofEnableAlphaBlending();
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  fbo.draw(0, 0);
  shader.end();
  ofDisableAlphaBlending();
  ofPopStyle();
}
