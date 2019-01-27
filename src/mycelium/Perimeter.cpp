//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.h"

Perimeter::Perimeter(ConidiaSettings settings) {
  this->settings = settings;
  this->dc = new DistortedCircle(settings.perimeterDistortion);
  this->rings = new Rings(settings);
  
  for(int i=0; i<360;i++) {
    cursors[i] = 0;
  }
}

Perimeter::~Perimeter() {
  delete this->dc;
  delete this->rings;
}

void Perimeter::update() {
  for(int i=0; i<360; i++) {
    cursors[i] += dc->get(i, cursors[i]) * this->settings.growthSpeed;
    int ring = rings->getRing(cursors[i]);
    ofVec2f pos = rings->fill(ring, i);
    if (pos.x != 0 || pos.y != 0) {
      static EmptyHoleReachedEvent event;
      event.pos = pos;
      ofNotifyEvent(this->newConidiumEvent, event);
    }
  }
}

void Perimeter::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255, 255, 0, 255);
  //drawCursor();
  rings->draw();
  ofPopStyle();
}

void Perimeter::drawCursor() {
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(cursors[i],0).getRotated(i);
    ofDrawRectangle(p, 1, 1);
  }
}
