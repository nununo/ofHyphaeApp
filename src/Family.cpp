//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.h"
#include "InkColor.h"

Family::Family(ofVec3f pos, int size, float growthSpeed, int lifespan, int elementLifespan, float elementDistance) {
  this->pos = pos;
  this->lifespan = lifespan;
  this->elementLifespan = elementLifespan;
  this->perimeter = new Perimeter(growthSpeed, elementDistance);
  this->ink = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);

  addElement(ofVec3f(0,0,0));

  initializeFBO(size);

  ofAddListener(this->perimeter->newElementEvent, this, &Family::onNewElementEvent);
}

Family::~Family() {
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr = elements.erase(itr);
  }
}

void Family::onNewElementEvent(NewElementEvent &e) {
  addElement(e.pos);
}

void Family::update() {
  if (isAlive()) {
    grow();
    perimeter->update();
    
    for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
      itr->update();
    }

    updateFBO();
  }
}

void Family::draw() {
  if (isAlive()) {
    fbo.draw(0,0);
  }
}

void Family::updateFBO() {
  fbo.begin();
  ofPushStyle();
  ofPushMatrix();
  ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
  
  ofEnableAlphaBlending();
  ofSetColor(255,255,255,255);
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->draw();
  }

  ofPopMatrix();
  ofPopStyle();
  fbo.end();
}

void Family::addElement(ofVec3f pos) {
  //InkColor *ic = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
  elements.push_back( Element(this->ink, pos, elementLifespan) );
}

void Family::grow() {
  if (isAlive()) {
    destroyDeadElements();
    this->lifespan--;
  }
}

void Family::destroyDeadElements() {
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    if (!itr->isAlive()) {
      itr = elements.erase(itr);
    }
  }
}

void Family::initializeFBO(float size) {
  fbo.allocate(size, size);
  fbo.begin();
  ofClear(0, 0, 0, 0);
  ofPopStyle();
  fbo.end();
}

void Family::drawFrame() {
  fbo.begin();
  ofPushStyle();
  ofSetColor(40, 40, 40, 255);
  ofNoFill();
  ofDrawRectangle(1,1,fbo.getWidth()-1,fbo.getHeight()-1);
  ofPopStyle();
  fbo.end();
}
