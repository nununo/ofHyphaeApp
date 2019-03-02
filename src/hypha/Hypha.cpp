//
//  Hypha.cpp
//  moldApp
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
  this->energy = 999999;
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
  float bendAngle = 2*(ofNoise(position.x+noiseOffset.x,
                        position.y+noiseOffset.y)-0.5f)*params.maxBendAngle;
  if (abs(angle+bendAngle)<params.maxBentAngle) {
    angle += bendAngle;
  }
}

void Hypha::calcNextForkDistance() {
  float length = position.length();
  this->nextForkDistance = 1+(int)(ofRandom(length*0.1f,length*1.0f)+0.5f);
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

bool Hypha::isOutsideBorder() {
  return (position.length() > border->getRadius(Tools::posToAngle(position)));
}

void Hypha::update() {
  if (isAlive()) {
    delta += velocity.getRotated(angle);
    if (abs(delta.x)>params.pixelOverlap || abs(delta.y)>params.pixelOverlap) {
      position += delta;
      delta = ofVec2f::zero();
      if (!dying && isOutsideBorder()) {
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
}

void Hypha::draw() {
  if (!started) {
    ofPushStyle();
    ofSetColor(params.color, 255);
    ofDrawRectangle(this->position.x, this->position.y, 1, 1);
    ofPopStyle();
    started = true;
  }
  if (posIsNewPixel) {
    ofDrawRectangle(this->position.x, this->position.y, 1, 1);
    posIsNewPixel = false;
  }
}
