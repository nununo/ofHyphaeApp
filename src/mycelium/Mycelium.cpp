//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"

Mycelium::Mycelium(const MyceliumSettings settings, MyceliumParams params) {
  this->pos = params.hyphae.position;
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
  stats.hyphaCount = hyphae->count();
  stats.primalHyphaCount = hyphae->primalCount();
  return stats;
}

void Mycelium::update() {  
  hyphae->update();
}

void Mycelium::draw() const {
  ofPushMatrix();
  ofTranslate(this->pos);
  hyphae->draw();
  ofPopMatrix();
}
