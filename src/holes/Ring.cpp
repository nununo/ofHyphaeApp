//
//  Ring.cpp
//  moldApp
//
//  Created by Nuno on 23/01/2019.
//

#include "Ring.h"

Ring::Ring(float space, int radius) {
  if (radius > 0) {
    numElements = getNumElements(space, radius);
    this->angleIndexIncrement = 360*ANGLE_RESOLUTION / numElements;
    ofVec2f pos = ofVec2f(radius,0);
    for (int angleIndex=0; angleIndex<360*ANGLE_RESOLUTION; angleIndex+=this->angleIndexIncrement) {
      holes[angleIndex].setPosition(pos.getRotated(angleIndex/(ANGLE_RESOLUTION*1.0f)));
    }
  } else {
    numElements = 1;
    angleIndexIncrement = 360*ANGLE_RESOLUTION;
  }
}

int Ring::getNumElements(float space, int radius) {
  float ringPerimeter = 2 * PI * radius;
  float arcDistance = ringPerimeter / space;
  return (int)(arcDistance + 0.5f);
}

ofVec2f Ring::fill(float angle) {
  int angleIndex = getAngleIndex(angle);
  bool result;
  for (int i=angleIndex; i<angleIndex+ANGLE_RESOLUTION; i++) {
    if (holes[i].fill()) {
      return holes[i].getPosition();
    }
  }
  return ofVec2f();
}

void Ring::draw() {
  ofPushStyle();
  for (int angleIndex=0; angleIndex<360*ANGLE_RESOLUTION; angleIndex+=this->angleIndexIncrement) {
    switch (holes[angleIndex].getState()) {
      case Filled:
        ofSetColor(0,255,0);
        ofDrawRectangle(holes[angleIndex].getPosition(), 2, 2);
      case Empty:
        ofSetColor(100,100,100);
        ofDrawRectangle(holes[angleIndex].getPosition(), 1, 1);
      default:
        continue;
    }
  }
  ofPopStyle();
}
