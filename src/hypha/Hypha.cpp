//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "HyphaForkEventArgs.h"

Hypha::Hypha(ofVec2f pos, Ink *ink, ofVec2f vel, const HyphaSettings settings) {
  this->pos = pos;
  this->ink = ink;
  this->settings = settings;
  this->vel = vel;
  this->lifespan = ofRandom(0,settings.maxLifespan);
  this->noiseOffset = ofVec2f(ofRandom(1000), ofRandom(1000));
}

void Hypha::updateVelocity() {
  float bendAngle = 2*(ofNoise(pos.x*settings.distortion+noiseOffset.x,
                        pos.y*settings.distortion+noiseOffset.y)-0.5f)*settings.maxBendAngle;
  vel.rotate(bendAngle);
}

void Hypha::fork() {
  HyphaForkEventArgs e;
  e.pos = this->pos;
  float angle = ofRandom(-settings.maxForkAngle, settings.maxForkAngle);
  e.vel = this->vel.getRotated(angle);
  ofNotifyEvent(this->forkEvent, e);
  this->lifespan /= settings.forkAgeRatio;
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
