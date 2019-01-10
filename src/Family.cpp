//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"

Family::Family(Ink *ink, ofVec2f pos, float size) {
  this->ink = ink;
  this->pos = pos;
  this->size = size;
  
  for(int i=0;i<10;i++) {
    elements.push_back( Element(ink, ofVec2f(ofRandom(-50, 50), ofRandom(-50, 50)), size) );
  }
  
  fbo.allocate(size*10, size*10);
  fbo.begin();
  ofClear(0, 0, 0, 0);
  fbo.end();
}

void Family::update() {
  fbo.begin();
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
    ofPushMatrix();
    ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
    itr->draw();
    ofPopMatrix();
  }
  fbo.end();
}

void Family::draw() {
  fbo.draw(pos - size/2);
}
