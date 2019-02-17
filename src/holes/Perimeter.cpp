//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.h"

Perimeter::Perimeter(HolesSettings settings) {
  this->settings = settings;
  this->rings = new Rings(settings);

  for(auto cursor: cursors) {
    cursor = 0;
  }
}

Perimeter::~Perimeter() {
  delete rings;
}

void Perimeter::update(ofVec2f pos) {
  float angle = ofVec2f(1,0).angle(pos);
  int i = ((int)(angle+0.5f)+360)%360;
  cursors[i] = pos.length();

  int ring = rings->getRing(cursors[i]);
  ofVec2f ringPos = rings->fill(ring, i);
  if (ringPos.x != 0 || ringPos.y != 0) {
    throwEmptyHoleReachedEvent(ringPos);
  }
}

void Perimeter::throwEmptyHoleReachedEvent(ofVec2f pos) {
  EmptyHoleReachedEventArgs event;
  event.pos = pos;
  ofNotifyEvent(this->emptyHoleReachedEvent, event);
}

void Perimeter::draw() {
  //drawCursor();
  rings->draw();
}

void Perimeter::drawCursor() {
  ofPushStyle();
  ofSetColor(255, 0, 0, 255);
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(cursors[i],0).getRotated(i);
    ofDrawRectangle(p, 1, 1);
  }
  ofPopStyle();
}
