//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

#define HYPHAE_INK_TRANSPARENCY 10

Mycelium::Mycelium(ofVec3f pos, const MyceliumSettings settings, ISpeciesFactory *danceFactory) {
  this->pos = pos;
  this->conidia = new Conidia(danceFactory, settings.conidia);
  this->hyphaeInk = new InkColor(ofColor::black, HYPHAE_INK_TRANSPARENCY);
  this->hyphae = new Hyphae(this->hyphaeInk, settings.hyphae);
  this->lifespan = settings.lifespan;
  this->perimeter = new Perimeter(settings.conidia);

  //conidia->add(ofVec3f(0,0,0));
  for(int i=0; i<10; i++) {
    addHypha();
  }

  //ofAddListener(this->perimeter->newConidiumEvent, this, &Mycelium::onNewConidiumEvent);
}

Mycelium::~Mycelium() {
  delete this->conidia;
  delete this->hyphae;
  delete this->hyphaeInk;
  delete this->perimeter;
}

void Mycelium::onNewConidiumEvent(EmptyHoleReachedEvent &e) {
  conidia->add(e.pos);
}

void Mycelium::update() {
  if (isAlive()) {
    grow();
    perimeter->update();
    conidia->update();
    hyphae->update();
  }
}

void Mycelium::draw() {
  if (isAlive()) {
    ofPushMatrix();
    ofTranslate(this->pos);
    hyphae->draw();
    conidia->draw();
    //perimeter->draw();
    ofPopMatrix();
  }
}

void Mycelium::addHypha() {
  ofVec2f vel = ofVec2f(0.01f,.01f).rotate(ofRandom(0,360));
  hyphae->add(vel);
}

void Mycelium::grow() {
  if (isAlive()) {
    this->lifespan--;
  }
}
