//
//  Spot.cpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#include "Family.hpp"
#include "InkColor.hpp"

Family::Family(Ink *ink, ofVec2f pos, int size) {
  this->ink = ink;
  this->pos = pos;
  
  for(int i=0;i<1;i++) {
    ofVec2f elementPos = ofVec2f(ofRandom(-size/2, size/2), ofRandom(-size/2, size/2));
    InkColor *ic = new InkColor(ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255)), 5);
    elements.push_back( Element(ic, elementPos) );
  }

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
  fbo.begin();
  ofPushMatrix();
  ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);

  ofEnableAlphaBlending();
  ofSetColor(255,255,255,255);
  for( list<Element>::iterator itr = elements.begin(); itr != elements.end(); ++itr ) {
    itr->update();
    
    itr->draw();
  }
  ofDisableBlendMode();

  ofPopMatrix();
  fbo.end();
}

void Family::draw() {
  fbo.draw(pos.x - getWidth()/2, pos.y - getHeight()/2);
}
