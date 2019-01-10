//
//  Element.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Element.hpp"

Element::Element(Ink *ink, ofVec2f pos, float size) {
  this->ink = ink;
  this->pos = pos;
  this->size = size;
  fbo.allocate(size, size);
  fbo.begin();
  ofClear(0, 0, 0, 0);
  fbo.end();
}

void Element::update() {
  cursor = cursor + ofVec2f(ofRandom(-1,1), ofRandom(-1,1));

  fbo.begin();
  ofSetColor(ink->getColor(cursor));
  ofDrawRectangle(size/2 + cursor.x, size/2 + cursor.y, 1, 1);
  fbo.end();
}

void Element::draw() {
  fbo.draw(-size/2,-size/2);
}
