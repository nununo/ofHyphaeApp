//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.h"

Surface::Surface(const ofVec2f size, const ofColor backgroundColor) {
  this->size = size;
  this->backgroundColor = backgroundColor;
  fbo.allocate(getWidth(), getHeight());
  fbo.begin();
  ofClear(backgroundColor);
  fbo.end();
}

Surface::~Surface() {
  for( list<IDrawable*>::iterator itr = parts.begin(); itr != parts.end(); ++itr ) {
    itr = parts.erase(itr);
  }
}

void Surface::update() {
  for( list<IDrawable*>::iterator itr = parts.begin(); itr != parts.end(); ++itr ) {
    if ((*itr)->isAlive()) {
      (*itr)->update();
    } else {
      itr = parts.erase(itr);
    }
  }
}

void Surface::draw() {
  fbo.begin();
  for( list<IDrawable*>::iterator itr = parts.begin(); itr != parts.end(); ++itr ) {
    (*itr)->draw();
  }
  fbo.end();

  fbo.draw(0,0);
}
