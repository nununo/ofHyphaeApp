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
  fbo.allocate(size, size);
  fbo.begin();
  ofClear(0, 0, 0, 0);
  fbo.end();
}

void Element::update() {
  cursor = cursor + ofVec2f(ofRandom(-1,1), ofRandom(-1,1));

  fbo.begin();
  //ofClear(255,255,255,100);
  //ofSetColor(ink->getColor(cursor));
  ofSetColor(255,255,255,100);
  ofDrawRectangle(getWidth()/2 + cursor.x, getHeight()/2 + cursor.y, 1, 1);
  fbo.end();
}

void Element::draw() {
  fbo.draw(pos.x-getWidth()/2, pos.y-getHeight()/2);
}
