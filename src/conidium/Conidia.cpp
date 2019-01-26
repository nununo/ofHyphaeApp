//
//  Conidia.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Conidia.h"

Conidia::Conidia(IDanceFactory *danceFactory, int conidiumLifespan) {
  this->danceFactory = danceFactory;
  this->conidiumLifespan = conidiumLifespan;
}

Conidia::~Conidia() {
  for( list<Conidium>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Conidia::add(ofVec3f p) {
  Dance *dance = this->danceFactory->getInstance(p);
  this->elements.push_back( Conidium(p, 0.00f, this->conidiumLifespan, dance) );
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
