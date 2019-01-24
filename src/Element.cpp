//
//  Element.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Element.h"

Element::Element(ofVec3f pos, float speed, int lifespan, Dance *dance) {
  this->size = ofGetHeight()/2;
  this->dance = dance;
  this->pos = pos;
  this->speed = this->pos.getNormalized()*speed;
  this->lifespan = lifespan;
}

void Element::update() {
  if (isAlive()) {
    updatePosition();
    this->dance->update();
    growOlder();
  }
}

void Element::draw() {
  if (isAlive()) {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    this->dance->draw();
    //ofSetColor(255,255,255);
    //ofDrawRectangle(0, 0, 1, 1);
    ofPopMatrix();
  }
}

