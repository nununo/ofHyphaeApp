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
  this->lifespan = settings.lifespan;
  this->hyphaeInk = hyphaeInk;

  this->dc = new DistortedCircle(settings.conidia.perimeterDistortion); // TODO
  this->perimeter = new Perimeter(settings.conidia, dc); // TODO Perimeter settings are not in the right place
  ofAddListener(this->perimeter->emptyHoleReachedEvent, this, &Mycelium::onEmptyHoleReachedEvent);

  this->conidia = new Conidia(danceFactory, settings.conidia);
  
  this->hyphae = new Hyphae(this->hyphaeInk, settings.hyphae);
  ofAddListener(this->hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
}

Mycelium::~Mycelium() {
  delete conidia;
  ofRemoveListener(hyphae->hyphaDieEvent, this, &Mycelium::onHyphaDie);
  delete hyphae;
  delete perimeter;
  delete dc;
}

void Mycelium::onEmptyHoleReachedEvent(EmptyHoleReachedEventArgs &e) {
  conidia->add(e.pos);
}

void Mycelium::onHyphaDie(HyphaDieEventArgs &e) {
  
}

void Mycelium::update() {
  if (isAlive()) {
    growOlder();
    perimeter->update();
    //conidia->update();
    hyphae->update();
  }
}

void Mycelium::draw() {
  if (isAlive()) {
    ofPushMatrix();
    ofTranslate(this->pos);
    hyphae->draw();
    conidia->draw();
    ofPopMatrix();
  }
}
