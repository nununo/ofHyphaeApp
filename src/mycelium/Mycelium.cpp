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
  this->lifespan = settings.lifespan;

  if (settings.conidia.active) {
    this->conidia = new Conidia(conidiaInk, settings.conidia);
  }
  
  if (settings.hyphae.active) {
    this->hyphae = new Hyphae(settings.hyphae);
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
}

MyceliumStats Mycelium::getStats() {
  MyceliumStats stats;
  if (settings.hyphae.active) {stats.hyphaCount = hyphae->count();}
  if (settings.conidia.active) {stats.conidiumCount = conidia->count();}
  return stats;
}

void Mycelium::onHyphaDie(HyphaDieEventArgs &e) {
  if (settings.conidia.active) {
    conidia->add(e.pos);
  }
}

void Mycelium::update() {
  if (isAlive()) {
    growOlder();
    if (settings.conidia.active) {
      //perimeter->update();
      conidia->update();
    }
    if (settings.hyphae.active) {
      hyphae->update();
    }
  }
}

void Mycelium::drawHyphae() const {
  if (isAlive() && settings.hyphae.active) {
    ofPushMatrix();
    ofTranslate(this->pos);
    hyphae->draw();
    ofPopMatrix();
  }
}

void Mycelium::drawConidia() const {
  if (isAlive() && settings.conidia.active) {
    ofPushMatrix();
    ofTranslate(this->pos);
    conidia->draw();
    ofPopMatrix();
  }
}
