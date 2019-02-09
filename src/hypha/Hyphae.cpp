//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"
#include "InkColor.h"

Hyphae::Hyphae(const HyphaeSettings settings) {
  this->ink = new InkColor(settings.color);
  this->settings = settings;
  generatePrimalHyphas();
}

Hyphae::~Hyphae() {
  delete ink;
}

ofVec3f Hyphae::calcDirection(const float angle, const float inclination) const {
  ofVec3f dir = ofVec3f(1,0,0).rotate(0,0,angle);
  ofVec3f dirPerp = dir.getNormalized().rotate(0,0,-90);
  return dir.getRotated(inclination, dirPerp);
}

void Hyphae::add(Hypha *hypha) {
  ofAddListener(hypha->forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(hypha->dieEvent, this, &Hyphae::onHyphaDie);
  elements.push_back(*hypha);
}

void Hyphae::addPrimalHypha(const float inclination) {
  ofVec3f dir = calcDirection(ofRandom(0,360), inclination);
  ofVec2f pos = ofVec2f(settings.creationAreaSize*ofRandom(0,1)).getRotated(ofRandom(0,360));
  add(new Hypha(pos, this->ink, dir, settings.hypha));
  primalHyphaCount++;
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(new Hypha(e.pos, this->ink, e.dir, settings.hypha, e.generation));
}

void Hyphae::onHyphaDie(HyphaDieEventArgs &e) {
  ofNotifyEvent(this->hyphaDieEvent, e);
}

void Hyphae::generatePrimalHyphas() {
  while (primalHyphaCount<settings.primalHyphaCount) {
    addPrimalHypha(0);
  }
}

void Hyphae::removeAllDeadHypha() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->dieEvent, this, &Hyphae::onHyphaDie);
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
}

void Hyphae::updateAllHypha() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
  }
}

void Hyphae::removeOlderHyphaIfOverpopulated() {
  int tooMany = elements.size() - settings.maxHyphaCount;
  for(auto &itr: elements) {
    if (tooMany-- > 0) {
      itr.die();
    }
  }
}

void Hyphae::update() {
  removeAllDeadHypha();
  removeOlderHyphaIfOverpopulated();
  updateAllHypha();
}

void Hyphae::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,255);
  for(auto &itr: elements) {
    itr.draw();
  }
  ofPopStyle();
}
