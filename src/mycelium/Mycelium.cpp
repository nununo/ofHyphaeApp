//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, ISpeciesFactory *danceFactory) {
  this->pos = pos;
  this->lifespan = settings.lifespan;

  this->dc = new DistortedCircle(settings.conidia.perimeterDistortion); // TODO
  this->hyphaeInk = new InkColor(ofColor::black);
  this->conidia = new Conidia(danceFactory, settings.conidia, this->dc);
  this->hyphae = new Hyphae(this->hyphaeInk, settings.hyphae);
}

Mycelium::~Mycelium() {
  delete this->conidia;
  delete this->hyphae;
  delete this->hyphaeInk;
  delete this->dc;
}

void Mycelium::update() {
  if (isAlive()) {
    this->lifespan--;
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
