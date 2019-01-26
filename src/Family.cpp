//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.h"
#include "InkColor.h"

Family::Family(ofVec3f pos, int size, float growthSpeed, int lifespan,
               int elementLifespan, float elementDistance,
               float perimeterDistortion,
               IDanceFactory *danceFactory) {
  this->pos = pos;
  this->lifespan = lifespan;
  this->elementLifespan = elementLifespan;
  this->perimeter = new Perimeter(growthSpeed, elementDistance, perimeterDistortion);
  this->danceFactory = danceFactory;

  addElement(ofVec3f(0,0,0));

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
  }
}

void Family::draw() {
  if (isAlive()) {
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(this->pos);
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);
    for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
      itr->draw();
    }
    //perimeter->draw();
    
    ofPopMatrix();
    ofPopStyle();
  }
}

void Family::addElement(ofVec3f p) {
  Dance *dance = this->danceFactory->getInstance(p);
  elements.push_back( Element(p, 0.00f, elementLifespan, dance) );
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
