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
}

void Element::update() {
  ofVec2f dir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                        ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + dir;
}

void Element::draw() {
  ofPushMatrix();
  ofTranslate(pos.x-getWidth()/2, pos.y-getHeight()/2);
  ofSetColor(ink->getColor(cursor));
  ofDrawRectangle(getWidth()/2 + cursor.x, getHeight()/2 + cursor.y, 1, 1);
  ofPopMatrix();
}
