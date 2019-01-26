//
//  ConidiumGravityDance.cpp
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#include "ConidiumGravityDance.h"

void ConidiumGravityDance::update() {
  ofVec2f cursorDir = ofVec2f(ofRandom(-9.9,0),
                              ofRandom(-4.9,4.9));
  cursor = cursorDir;
}

void ConidiumGravityDance::draw() {
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
}
