//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"
#include "InkColor.hpp"

Family::Family(ofVec3f pos, int size, int lifespan, int elementLifespan, float elementDistance) {
  this->pos = pos;
  this->lifespan = lifespan;
  this->elementDistance = elementDistance;
  this->elementLifespan = elementLifespan;
  radius = 0;
  growthSpeed = 0.5;
  lastElementRadius = 0;

  addElement(ofVec3f(0,0,0));
  
  fbo.allocate(size, size);
  ofPushStyle();
  fbo.begin();
  ofClear(0, 0, 0, 0);

  ofSetColor(40, 40, 40, 255);
  ofNoFill();
  ofDrawRectangle(1,1,size-1,size-1);
  
  ofPopStyle();
  fbo.end();
}

Family::~Family() {
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Family::update() {
  if (isAlive()) {
    grow();
    
    for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
      itr->update();
    }
    fbo.begin();
    ofClear(0,0,0); // TEMP!!!
    ofPushMatrix();
    ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);

    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);
    for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
      itr->draw();
    }
    ofDisableBlendMode();

    ofPopMatrix();
    fbo.end();
  }
}

void Family::draw() {
  if (isAlive()) {
    fbo.draw(pos.x - getWidth()/2, pos.y - getHeight()/2);
  }
}

void Family::addElement(ofVec3f pos) {
  InkColor *ic = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
  elements.push_back( Element(ic, pos, elementLifespan) );
}

float Family::getElementAngleDistance() {
  float circlePerimeter = 2 * PI * this->radius;
  return 360 * this->elementDistance / circlePerimeter;
}

ofVec3f Family::calcCorrectedPosition(ofVec3f p, float maxCorrection) {
  float noise = ofSignedNoise(p + 0.123f);
  ofVec3f newP = p + noise * maxCorrection;
  newP.z = p.z; // Do not affect Z
  return newP;
}

void Family::grow() {
  if (isAlive()) {
    this->radius += this->growthSpeed;
    //createElements();
    destroyDeadElements();
    this->lifespan--;
  }
}

void Family::createElements() {
  if (this->radius >= this->lastElementRadius + this->elementDistance) {
    float currentAngle = 0;
    float angleIncrement = getElementAngleDistance();
    while (currentAngle < 360) {
      ofVec3f p = ofVec3f(this->radius, 0, 0).rotate(currentAngle, ofVec3f(0, 0, 1));
      addElement(calcCorrectedPosition(p, this->elementDistance));
      currentAngle += angleIncrement;
    }
    this->lastElementRadius = this->radius;
  }
}

void Family::destroyDeadElements() {
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      itr = elements.erase(itr);
    }
  }
}

