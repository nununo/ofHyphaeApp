//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.hpp"

Surface::Surface(Family *family, const std::filesystem::path imageFilename, ofVec2f size) {
  image.load(imageFilename);
  this->family = family;
  this->size = size;
  fbo.allocate(getWidth(), getHeight());
}

void Surface::update() {
  family->update();

  fbo.begin();
  ofEnableAlphaBlending();
  ofClear(0,0,0);
  ofSetColor(255,0,0,100);
  image.draw(0,0, getWidth(), getHeight());
  image.unbind(); // So that it does not become tex0 for MaskedSurface's shader
  ofSetColor(255,255,255,255);
  family->draw();
  fbo.end();
}

void Surface::draw() {
  fbo.draw(0,0);
}
