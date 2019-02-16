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
  this->radius = ofRandom(settings.radiusRange.x, settings.radiusRange.y);
  this->wasAlreadyAlive = false;

  if (settings.conidia.active) {
    this->conidia = new Conidia(conidiaInk, settings.conidia);
  }
  
  if (settings.hyphae.active) {
    this->hyphae = new Hyphae(settings.hyphae, this->radius);
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
  stats.hyphaCount = hyphaeCount();
  stats.conidiumCount = conidiaCount();
  return stats;
}

void Mycelium::onHyphaDie(HyphaDieEventArgs &e) {
  if (settings.conidia.active) {
    conidia->add(e.pos);
  }
}

void Mycelium::growOlder() {
  lifespan--;
  // It can only die after it was alive (at least one conidium or hypha existed)
  if (!wasAlreadyAlive) {
    if (conidiaCount() > 0 || hyphaeCount() > 0) {
      wasAlreadyAlive = true;
    }
  } else if (conidiaCount() == 0 && hyphaeCount() == 0) {
    die();
  }
}

void Mycelium::update() {  
  if (isAlive()) {
    if (settings.conidia.active) {
      conidia->update();
    }
    if (settings.hyphae.active) {
      hyphae->update();
    }
    growOlder();
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
