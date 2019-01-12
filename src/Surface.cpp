//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.hpp"

Surface::Surface(Family *family, ofVec2f size) {
  this->family = family;
  this->size = size;
  fbo.allocate(getWidth(), getHeight());
}

void Surface::update() {
  family->update();

  fbo.begin();
  ofClear(0,0,0);
  family->draw();
  fbo.end();
}

void Surface::draw() {
  fbo.draw(0,0);
}
