//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, Ink *conidiaInk) {
  this->pos = pos;
  this->settings = settings;
  this->wasAlreadyAlive = false;

  this->border = new Border(settings.border);
  this->hyphae = new Hyphae(settings.hyphae, border);
  this->conidia = new Conidia(conidiaInk, settings.conidia);
  this->rings = new Rings(settings.holes);

  if (settings.conidia.active) {
    ofAddListener(this->hyphae->hyphaPositionEvent, this, &Mycelium::onHyphaPosition);
    ofAddListener(this->rings->holeFilledEvent, this, &Mycelium::onRingsHoleFilled);
  }
}

Mycelium::~Mycelium() {
  if (settings.conidia.active) {
    ofRemoveListener(hyphae->hyphaPositionEvent, this, &Mycelium::onHyphaPosition);
    ofRemoveListener(rings->holeFilledEvent, this, &Mycelium::onRingsHoleFilled);
  }
  delete hyphae;
  delete conidia;
  delete rings;
  delete border;
}

MyceliumStats Mycelium::getStats() {
  MyceliumStats stats;
  stats.hyphaCount = hyphaeCount();
  stats.conidiumCount = conidiaCount();
  return stats;
}

void Mycelium::onHyphaPosition(PositionEventArgs &e) {
  rings->fill(e.pos);
}

void Mycelium::onRingsHoleFilled(PositionEventArgs &e) {
  conidia->add(e.pos);
}

void Mycelium::update() {  
  hyphae->update();
  if (settings.conidia.active) {
    conidia->update();
  }
}

void Mycelium::drawHyphae() const {
  ofPushMatrix();
  ofTranslate(this->pos);
  hyphae->draw();
  //border->draw();
  //rings->draw();
  ofPopMatrix();
}

void Mycelium::drawConidia() const {
  if (settings.conidia.active) {
    ofPushMatrix();
    ofTranslate(this->pos);
    conidia->draw();
    ofPopMatrix();
  }
}
