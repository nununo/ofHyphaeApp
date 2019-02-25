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
  removeAllHypha();
}

void Hyphae::add(ofVec2f pos, ofVec2f dir, int generation) {
  if (!sterile) {
    elements.push_back(Hypha(pos, dir, border.get(), params.hypha, generation));
    ofAddListener(elements.back().forkEvent, this, &Hyphae::onHyphaFork);
    ofAddListener(elements.back().outsideEvent, this, &Hyphae::onHyphaOutside);
  }
}

void Hyphae::generatePrimal() {
  if (sterile) {
    // If we already reached the maximum possible hypha count then don't create more primal hypha
    return;
  }
  if (primalHyphaCount < params.primalHyphaCount &&
      (params.newPrimalHyphaFramesPeriod == 0 ||
       ofGetFrameNum() % params.newPrimalHyphaFramesPeriod == 0)) {
    ofVec2f dir = ofVec2f(1,0).getRotated(ofRandom(0,360));
    ofVec2f pos = ofVec2f(params.creationAreaSize*ofRandom(0,1)).getRotated(ofRandom(0,360));
    add(pos, dir, 0);
    primalHyphaCount++;
  }
}

void Hyphae::removeAllHypha(const int quantity) {
  int erased = 0;
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
    ofRemoveListener(itr->outsideEvent, this, &Hyphae::onHyphaOutside);
    itr = elements.erase(itr);
    // If quantity is provided and > 0 we stop erasing after reaching that quantity
    if (quantity > 0 && ++erased>=quantity) {
      return;
    }
  }
  if (count()==0) {
    dead = true;
  }
}

int Hyphae::getDyingPerFrame() {
  int frames = count() / params.dyingFrames;
  if (frames < 1) {frames=1;}
  return frames;
}

void Hyphae::updateAllHypha() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
  }
  if (elements.size() >= params.maxHyphaCount) {
    sterile = true;
  }
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(e.pos, e.dir, e.generation);
}

void Hyphae::onHyphaOutside(ofEventArgs &e) {
  if (dyingPerFrame==0) {
    sterile = true;
    dyingPerFrame = getDyingPerFrame();
  }
}

HyphaeStats Hyphae::getStats() const {
  HyphaeStats stats;
  stats.hyphaCount = elements.size();
  stats.primalHyphaCount = this->primalHyphaCount;
  return stats;
}

void Hyphae::update() {
  if (dyingPerFrame > 0) {
    removeAllHypha(dyingPerFrame);
  }
  updateAllHypha();
  generatePrimal();
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
