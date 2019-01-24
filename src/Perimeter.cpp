//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.h"
#include "Utils.h"

Perimeter::Perimeter(float growthSpeed, float space) {
  this->space = space;
  this->dc = new DistortedCircle(0.0025f);
  this->rings = new Rings(space);
  this->growthSpeed = growthSpeed;
  
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
    cursors[i] += dc->get(i, cursors[i]) * this->growthSpeed;
    int ring = rings->getRing(cursors[i]);
    if (rings->fill(ring, i)) {
      ofLog() << "new event: " << ring << " " << i;
      static NewElementEvent event;
      event.pos = ofVec2f(cursors[i],0).getRotated(i);
      ofNotifyEvent(this->newElementEvent, event);
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
