//
//  Conidium.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Conidium.h"

Conidium::Conidium(ofVec3f pos, float speed, const ConidiumSettings settings, ConidiumDance *dance) {
  this->size = ofGetHeight()/2;
  this->dance = dance;
  this->pos = pos;
  this->angle = ofVec2f(1,0).angle(pos);
  this->speed = this->pos.getNormalized()*speed; // TODO: Get rid of this?
  this->lifespan = settings.lifespan;
  this->sleepFrames = ofGetFrameRate() * settings.delay;
}

void Conidium::growOlder() {
  if (isStillSleeping()) {
    sleepFrames--;
  } else {
    lifespan--;
  }
}

void Conidium::update() {
  if (!isStillSleeping() && isAlive()) {
    updatePosition();
    this->dance->update();
  }
  growOlder();
}

void Conidium::draw() {
  if (!isStillSleeping() && isAlive()) {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZDeg(this->angle);
    ofPushStyle();
    this->dance->draw();
    ofPopStyle();
    //ofSetColor(255,255,255);
    //ofDrawRectangle(0, 5, 1, -10);
    //ofDrawRectangle(0, 0, 1, 1);
    ofPopMatrix();
  }
}

