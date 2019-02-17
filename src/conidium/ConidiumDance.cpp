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
  ofPushStyle();
  glEnable(GL_BLEND);
  glBlendFunc(GL_ONE, GL_ONE);
  ofSetColor(ink->getColor(cursor));
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
  glDisable(GL_BLEND);
  ofPopStyle();
}
