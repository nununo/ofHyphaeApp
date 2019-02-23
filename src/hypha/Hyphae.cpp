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
  this->primalHyphaCount = 0;
  this->sterile = false;
}

Hyphae::~Hyphae() {
  removeAllHypha(false);
}

void Hyphae::add(ofVec2f pos, ofVec2f dir, int generation) {
  elements.push_back(Hypha(pos, dir, border.get(), params.hypha, generation));
  ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
}

void Hyphae::generatePrimalHyphas() {
  if (count()>=params.maxHyphaCount) {
    // If we already reached the maximum possible hypha count then don't create more primal hypha
    primalHyphaCount = params.primalHyphaCount;
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
    if (onlyDead && !itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
}

void Hyphae::sterilizeIfFull() {
  if (elements.size() >= params.maxHyphaCount) {
    sterile = true;
  }
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  if (!sterile) {
    add(e.pos, e.dir, e.generation);
  }
}

HyphaeStats Hyphae::getStats() const {
  HyphaeStats stats;
  stats.hyphaCount = elements.size();
  stats.primalHyphaCount = this->primalHyphaCount;
  return stats;
}

void Hyphae::update() {
  sterilizeIfFull();
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
