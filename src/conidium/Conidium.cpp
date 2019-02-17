//
//  Conidium.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Conidium.h"

Conidium::Conidium(ofVec3f pos, float speed, const ConidiumSettings settings, Ink *ink) {
  this->dance = new ConidiumDance(ink, settings.recenterRatio);
  this->pos = pos;
  this->angle = ofVec2f(1,0).angle(pos);
  this->speed = this->pos.getNormalized()*speed; // TODO: Get rid of this?
  this->lifespan = settings.lifespan;
  this->sleepFrames = ofGetFrameRate() * settings.delay;
}

Conidium::~Conidium() {
  delete dance;
}

void Conidium::growOlder() {
  if (isStillSleeping()) {
    sleepFrames--;
  } else {
    lifespan--;
  }
}

void Conidium::update() {
  growOlder();
  if (!isStillSleeping() && isAlive()) {
    updatePosition();
    this->dance->update();
  }
}

void Conidium::draw() {
  if (!isStillSleeping() && isAlive()) {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZDeg(this->angle);
    this->dance->draw();
    ofPopMatrix();
  }
}

