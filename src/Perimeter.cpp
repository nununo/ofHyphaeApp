//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.h"
#include "Utils.h"

Perimeter::Perimeter(float growthSpeed, float elementDistance) {
  this->elementDistance = elementDistance;
  this->dc = new DistortedCircle(0.0025f);
  this->sockets = new Sockets(elementDistance);
  this->growthSpeed = growthSpeed;
  
  for(int i=0; i<360;i++) {
    cursors[i] = 0;
  }
}

Perimeter::~Perimeter() {
  delete this->dc;
  delete this->sockets;
}

void Perimeter::update() {
  for(int i=0; i<360; i++) {
    cursors[i] += dc->get(i, cursors[i]) * this->growthSpeed;
    if (sockets->getState(cursors[i], i) == Empty) {
      if (sockets->fillState(cursors[i], i) == 0) {
        static NewElementEvent event;
        event.pos = ofVec2f(cursors[i],0).getRotated(i);
        ofNotifyEvent(this->newElementEvent, event);
      }
    }
  }
}

void Perimeter::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255, 255, 0, 255);
  drawCursor();
  drawSockets();
  ofPopStyle();
}

void Perimeter::drawCursor() {
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(cursors[i],0).getRotated(i);
    ofDrawRectangle(p, 1, 1);
  }
}

void Perimeter::drawSockets() {
  for(int i=0; i<360; i++) {
    for (int j=0; j<10;j ++) {
      SocketState s = sockets->getState(j*this->elementDistance, i);
      if ( s != Invalid ) {
        ofVec2f p = ofVec2f(j*this->elementDistance,0).getRotated(i);
        if (s == Empty ) {
          ofSetColor(255, 255, 255);
        } else {
          ofSetColor(255, 255, 0);
        }
        ofDrawRectangle(p, 1, 1);
      }
    }
  }
}
