//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

Hyphae::Hyphae(const HyphaeParams params) {
  this->params = params;
  this->border = new Border(params.border);
  this->newPrimalHyphaFramesPeriod = ofGetFrameRate() * params.newPrimalHyphaPeriod;
  this->primalHyphaCount = 0;
  this->sterile = false;
}

Hyphae::~Hyphae() {
  removeAllHypha(false);
  delete border;
}

void Hyphae::add(Hypha *hypha) {
  ofAddListener(hypha->forkEvent, this, &Hyphae::onHyphaFork);
  elements.push_back(*hypha);
}

void Hyphae::generatePrimalHyphas() {
  if (primalHyphaCount < params.primalHyphaCount &&
      (newPrimalHyphaFramesPeriod == 0 || ofGetFrameNum() % newPrimalHyphaFramesPeriod == 0)) {
    float angle = ofRandom(0,360);
    ofVec3f dir = ofVec3f(1,0,0).rotate(0,0,angle);
    ofVec2f pos = ofVec2f(params.creationAreaSize*ofRandom(0,1)).getRotated(ofRandom(0,360));
    add(new Hypha(pos, dir, border, params.hypha));
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
    add(new Hypha(e.pos, e.dir, border, params.hypha, e.generation));
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
