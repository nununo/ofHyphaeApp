//
//  Mycelia.cpp
//  moldApp
//
//  Created by Nuno on 16/02/2019.
//

#include "Mycelia.h"

Mycelia::Mycelia(const MyceliumSettings settings) {
  this->settings = settings;
}

Mycelia::~Mycelia() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Mycelia::add(ofVec3f pos, Ink *conidiaInk)  {
  elements.push_back(new Mycelium(pos, settings, conidiaInk));
}

MyceliaStats Mycelia::getStats() {
  MyceliaStats stats;
  for(auto &itr: elements) {
    auto myceliumStats = itr->getStats();
    stats.hyphaCount += myceliumStats.hyphaCount;
    stats.conidiumCount += myceliumStats.conidiumCount;
  }
  stats.myceliaCount = elements.size();
  return stats;
}

void Mycelia::update() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    if ((*itr)->isAlive()) {
      (*itr)->update();
    } else {
      itr = elements.erase(itr);
    }
  }
}

void Mycelia::drawHyphae() {
  for(auto &itr: elements) {
    itr->drawHyphae();
  }}

void Mycelia::drawConidia() {
  for(auto &itr: elements) {
    itr->drawConidia();
  }
}
