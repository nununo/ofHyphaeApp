//
//  Element.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Element.hpp"

Element::Element(Ink *ink, ofVec2f pos) {
  this->ink = ink;
  this->pos = pos;
  this->dir = ofVec2f(ofRandom(0.01f, 0.01f),0).getRotated(ofRandom(360));
}

void Element::update() {
  // Move center position
  //pos += dir;

  // Move cursor
  ofVec2f cursorDir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                        ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + cursorDir;
}

void Element::draw() {
  ofPushMatrix();
  ofPushStyle();
  ofTranslate(pos.x, pos.y);
  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 3, 3);
  ofPopStyle();
  ofPopMatrix();
}
