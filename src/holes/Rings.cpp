//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Rings.h"
#include "Tools.h"

Rings::Rings(HolesSettings settings, Border *border) {
  this->settings = settings;
  for (int i=0; i<settings.maxRings; i++) {
    Ring *r = new Ring(settings, i, border);
    rings[i] = r;
    ofAddListener(r->holeFilledEvent, this, &Rings::onHoleFilled);
  }
}

Rings::~Rings() {
  for (int i=0; i<settings.maxRings; i++) {
    ofRemoveListener(rings[i]->holeFilledEvent, this, &Rings::onHoleFilled);
    delete rings[i];
  }
}

void Rings::onHoleFilled(PositionEventArgs &e) {
  ofNotifyEvent(this->holeFilledEvent, e);
}

void Rings::fill(ofVec2f pos) {
  float angle = Tools::posToAngle(pos);
  int i = getRing(pos.length());
  if (i<settings.maxRings) {
    rings[i]->fill(angle);
  }
}

void Rings::draw() {
  for(int ring=1; ring<settings.maxRings; ring++) {
    rings[ring]->draw();
  }
}
