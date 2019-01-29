//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "HyphaForkEventArgs.h"

#define OFFSET_MAX 1000

Hypha::Hypha(ofVec2f pos, Ink *ink, ofVec2f vel, const HyphaSettings settings, int generation) {
  this->pos = pos;
  this->ink = ink;
  this->settings = settings;
  this->vel = vel;
  this->generation = generation;
  this->forkCount = 0;
  this->lifespan = ofRandom(0,settings.maxLifespan);
  this->noiseOffset = ofVec2f(ofRandom(OFFSET_MAX), ofRandom(OFFSET_MAX));
  calcNextForkDistance();
}

void Hypha::updateVelocity() {
  float bendAngle = 2*(ofNoise(pos.x*settings.distortion+noiseOffset.x,
                        pos.y*settings.distortion+noiseOffset.y)-0.5f)*settings.maxBendAngle;
  vel.rotate(bendAngle);
}

float Hypha::getFertilityRate() {
  return settings.fertilityRateRacio*(pow(generation+forkCount,settings.fertilityRatePower)+1);
}

void Hypha::calcNextForkDistance() {
  this->nextForkDistance = (int)(ofRandom(1,(getFertilityRate()))+0.5f);
}

void Hypha::fork() {
  HyphaForkEventArgs e;
  e.generation = this->generation + 1;
  e.pos = this->pos;
  float angle = ofRandom(-settings.maxForkAngle, settings.maxForkAngle);
  e.vel = this->vel.getRotated(angle);
  ofNotifyEvent(this->forkEvent, e);

  this->lifespan /= settings.forkAgeRatio;
  this->forkCount++;

  calcNextForkDistance();
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
      this->nextForkDistance--;
      if (this->nextForkDistance==0) {
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
    color.a = settings.transparency;
    ofSetColor(color);
    ofDrawRectangle(this->lastIntPos, 1, 1);
    ofPopStyle();
    this->posIsNewPixel = false;
  }
}
