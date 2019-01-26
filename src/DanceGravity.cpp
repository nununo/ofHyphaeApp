//
//  DanceGravity.cpp
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#include "DanceGravity.h"

void DanceGravity::update() {
  ofVec2f cursorDir = ofVec2f(ofRandom(-9.9,0),
                              ofRandom(-4.9,4.9));
  cursor = cursorDir;
}

void DanceGravity::draw() {
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
}
