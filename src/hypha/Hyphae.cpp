//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"
#include "InkColor.h"

Hyphae::Hyphae(const HyphaeParams params, Border *border) {
  this->params = params;
  this->border = border;
  this->newPrimalHyphaFramesPeriod = ofGetFrameRate() * params.newPrimalHyphaPeriod;
  this->primalHyphaCount = 0;
  this->sterile = false;
}

void Hyphae::add(Hypha *hypha) {
  ofAddListener(hypha->forkEvent, this, &Hyphae::onHyphaFork);
  ofAddListener(hypha->positionEvent, this, &Hyphae::onHyphaPosition);
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

void Hyphae::removeAllDeadHypha() {
  for(auto itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      ofRemoveListener(itr->positionEvent, this, &Hyphae::onHyphaPosition);
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

void Hyphae::onHyphaPosition(PositionEventArgs &e) {
  ofNotifyEvent(this->hyphaPositionEvent, e);
}

void Hyphae::update() {
  sterilizeIfFull();
  removeAllDeadHypha();
  generatePrimalHyphas();
}

void Hyphae::draw() {
  ofPushStyle();
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE);
  ofSetColor(params.hypha.color);
  for(auto &itr: elements) {
    itr.draw();
  }
  glDisable(GL_BLEND);
  ofPopStyle();
}
