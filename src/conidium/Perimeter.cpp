//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.h"

Perimeter::Perimeter(ConidiaSettings settings, DistortedCircle *dc) {
  this->settings = settings;
  this->rings = new Rings(settings);
  this->dc = dc;
  
  for(int i=0; i<360;i++) {
    cursors[i] = 0;
  }
}

Perimeter::~Perimeter() {
  delete this->rings;
}

void Perimeter::update() {
  for(int i=0; i<360; i++) {
    cursors[i] += dc->getForAngle(i, cursors[i]) * this->settings.growthSpeed;
    int ring = rings->getRing(cursors[i]);
    ofVec2f pos = rings->fill(ring, i);
    if (pos.x != 0 || pos.y != 0) {
      static EmptyHoleReachedEventArgs event;
      event.pos = pos;
      ofNotifyEvent(this->emptyHoleReachedEvent, event);
    }
  }
}

void Perimeter::draw() {
  drawCursor();
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
