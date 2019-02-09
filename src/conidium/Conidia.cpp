//
//  Conidia.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Conidia.h"

Conidia::Conidia(Ink *ink, const ConidiaSettings settings) {
  this->ink = ink;
  this->settings = settings;
}

Conidia::~Conidia() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Conidia::add(ofVec3f p) {
  Conidium *conidium = new Conidium(p, 0.00f, this->settings.conidium, ink);
  this->elements.push_back( *conidium );
}

void Conidia::update() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
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
  for(auto &itr: elements) {
    itr.draw();
  }
  ofPopStyle();
}
