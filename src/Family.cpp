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
  
  ofAddListener(NewElementEvent::events, this, &Family::onNewElementEvent);
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
    fbo.draw(pos.x - getWidth()/2, pos.y - getHeight()/2);
  }
}

void Family::updateFBO() {
  fbo.begin();
  ofPushStyle();
  ofPushMatrix();
  ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);

  //ofClear(0,0,0);
  //perimeter->draw();

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
  InkColor *ic = new InkColor(ofColor::fromHsb(ofRandom(0,255), 255, 255), 5);
  elements.push_back( Element(ic, pos, elementLifespan) );
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

