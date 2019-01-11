//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"

Family::Family(Ink *ink, ofVec2f pos, float elementSize) {
  this->ink = ink;
  this->pos = pos;
  
  for(int i=0;i<10;i++) {
    ofVec2f elementPos = ofVec2f(ofRandom(-elementSize/2, elementSize/2), ofRandom(-elementSize/2, elementSize/2));
    elements.push_back( Element(ink, elementPos, elementSize) );
  }

  float size = elementSize * 3;

  fbo.allocate(size, size);
  fbo.begin();
  ofClear(0, 0, 0, 0);
  fbo.end();
}

void Family::update() {
  fbo.begin();
  ofPushMatrix();
  ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
  //ofClear(255,255,255,50);
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
    itr->draw();
  }
  ofPopMatrix();
  fbo.end();
}

void Family::draw() {
  fbo.draw(pos.x - getWidth()/2, pos.y - getHeight()/2);
}
