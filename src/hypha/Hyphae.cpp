//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaeParams params) {
  this->params = params;
  this->border.reset(new Border(params.border));
}

Hyphae::~Hyphae() {
  removeAllHypha(false);
}

void Hyphae::add(ofVec2f pos, ofVec2f dir, int generation) {
  if (!sterile) {
    wasAlive = true;
    elements.push_back(Hypha(pos, dir, border.get(), params.hypha, generation));
    ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
    ofAddListener(elements.back().outsideEvent, this, &Hyphae::onHyphaOutside);
  }
}

void Hyphae::generatePrimalHyphas() {
  if (sterile) {
    return; // If maximum possible hypha count reached, don't create more primal hypha
  }
  if (primalHyphaCount < params.primalHyphaCount &&
      (params.newPrimalHyphaFramesPeriod == 0 || ofGetFrameNum() % params.newPrimalHyphaFramesPeriod == 0)) {
    ofVec2f dir = ofVec2f(1,0).getRotated(ofRandom(0,360));
    ofVec2f pos = ofVec2f(params.creationAreaSize*ofRandom(0,1)).getRotated(ofRandom(0,360));
    add(pos, dir, 0);
    primalHyphaCount++;
  }
}

void Hyphae::removeAllHypha(bool onlyDead) {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!onlyDead || !itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->outsideEvent, this, &Hyphae::onHyphaOutside);
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
}

void Hyphae::updateLifecycle() {
  if (elements.size() >= params.maxHyphaCount) {
    sterile = true;
  }
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.pos, e.dir, e.generation);
}

void Hyphae::onHyphaOutside(ofEventArgs &e) {
  // When the first Hypha goes outside the border the dying process starts:
  // - Become sterile (so that no more Hypha are created
  // - Set dying = true
  // - Set all Hypha with a random energy
  if (!dying) {
    ofLog() << "dying";
    sterile = true;
    dying = true;
    for( auto& element : elements ) {
      element.setEnergy(ofRandom(150));
    }
  }
}

HyphaeStats Hyphae::getStats() const {
  HyphaeStats stats;
  stats.hyphaCount = elements.size();
  stats.primalHyphaCount = this->primalHyphaCount;
  return stats;
}

void Hyphae::update() {
  updateLifecycle();
  removeAllHypha(true);
  generatePrimalHyphas();
}

void Hyphae::drawBorder() const {
  ofPushMatrix();
  ofTranslate(params.position);
  border->draw();
  ofPopMatrix();
}

void Hyphae::draw() {
  ofPushMatrix();
  ofTranslate(params.position);
  ofPushStyle();
  ofSetColor(params.hypha.color);
  for(auto &itr: elements) {
    itr.draw();
  }
  ofPopStyle();
  ofPopMatrix();
}
