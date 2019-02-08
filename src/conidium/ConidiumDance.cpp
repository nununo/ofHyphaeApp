//
//  ConidiumDance.cpp
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#include "ConidiumDance.h"

ConidiumDance::ConidiumDance(Ink *ink, float recenterRatio) {
  this->ink = ink;
  this->recenterRatio = recenterRatio;
}

void ConidiumDance::update() {
  ofVec2f cursorDir = ofVec2f(ofRandom(-1,1),
                              ofRandom(-1,1));
  cursor = (cursor + cursorDir) * recenterRatio;
}

void ConidiumDance::draw() {
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
}
