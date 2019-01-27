//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

Hyphae::Hyphae(Ink *ink, const HyphaeSettings settings) {
  this->ink = ink;
  this->settings = settings;  

  for(int i=0; i<settings.initHyphaCount; i++) {
    ofVec2f vel = ofVec2f(0.01f,.01f).rotate(ofRandom(0,360));
    add(vel);
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

void Hyphae::addAtPosition(ofVec2f pos, ofVec2f vel) {
  Hypha *newHypha = new Hypha(pos, this->ink, vel, settings.hypha);
  ofAddListener(newHypha->forkEvent, this, &Hyphae::onHyphaFork);
  elements.push_back(*newHypha);
}

void Hyphae::add(ofVec2f vel) {
  float half = settings.creationAreaSize/2;
  ofVec2f pos = ofVec2f(ofRandom(-half/2,half/2),
                        ofRandom(-half/2,half/2));
  addAtPosition(pos, vel);
}

void Hyphae::onHyphaFork(HyphaForkEventArgs &e) {
  addAtPosition(e.pos, e.vel);
}
