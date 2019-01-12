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
}

void Element::update() {
  ofVec2f dir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                        ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + dir;
}

void Element::draw() {

  ofPushMatrix();
  ofPushStyle();
  ofTranslate(pos.x, pos.y);

// Square to help locate the element
  ofSetColor(40, 40, 40, 255);
  ofNoFill();
  ofDrawRectangle(-100,-100,200,200);

  ofSetColor(ink->getColor(cursor));
  ofFill();
  ofDrawRectangle(cursor.x, cursor.y, 1, 1);
  ofPopStyle();
  ofPopMatrix();
}
