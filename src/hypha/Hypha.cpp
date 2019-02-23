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
  this->deathRadius = calcDeathRadius();
  
  this->forkCount = 0;
  this->noiseOffset = ofVec2f(ofRandom(OFFSET_MAX), ofRandom(OFFSET_MAX));
  calcNextForkDistance();
  this->delta = ofVec2f(0,0);
}

float Hypha::calcDeathRadius() const {
  float angle = Tools::posToAngle(velocity);
  return border->getRadius(angle) * ofRandom(1, 1+params.radiusTolerance/100.0f);
}

ofVec2f Hypha::getInitialVelocity(ofVec2f dir) const {
   return dir.getNormalized() *
          ofRandom(params.speed*(1-params.speedVariation/100.0f),
                   params.speed*(1+params.speedVariation/100.0f)) *
          border->getRatio(Tools::posToAngle(dir));
}

void Hypha::updateDirection() {
  float bendAngle = 2*(ofNoise(position.x+noiseOffset.x,
                        position.y+noiseOffset.y)-0.5f)*params.maxBendAngle;
  velocity.rotate(bendAngle, ofVec3f(0,0,1));
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
  float angle = ofRandom(-params.maxForkAngle, params.maxForkAngle);
  e.dir = this->velocity.getRotated(angle, ofVec3f(0,0,1));
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::update() {
  if (isAlive()) {
    delta += velocity;
    if (abs(delta.x)>params.pixelOverlap || abs(delta.y)>params.pixelOverlap) {
      position += delta;
      delta = ofVec2f(0,0);
      if (position.length() > deathRadius) {
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

