//
//  Mycelia.cpp
//  moldApp
//
//  Created by Nuno on 16/02/2019.
//

#include "Mycelia.h"
#include "MyceliumParamsBuilder.h"

Mycelia::Mycelia(const MyceliumSettings settings) {
  this->settings = settings;
}

Mycelia::~Mycelia() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Mycelia::add(ofVec3f pos)  {
  MyceliumParams params = MyceliumParamsBuilder(settings).create();
  elements.push_back(new Mycelium(pos, settings, params));
}

MyceliaStats Mycelia::getStats() {
  MyceliaStats stats;
  for(auto &itr: elements) {
    auto myceliumStats = itr->getStats();
    stats.hyphaCount += myceliumStats.hyphaCount;
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

void Mycelia::draw() {
  for(auto &itr: elements) {
    itr->draw();
  }
}
