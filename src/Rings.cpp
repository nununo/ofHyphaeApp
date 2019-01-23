//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Rings.h"

Rings::Rings(float space) {
  this->space = space;
  for (int r=0; r<MAX_RINGS; r++) {
    rings[r] = new Ring(this->space, r*this->space);
  }
}

bool Rings::fill(int ring, float angle) {
  return rings[ring]->fill(angle);
}

void Rings::draw() {
  ofPushStyle();
  ofSetColor(0, 255, 0);
  for(int ring=1; ring<MAX_RINGS; ring++) {
    rings[ring]->draw();
  }
  ofPopStyle();
}
