//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "HyphaForkEventArgs.h"

Hypha::Hypha(ofVec2f pos, Ink *ink, ofVec2f vel, int lifespan, float distortion) {
  this->pos = pos;
  this->ink = ink;
  this->vel = vel;
  this->lifespan = lifespan;
  this->distortion = distortion;
  this->noiseOffset = ofVec2f(ofRandom(1000), ofRandom(1000));
}

void Hypha::updateVelocity() {
  float angle = ofNoise(pos.x*distortion+noiseOffset.x,
                        pos.y*distortion+noiseOffset.y)-0.5f;
  vel.rotate(angle);
}

void Hypha::fork() {
  HyphaForkEventArgs e;
  e.pos = this->pos;
  e.vel = this->vel.getRotated(90);
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::update() {
  if (isAlive()) {
    lifespan--;
    updateVelocity();
    this->pos += vel;
    ofVec2f newIntPos = ofVec2f((int)(this->pos.x+0.5f),
                                (int)(this->pos.y+0.5f));
    if (newIntPos != this->lastIntPos) {
      this->lastIntPos = newIntPos;
      this->posIsNewPixel = true;
      if ((int)(ofRandom(0,100)+0.5f)==1) {
        fork();
      }
    }
  }
}

void Hypha::draw() {
  if (isAlive() && this->posIsNewPixel) {
    ofPushStyle();
    ofEnableAlphaBlending();
    ofColor color = ink->getColor(this->pos);
    ofSetColor(color);
    ofDrawRectangle(this->lastIntPos, 1, 1);
    ofPopStyle();
    this->posIsNewPixel = false;
  }
}
