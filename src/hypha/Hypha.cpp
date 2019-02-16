//
//  Hypha.cpp
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#include "Hypha.h"

#define OFFSET_MAX 1000

Hypha::Hypha(const ofVec2f pos, const ofVec2f dir, float radius, const HyphaSettings settings, const int generation) {
  this->pos = pos;
  this->settings = settings;
  this->radius = radius;
  this->vel = getInitialVelocity(dir);
  this->generation = generation;
  this->nextDeathRadius = calcDeathRadius();
  
  this->forkCount = 0;
  float angle = getAngle(this->pos, this->vel);
  this->lifespan = ofRandom(1,getMaxLifespan(angle));
  this->color = calcColor(angle);
  this->noiseOffset = ofVec2f(ofRandom(OFFSET_MAX), ofRandom(OFFSET_MAX));
  calcNextForkDistance();
}

ofColor Hypha::calcColor(float angle) const {
  ofColor c = settings.color;
  //c.a = c.a * glm::pow(ofLerp(5.0f, 0.1f, angle/90.0f),2);
  return c;
}

float Hypha::calcDeathRadius() {
  return ofRandom(radius-radius*settings.radiusTolerance/100.0f, radius);
}

void Hypha::growOlder() {
  lifespan--;
  if (lifespan<=0 || pos.length() > nextDeathRadius) {
    dead = true;
    nextDeathRadius = calcDeathRadius();
    throwDieEvent();
  }
}

ofVec3f Hypha::getInitialVelocity(ofVec2f dir) const {
   return dir.getNormalized() * ofRandom(settings.speed*(1-settings.speedVariation/100),
                                         settings.speed*(1+settings.speedVariation/100));
}

void Hypha::updateVelocity() {
  float bendAngle = 2*(ofNoise(pos.x*settings.distortion+noiseOffset.x,
                        pos.y*settings.distortion+noiseOffset.y)-0.5f)*settings.maxBendAngle;
  vel.rotate(bendAngle, ofVec3f(0,0,1));
}

float Hypha::getFertilityRate() const {
  return settings.fertilityRateRatio*(pow(generation/2.0f+forkCount,settings.fertilityRatePower)+1);
}

void Hypha::calcNextForkDistance() {
  this->nextForkDistance = (int)(ofRandom(1,(getFertilityRate()))+0.5f);
}

void Hypha::fork() {
  throwForkEvent();

  this->lifespan /= settings.forkAgeRatio;
  this->forkCount++;

  calcNextForkDistance();
}

void Hypha::throwForkEvent() {
  HyphaForkEventArgs e;
  e.generation = this->generation + 1;
  e.pos = this->pos;
  float angle = ofRandom(-settings.maxForkAngle, settings.maxForkAngle);
  e.dir = this->vel.getRotated(angle, ofVec3f(0,0,1));
  ofNotifyEvent(this->forkEvent, e);
}

void Hypha::throwDieEvent() {
  HyphaDieEventArgs e;
  e.pos = this->pos;
  ofNotifyEvent(this->dieEvent, e);
}

void Hypha::update() {
  if (isAlive()) {
    pos += vel;
    ofVec2f newIntPos = ofVec3f((int)(pos.x+0.5f),
                                (int)(pos.y+0.5f));
    if (newIntPos != lastIntPos) {
      growOlder();
      updateVelocity();
      lastIntPos = newIntPos;
      posIsNewPixel = true;
      nextForkDistance--;
      if (nextForkDistance==0) {
        fork();
      }
    }
  }
}

void Hypha::draw() {
  if (isAlive()) {
    if (posIsNewPixel) {
      ofPushStyle();
      glEnable(GL_BLEND);
      glBlendFunc(GL_ONE, GL_ONE);
      ofSetColor(color);
      ofDrawRectangle(this->pos.x, this->pos.y, 1, 1);
      glDisable(GL_BLEND);
      ofPopStyle();
      posIsNewPixel = false;
    }
  } else {
    //ofPushStyle();
    //ofSetColor(0, 0, 255);
    //ofDrawRectangle(this->pos.x, this->pos.y, 1, 1);
    //ofPopStyle();
  }
}

