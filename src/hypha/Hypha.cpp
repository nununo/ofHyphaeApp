//
//  Hypha.cpp
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "Tools.h"

Hypha::Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaParams params, const int generation) {
  this->pos = pos;
  this->params = params;
  this->border = border;
  this->dir = dir.getNormalized();
  this->generation = generation;
  this->noiseOffset = Tools::getRandomVec2f();
  
  baseSpeed = ofRandom(params.speed*(1-params.speedVariation/100.0f),
                       params.speed*(1+params.speedVariation/100.0f));

  this->velocity = calcVelocity();

  calcNextForkDistance();
}

ofVec2f Hypha::calcVelocity() const {
  ofVec2f newDirection = dir.getRotated(angle);
  float speed = baseSpeed * border->getRatio(Tools::posToAngle(newDirection));
  return newDirection * speed;
}

void Hypha::updateDirectionAndVelocity() {
  float bendAngle = ofRandom(-params.maxBendAngle, params.maxBendAngle);
  if (abs(angle+bendAngle)<params.maxBentAngle) {
    angle += bendAngle;
  }
  if (++velocityAge>10) {
    velocity = calcVelocity();
    velocityAge = 0;
  }
}

void Hypha::calcNextForkDistance() {
  float length = pos.length();
  this->nextForkDistance = 1+(int)(params.fertilityRatio*ofRandom(length*0.1f,length*1.0f)+0.5f);
}

void Hypha::fork() {
  throwForkEvent();
  this->forkCount++;
  calcNextForkDistance();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e;
  e.generation = this->generation + 1;
  e.pos = pos;
  float forkAngle = ofRandom(-params.maxForkAngle, params.maxForkAngle);
  e.dir = dir.getRotated(angle+forkAngle);
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::checkBorder() {
  if (++checkBorderAge > 10) {
    if (!dying && border->isOutside(pos)) {
      ofEventArgs e;
      ofNotifyEvent(this->outsideEvent, e);
    }
    checkBorderAge = 0;
  }
}

void Hypha::checkFork() {
  if (!dying && --nextForkDistance<=0) {
    fork();
  }
}

void Hypha::update() {
  delta += velocity;
  float absDeltaX = abs(delta.x);
  float absDeltaY = abs(delta.y);
  if (absDeltaX>params.pixelOverlap || absDeltaY>params.pixelOverlap) {
    energy--;
    posIsNewPixel = true;
    pos += delta;
    updateDirectionAndVelocity();

    if (absDeltaX>0) {delta.x=0;}
    if (absDeltaY>0) {delta.y=0;}

    checkBorder();
    checkFork();
  }
}
