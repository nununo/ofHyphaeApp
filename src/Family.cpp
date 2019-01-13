//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"
#include "InkColor.hpp"

Family::Family(ofVec3f pos, int size, float elementDistance) {
  this->pos = pos;
  this->elementDistance = elementDistance;
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

void Family::update() {
  grow();
  
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
  }
  fbo.begin();
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

void Family::draw() {
  fbo.draw(pos.x - getWidth()/2, pos.y - getHeight()/2);
}

void Family::addElement(ofVec3f pos) {
  InkColor *ic = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
  elements.push_back( Element(ic, pos) );
}

float Family::getElementAngleDistance() {
  float circlePerimeter = 2 * PI * this->radius;
  return 360 * this->elementDistance / circlePerimeter;
}

void Family::grow() {
  this->radius += this->growthSpeed;
  ofLog() << this->radius;
  createElements();
}

void Family::createElements() {
  if (this->radius >= this->lastElementRadius + this->elementDistance) {
    float currentAngle = 0;
    float angleIncrement = getElementAngleDistance();
    ofLog() << "creating elements " << angleIncrement;
    while (currentAngle < 360) {
      addElement(ofVec3f(this->radius, 0, 0).rotate(currentAngle, ofVec3f(0, 0, 1)));
      currentAngle += angleIncrement;
    }
    this->lastElementRadius = this->radius;
  }
}

