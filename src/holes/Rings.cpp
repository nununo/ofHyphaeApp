//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Rings.h"

Rings::Rings(ConidiaSettings settings) {
  this->settings = settings;
  for (int r=0; r<settings.maxRings; r++) {
    rings[r] = new Ring(settings.space, r*settings.space);
  }
}

ofVec2f Rings::fill(int ring, float angle) {
  return rings[ring]->fill(angle);
}

void Rings::draw() {
  for(int ring=1; ring<30; ring++) {
    rings[ring]->draw();
  }
}
