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

bool Ring::fill(float angle) {
  int angleIndex = getAngleIndex(angle);
  return holes[angleIndex].fill();
}

void Ring::draw() {
  ofPushStyle();
  ofSetColor(0, 255, 0);
  for (int angleIndex=0; angleIndex<360*ANGLE_RESOLUTION; angleIndex+=this->angleIndexIncrement) {
    if (holes[angleIndex].getState() == Filled) {
    ofDrawRectangle(holes[angleIndex].getPosition(), 1, 1);
    }
  }
  ofPopStyle();
}
