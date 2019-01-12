//
//  VboElement.cpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#include "VboElement.hpp"

VboElement::VboElement(Ink *ink, ofVec2f pos) {
  this->ink = ink;
  this->pos = pos;
  mesh.setMode(OF_PRIMITIVE_POINTS);
}

void VboElement::update() {
  ofVec2f dir = ofVec2f(ofRandom(-(getWidth()+cursor.x)/getWidth(),(getWidth()-cursor.x)/getWidth()),
                        ofRandom(-(getHeight()+cursor.y)/getHeight(),(getHeight()-cursor.y)/getHeight()));
  cursor = cursor + dir;
  
  addPoint(cursor);
}

void VboElement::draw() {

  ofPushMatrix();
  ofTranslate(pos.x, pos.y);

  /*
// Square to help locate the element
  ofPushStyle();
  ofSetColor(40, 40, 40, 255);
  ofNoFill();
  ofDrawRectangle(-100,-100,200,200);
  ofPopStyle();
*/
  
  ofEnableAlphaBlending();
  ofEnableDepthTest();
  mesh.draw();
  ofDisableDepthTest();
  ofDisableAlphaBlending();

  ofPopMatrix();
}

void VboElement::addPoint(ofVec2f pos) {
  mesh.addColor(ink->getColor(pos));
  mesh.addVertex(ofVec3f(pos.x, pos.y, 0));
}
