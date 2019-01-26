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
  this->conidia = new Conidia(danceFactory, conidiumLifespan);
  this->lifespan = lifespan;
  this->perimeter = new Perimeter(growthSpeed, conidiumDistance, perimeterDistortion);

  conidia->add(ofVec3f(0,0,0));
  addHypha();

  //ofAddListener(this->perimeter->newElementEvent, this, &Mycelium::onNewElementEvent);
}

Mycelium::~Mycelium() {
  delete this->conidia;
}

void Mycelium::onNewElementEvent(NewConidiumEvent &e) {
  conidia->add(e.pos);
}

void Mycelium::update() {
  if (isAlive()) {
    grow();
    perimeter->update();
    
    conidia->update();

    for( list<Hypha>::iterator itr = hyphae.begin(); itr != hyphae.end(); ++itr ) {
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
    for( list<Hypha>::iterator itr = hyphae.begin(); itr != hyphae.end(); ++itr ) {
      itr->draw();
    }
    conidia->draw();
    //perimeter->draw();
    
    ofPopMatrix();
    ofPopStyle();
  }
}

void Mycelium::addHypha() {
  Ink *ink = new InkColor(ofColor::black, 20); // ofColor::fromHsb(ofRandom(0,255), 255, 255)
  ofVec2f vel = ofVec2f(0.01f,.01f).rotate(ofRandom(0,360));
  hyphae.push_back( Hypha(ofVec2f(0,0), ink, vel) );
}

void Mycelium::grow() {
  if (isAlive()) {
    this->lifespan--;
  }
}
