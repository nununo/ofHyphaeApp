//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

Hyphae::Hyphae(Ink *ink, int hyphaMaxLifespan, float hyphaDistortion) {
  this->ink = ink;
  this->hyphaMaxLifespan = hyphaMaxLifespan;
  this->hyphaDistortion = hyphaDistortion;
  
}

void Hyphae::update() {
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
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

void Hyphae::add(ofVec2f vel) {
  ofVec2f pos = ofVec2f(ofRandom(-CREATION_AREA_SIZE/2,CREATION_AREA_SIZE/2), ofRandom(-CREATION_AREA_SIZE/2,CREATION_AREA_SIZE/2));
  int lifespan = ofRandom(0,this->hyphaMaxLifespan);
  elements.push_back( Hypha(pos, this->ink, vel, lifespan, this->hyphaDistortion) );
}
