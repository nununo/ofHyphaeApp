//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "Tools.h"

#define OFFSET_MAX 1000

Hypha::Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaParams params, const int generation) {
  this->position = pos;
  this->params = params;
  this->border = border;
  this->velocity = getInitialVelocity(dir);
  this->generation = generation;
  
  this->angle = 0;
  this->forkCount = 0;
  this->delta = ofVec2f::zero();
  this->noiseOffset = ofVec2f(ofRandom(OFFSET_MAX), ofRandom(OFFSET_MAX));
  calcNextForkDistance();
}

ofVec2f Hypha::getInitialVelocity(const ofVec2f dir) const {
   return dir.getNormalized() *
          ofRandom(params.speed*(1-params.speedVariation/100.0f),
                   params.speed*(1+params.speedVariation/100.0f)) *
          border->getRatio(Tools::posToAngle(dir));
}

void Hypha::updateDirection() {
  float bendAngle = 2*(ofNoise(position.x+noiseOffset.x,
                        position.y+noiseOffset.y)-0.5f)*params.maxBendAngle;
  if (abs(angle+bendAngle)<params.maxBentAngle) {
    angle += bendAngle;
  }
}

void Hypha::calcNextForkDistance() {
  float length = position.length();
  this->nextForkDistance = 1+(int)(ofRandom(length,length*1.1)+0.5f);
}

void Hypha::fork() {
  throwForkEvent();
  this->forkCount++;
  calcNextForkDistance();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e;
  e.generation = this->generation + 1;
  e.pos = this->position;
  float forkAngle = ofRandom(-params.maxForkAngle, params.maxForkAngle);
  e.dir = this->velocity.getRotated(angle+forkAngle);
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::update() {
  if (isAlive()) {
    delta += velocity.getRotated(angle);
    if (abs(delta.x)>params.pixelOverlap || abs(delta.y)>params.pixelOverlap) {
      position += delta;
      delta = ofVec2f::zero();
      if (position.length() > border->getRadius(Tools::posToAngle(position)) * ofRandom(1, 1+params.radiusTolerance/100.0f)) {
        die();
      } else {
        posIsNewPixel = true;
        updateDirection();
        if (--nextForkDistance==0) {
          fork();
        }
      }
    }
  }
}

void Hypha::draw() {
  if (isAlive() && posIsNewPixel) {
    ofDrawRectangle(this->position.x, this->position.y, 1, 1);
    posIsNewPixel = false;
  }
}

