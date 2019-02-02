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

  for(int i=0; i<settings.initHyphaCount; i++) {
    ofVec2f vel = ofVec2f(0.01f,.01f).rotate(ofRandom(0,360));
    addGeneration0(vel);
  }
}

void Hyphae::update() {
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      ofRemoveListener(itr->forkEvent, this, &Hyphae::onHyphaFork);
      itr = elements.erase(itr);
    } else {
      itr->update();
    }
  }
  int tooMany = elements.size() - settings.maxHyphaCount;
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (tooMany-- > 0) {
      itr->die();
    }
  }
  ofLog() << "hypha count" << elements.size();
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

void Hyphae::addAtPosition(ofVec2f pos, ofVec2f vel, int generation) {
  Hypha *newHypha = new Hypha(pos, this->ink, this->dc, vel, settings.hypha, generation);
  ofAddListener(newHypha->forkEvent, this, &Hyphae::onHyphaFork);
  elements.push_back(*newHypha);
}

void Hyphae::addGeneration0(ofVec2f vel) {
  float half = settings.creationAreaSize/2;
  ofVec2f pos = ofVec2f(ofRandom(-half,half),
                        ofRandom(-half,half));
  addAtPosition(pos, vel, 0);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  addAtPosition(e.pos, e.vel, e.generation);
}
