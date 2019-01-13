//
//  Element.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Element.hpp"

Element::Element(Ink *ink, ofVec3f pos, int lifespan) {
  this->size = ofGetHeight()/2;
  this->ink = ink;
  this->pos = pos;
  this->dir = ofVec3f(0,0,0); //ofVec2f(ofRandom(0.01f, 0.01f),0).getRotated(ofRandom(360));
  this->lifespan = lifespan;
}

void Element::update() {
  if (lifespan >0) {
    updatePosition();
    updateCursor();
    grow();
  }
}

void Element::draw() {
  if (isAlive()) {
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(pos.x, pos.y);
    ofSetColor(ink->getColor(cursor));
    ofFill();
    ofDrawRectangle(cursor.x, cursor.y, 3, 3);
    ofPopStyle();
    ofPopMatrix();
  }
}

void Element::updateCursor() {
  // Move cursor
  ofVec2f cursorDir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                              ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + cursorDir;
}
