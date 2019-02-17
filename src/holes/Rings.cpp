//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Rings.h"

Rings::Rings(HolesSettings settings) {
  this->settings = settings;
  for (int i=0; i<settings.maxRings; i++) {
    Ring *r = new Ring(settings.space, i*settings.space);
    rings[i] = r;
    ofAddListener(r->holeFilledEvent, this, &Rings::onHoleFilled);
  }
}

void Rings::onHoleFilled(PositionEventArgs &e) {
  ofNotifyEvent(this->holeFilledEvent, e);
}

void Rings::fill(ofVec2f pos) {
  float angle = ofVec2f(1,0).angle(pos);
  int i = getRing(pos.length());
  rings[i]->fill(angle);
}

void Rings::draw() {
  for(int ring=1; ring<settings.maxRings; ring++) {
    rings[ring]->draw();
  }
}