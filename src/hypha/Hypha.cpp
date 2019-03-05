//
//  Hypha.cpp
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"
#include "Tools.h"

Hypha::Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaParams params, const int generation) {
  this->position = pos;
  this->params = params;
  this->border = border;
  this->velocity = getInitialVelocity(dir);
  this->generation = generation;
  this->noiseOffset = Tools::getRandomVec2f();
  
  calcNextForkDistance();
}

ofVec2f Hypha::getInitialVelocity(const ofVec2f dir) const {
   return dir.getNormalized() *
          ofRandom(params.speed*(1-params.speedVariation/100.0f),
                   params.speed*(1+params.speedVariation/100.0f)) *
          border->getRatio(Tools::posToAngle(dir));
}

void Hypha::updateDirection() {
  float bendAngle = ofRandom(-params.maxBendAngle, params.maxBendAngle);
  if (abs(angle+bendAngle)<params.maxBentAngle) {
    angle += bendAngle;
  }
}

void Hypha::calcNextForkDistance() {
  float length = position.length();
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
  e.pos = this->position;
  float forkAngle = ofRandom(-params.maxForkAngle, params.maxForkAngle);
  e.dir = this->velocity.getRotated(angle+forkAngle);
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::update() {
  delta += velocity.getRotated(angle);
  float absDeltaX = abs(delta.x);
  float absDeltaY = abs(delta.y);
  if (absDeltaX>params.pixelOverlap || absDeltaY>params.pixelOverlap) {
    position += delta;
    if (absDeltaX>0) {delta.x=0;}
    if (absDeltaY>0) {delta.y=0;}
      if (!dying && border->isOutside(position)) {
        ofEventArgs e;
        ofNotifyEvent(this->outsideEvent, e);
      }
    energy--;
    posIsNewPixel = true;
    updateDirection();
    if (!dying && --nextForkDistance<=0) {
      fork();
    }
  }
}
