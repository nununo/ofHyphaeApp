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

  if (settings.hyphae.active) {
    this->hyphae = new Hyphae(settings.hyphae, border);
  }

  if (settings.conidia.active) {
    this->conidia = new Conidia(conidiaInk, settings.conidia);
    this->rings = new Rings(settings.holes);
    ofAddListener(this->hyphae->hyphaPositionEvent, this, &Mycelium::onHyphaPosition);
    ofAddListener(this->rings->holeFilledEvent, this, &Mycelium::onRingsHoleFilled);
  }
}

Mycelium::~Mycelium() {
  if (settings.hyphae.active) {
    delete hyphae;
  }
  if (settings.conidia.active) {
    ofRemoveListener(hyphae->hyphaPositionEvent, this, &Mycelium::onHyphaPosition);
    ofRemoveListener(rings->holeFilledEvent, this, &Mycelium::onRingsHoleFilled);
    delete conidia;
    delete rings;
  }
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
  if (settings.conidia.active) {
    conidia->update();
  }
  if (settings.hyphae.active) {
    hyphae->update();
  }
}

void Mycelium::drawHyphae() const {
  if (settings.hyphae.active) {
    ofPushMatrix();
    ofTranslate(this->pos);
    hyphae->draw();
    border->draw();
    rings->draw();
    ofPopMatrix();
  }
}

void Mycelium::drawConidia() const {
  if (settings.conidia.active) {
    ofPushMatrix();
    ofTranslate(this->pos);
    conidia->draw();
    ofPopMatrix();
  }
}
