//
//  ConidiumRandomDance.cpp
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#include "ConidiumRandomDance.h"

void ConidiumRandomDance::update() {
  ofVec2f cursorDir = ofVec2f(ofRandom(-1,1),
                              ofRandom(-1,1));
  cursor = (cursor + cursorDir) * 0.95f;
}

void ConidiumRandomDance::draw() {
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
}
