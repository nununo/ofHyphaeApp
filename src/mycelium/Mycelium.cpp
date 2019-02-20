//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, MyceliumParams params) {
  this->pos = pos;
  this->settings = settings;
  this->params = params;
  this->wasAlreadyAlive = false;

  this->border = new Border(params.border);
  this->hyphae = new Hyphae(params.hyphae, border);
}

Mycelium::~Mycelium() {
  delete hyphae;
  delete border;
}

MyceliumStats Mycelium::getStats() {
  MyceliumStats stats;
  stats.hyphaCount = hyphaeCount();
  return stats;
}

void Mycelium::update() {  
  hyphae->update();
}

void Mycelium::draw() const {
  ofPushMatrix();
  ofTranslate(this->pos);
  hyphae->draw();
  border->draw();
  ofPopMatrix();
}
