//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"

Hypha::Hypha(ofVec2f pos, Ink *ink, ofVec2f vel, float distortion) {
  this->pos = pos;
  this->ink = ink;
  this->vel = vel;
  this->distortion = distortion;
  this->noiseOffset = ofVec2f(ofRandom(1000), ofRandom(1000));
}

void Hypha::updateVelocity() {
  float angle = ofNoise(pos.x*distortion+noiseOffset.x,
                        pos.y*distortion+noiseOffset.y)-0.5f;
  vel.rotate(angle);
}

void Hypha::update() {
  updateVelocity();
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
