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
  
  if (settings.conidia.active) {
    this->conidia = new Conidia(conidiaInk, settings.conidia);
  }
  
  if (settings.hyphae.active) {
    this->hyphae = new Hyphae(settings.hyphae, border);
    ofAddListener(this->hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
  }
}

Mycelium::~Mycelium() {
  if (settings.hyphae.active) {
    ofRemoveListener(hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
    delete hyphae;
  }
  if (settings.conidia.active) {
    delete conidia;
  }
  delete border;
}

MyceliumStats Mycelium::getStats() {
  MyceliumStats stats;
  stats.hyphaCount = hyphaeCount();
  stats.conidiumCount = conidiaCount();
  return stats;
}

void Mycelium::onHyphaDie(HyphaDieEventArgs &e) {
  if (settings.conidia.active) {
    conidia->add(e.pos);
  }
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
