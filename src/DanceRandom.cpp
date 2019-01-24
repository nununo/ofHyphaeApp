//
//  DanceRandom.cpp
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#include "DanceRandom.h"

DanceRandom::DanceRandom(ofVec2f pos, Ink *ink) : Dance(pos) {
  this->ink = ink;
  this->cursor = ofVec3f(0,0,0);
}

void DanceRandom::update() {
  ofVec2f cursorDir = ofVec2f(ofRandom(-1,1),
                              ofRandom(-1,1));
  cursor = cursor + cursorDir;
}

void DanceRandom::draw() {
  ofPushStyle();
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
  ofPopStyle();
}
