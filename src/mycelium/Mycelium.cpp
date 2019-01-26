//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

Mycelium::Mycelium(ofVec3f pos, int size, float growthSpeed, int lifespan,
               int conidiumLifespan, float conidiumDistance,
               float perimeterDistortion,
               ISpeciesFactory *danceFactory) {
  this->pos = pos;
  this->conidia = new Conidia(danceFactory, conidiumLifespan);
  this->hyphaeInk = new InkColor(ofColor::black, 20); // ofColor::fromHsb(ofRandom(0,255), 255, 255)
  this->hyphae = new Hyphae(this->hyphaeInk);
  this->lifespan = lifespan;
  this->perimeter = new Perimeter(growthSpeed, conidiumDistance, perimeterDistortion);

  //conidia->add(ofVec3f(0,0,0));
  addHypha();

  //ofAddListener(this->perimeter->newConidiumEvent, this, &Mycelium::onNewConidiumEvent);
}

Mycelium::~Mycelium() {
  delete this->conidia;
  delete this->hyphae;
  delete this->hyphaeInk;
}

void Mycelium::onNewConidiumEvent(NewConidiumEvent &e) {
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
  hyphae->add(ofVec2f(0,0), vel);
}

void Mycelium::grow() {
  if (isAlive()) {
    this->lifespan--;
  }
}