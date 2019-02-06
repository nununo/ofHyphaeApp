//
//  Conidia.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Conidia.h"

Conidia::Conidia(ISpeciesFactory *speciesFactory, const ConidiaSettings settings) {
  this->speciesFactory = speciesFactory;
  this->settings = settings;
  add(ofVec2f(0,0));
}

Conidia::~Conidia() {
  for( list<Conidium>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Conidia::add(ofVec3f p) {
  ConidiumDance *dance = this->speciesFactory->getConidiumDanceInstance(p);
  this->elements.push_back( Conidium(p, 0.00f, this->settings.conidium, dance) );
}

void Conidia::update() {
  for( list<Conidium>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
}

void Conidia::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,255);
  for( list<Conidium>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->draw();
  }
  ofPopStyle();
}
