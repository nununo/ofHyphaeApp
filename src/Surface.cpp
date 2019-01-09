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
  fbo.begin();
  image.draw(0,0, getWidth(), getHeight());
  family->draw();
  fbo.end();
}

void Surface::draw() {
  ofSetColor(255,255);
  fbo.draw(0,0);
}
