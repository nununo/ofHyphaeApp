//
//  Hyphae.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hyphae.h"

void Hyphae::update() {
  for( list<Hypha>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
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
  ofVec2f pos = ofVec2f(ofRandom(-20,20), ofRandom(-20,20));
  elements.push_back( Hypha(pos, this->ink, vel, this->hyphaDistortion) );
}
