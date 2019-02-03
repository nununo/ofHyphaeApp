//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

Hyphae::Hyphae(Ink *ink, const HyphaeSettings settings, DistortedCircle *dc) {
  this->ink = ink;
  this->dc = dc;
  this->settings = settings;
}

void Hyphae::update() {
  generateZeroHypha();
  removeAllDeadHypha();
  removeOlderHyphaIfOverpopulated();
  updateAllHypha();
}

void Hyphae::generateZeroHypha() {
  if (zeroHyphaCount<settings.initHyphaCount && ofGetFrameNum()%settings.newHyphaPeriod == 0) {
    float inclination = 60 * zeroHyphaCount/(float)settings.initHyphaCount;
    addGeneration0(inclination);
    zeroHyphaCount++;
    ofLog() << "new Hypha: " << zeroHyphaCount << " inclination: "  << inclination;
  }
}

void Hyphae::removeAllDeadHypha() {
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
}

void Hyphae::updateAllHypha() {
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
  }
}

void Hyphae::removeOlderHyphaIfOverpopulated() {
  int tooMany = elements.size() - settings.maxHyphaCount;
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (tooMany-- > 0) {
      itr->die();
    }
  }
}

void Hyphae::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,255);
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->draw();
  }
  ofPopStyle();
}

ofVec3f Hyphae::calcVelocity(float speed, float angle, float inclination) {
  ofVec3f vel = ofVec3f(speed,0,0).rotate(0,0,angle);
  ofVec3f vel0 = vel.getNormalized().rotate(0,0,-90);
  return vel.getRotated(inclination, vel0);
}

void Hyphae::add(Hypha *hypha) {
  ofAddListener(hypha->forkEvent, this, &Hyphae::onHyphaFork);
  elements.push_back(*hypha);
}

void Hyphae::addGeneration0(float inclination) {
  ofVec3f vel = calcVelocity(settings.hypha.speed, ofRandom(0,360), inclination);
  ofVec2f pos = ofVec2f(settings.creationAreaSize*ofRandom(0,1)).getRotated(ofRandom(0,360));
  add(new Hypha(pos, this->ink, this->dc, vel, settings.hypha));
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  add(new Hypha(e.pos, this->ink, this->dc, e.vel, settings.hypha, e.generation));
}
