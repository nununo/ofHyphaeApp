//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.hpp"

Surface::Surface(ofVec2f size) {
  this->size = size;
  fbo.allocate(getWidth(), getHeight());
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
  ofClear(0,0,0);
  for( list<IDrawable*>::iterator itr = parts.begin(); itr != parts.end(); ++itr ) {
    (*itr)->draw();
  }
  fbo.end();

  fbo.draw(0,0);
}
