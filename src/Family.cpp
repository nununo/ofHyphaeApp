//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"
#include "InkColor.hpp"

Family::Family(ofVec2f pos, int size) {
  this->pos = pos;
  
  for(int i=0;i<10000;i++) {
    ofVec2f elementPos = ofVec2f(ofRandom(-size/2, size/2), ofRandom(-size/2, size/2));
    InkColor *ic = new InkColor(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)), 255);
    vboElements.push_back(VboElement(ic, elementPos));
  }
}

void Family::update() {
  for(list<VboElement>::iterator itr = vboElements.begin(); itr != vboElements.end(); ++itr ) {
    itr->update();
  }
}

void Family::draw() {
  for(list<VboElement>::iterator itr = vboElements.begin(); itr != vboElements.end(); ++itr ) {
    itr->draw();
  }
}
