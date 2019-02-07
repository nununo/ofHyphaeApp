//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, ISpeciesFactory *danceFactory, Ink *hyphaeInk) {
  this->pos = pos;
  this->settings = settings;
  this->lifespan = settings.lifespan;
  this->hyphaeInk = hyphaeInk;

  if (settings.conidia.active) {
    this->perimeter = new Perimeter(settings.holes);
    ofAddListener(this->perimeter->emptyHoleReachedEvent, this, &Mycelium::onEmptyHoleReachedEvent);
    this->conidia = new Conidia(danceFactory, settings.conidia);
  }
  
  if (settings.hyphae.active) {
    this->hyphae = new Hyphae(this->hyphaeInk, settings.hyphae);
    ofAddListener(this->hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
  }
}

Mycelium::~Mycelium() {
  if (settings.hyphae.active) {
    ofRemoveListener(hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
    delete hyphae;
  }
  if (settings.conidia.active) {
    ofRemoveListener(perimeter->emptyHoleReachedEvent, this, &Mycelium::onEmptyHoleReachedEvent);
    delete conidia;
    delete perimeter;
  }
}

void Mycelium::onEmptyHoleReachedEvent(EmptyHoleReachedEventArgs &e) {
  if (settings.conidia.active) {
    conidia->add(e.pos);
  }
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

void Mycelium::draw() {
  if (isAlive()) {
    ofPushMatrix();
    ofTranslate(this->pos);
    if (settings.hyphae.active) {
      hyphae->draw();
    }
    if (settings.conidia.active) {
      conidia->draw();
    }
    ofPopMatrix();
  }
}
