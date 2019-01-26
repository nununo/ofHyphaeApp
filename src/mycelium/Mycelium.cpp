//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Mycelium.h"
#include "InkColor.h"

Mycelium::Mycelium(ofVec3f pos, int size, float growthSpeed, int lifespan,
               int conidiumLifespan, float conidiumDistance,
               float perimeterDistortion,
               IDanceFactory *danceFactory) {
  this->pos = pos;
  this->lifespan = lifespan;
  this->conidiumLifespan = conidiumLifespan;
  this->perimeter = new Perimeter(growthSpeed, conidiumDistance, perimeterDistortion);
  this->danceFactory = danceFactory;

  addConidium(ofVec3f(0,0,0));

  ofAddListener(this->perimeter->newElementEvent, this, &Mycelium::onNewElementEvent);
}

Mycelium::~Mycelium() {
  for( list<Conidium>::iterator itr = conidia.begin(); itr != conidia.end(); ++itr ) {
    itr = conidia.erase(itr);
  }
}

void Mycelium::onNewElementEvent(NewConidiumEvent &e) {
  addConidium(e.pos);
}

void Mycelium::update() {
  if (isAlive()) {
    grow();
    perimeter->update();
    
    for( list<Conidium>::iterator itr = conidia.begin(); itr != conidia.end(); ++itr ) {
      itr->update();
    }
  }
}

void Mycelium::draw() {
  if (isAlive()) {
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(this->pos);
    
    ofEnableAlphaBlending();
    ofSetColor(255,255,255,255);
    for( list<Conidium>::iterator itr = conidia.begin(); itr != conidia.end(); ++itr ) {
      itr->draw();
    }
    //perimeter->draw();
    
    ofPopMatrix();
    ofPopStyle();
  }
}

void Mycelium::addConidium(ofVec3f p) {
  Dance *dance = this->danceFactory->getInstance(p);
  conidia.push_back( Conidium(p, 0.00f, conidiumLifespan, dance) );
}

void Mycelium::grow() {
  if (isAlive()) {
    destroyDeadElements();
    this->lifespan--;
  }
}

void Mycelium::destroyDeadElements() {
  for( list<Conidium>::iterator itr = conidia.begin(); itr != conidia.end(); ++itr ) {
    if (!itr->isAlive()) {
      itr = conidia.erase(itr);
    }
  }
}
