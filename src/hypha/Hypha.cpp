//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"

Hypha::Hypha(ofVec2f pos, Ink *ink, ofVec2f vel) {
  this->pos = pos;
  this->ink = ink;
  this->vel = vel;
}

void Hypha::update() {
  this->pos += vel;
  ofVec2f newIntPos = ofVec2f((int)(this->pos.x+0.5f),
                              (int)(this->pos.y+0.5f));
  if (newIntPos != this->lastIntPos) {
    this->lastIntPos = newIntPos;
    this->posIsNewPixel = true;
  }
}

void Hypha::draw() {
  if (this->posIsNewPixel) {
    ofPushStyle();
    ofEnableAlphaBlending();
    ofColor color = ink->getColor(this->pos);
    ofSetColor(color);
    ofDrawRectangle(this->lastIntPos, 1, 1);
    ofPopStyle();
    this->posIsNewPixel = false;
  }
}
