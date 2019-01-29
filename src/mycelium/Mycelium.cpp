//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

#define HYPHAE_INK_TRANSPARENCY 20 //3

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, ISpeciesFactory *danceFactory) {
  this->pos = pos;
  this->conidia = new Conidia(danceFactory, settings.conidia);
  this->hyphaeInk = new InkColor(ofColor::black, HYPHAE_INK_TRANSPARENCY);
  this->hyphae = new Hyphae(this->hyphaeInk, settings.hyphae);
  this->lifespan = settings.lifespan;
}

Mycelium::~Mycelium() {
  delete this->conidia;
  delete this->hyphae;
  delete this->hyphaeInk;
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
