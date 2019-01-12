//
//  Element.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "Element.hpp"

Element::Element(Ink *ink, ofVec2f pos, float size) {
  this->ink = ink;
  this->pos = pos;
  fbo.allocate(size, size);
  fbo.begin();
  ofClear(0,0,0,0);
  fbo.end();
}

void Element::update() {
  ofVec2f dir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                        ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + dir;

  fbo.begin();
  glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
  ofSetColor(ink->getColor(cursor));
  ofDrawRectangle(getWidth()/2 + cursor.x, getHeight()/2 + cursor.y, 1, 1);
  ofDisableAlphaBlending();
  fbo.end();
}

void Element::draw() {
  fbo.draw(pos.x-getWidth()/2, pos.y-getHeight()/2);
}
