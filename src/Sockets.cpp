//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Sockets.h"
#include "ofMain.h"

Sockets::Sockets(float distance) {
  this->distance = distance;
  initialize();
}

void Sockets::initialize() {
  for (int ring=0;ring<MAX_RINGS;ring++) {
    float angularDistance = getAngularDistance(ring);
    for (int angle=0;angle<ANGLE_STEPS;angle++) {
      if (ring != 0 && (angle == 0 || angle % getAngularDistance(ring) == 0)) {
        states[ring][angle] = Empty;
      } else {
        states[ring][angle] = Invalid;
      }
    }
  }
}

int Sockets::getAngularDistance(int ring) {
  float circlePerimeter = 2 * PI * this->distance * ring;
  return (int)(ANGLE_STEPS * this->distance / circlePerimeter + 0.5f);
}

SocketState Sockets::isFilled(int ring, float angle) {
  if (ring<MAX_RINGS) {
    return states[ring][getAngleIndex(angle)];
  } else {
    return Invalid;
  }
}

bool Sockets::fill(int ring, float angle) {
  int angleIndex = getAngleIndex(angle);
  if (states[ring][angleIndex] == Empty) {
    states[ring][angleIndex] = Filled;
    return true;
  } else {
    return false;
  }
}

void Sockets::draw() {
  ofPushStyle();
  ofSetColor(0, 255, 0);
  for(int ring=1; ring<MAX_RINGS; ring++) {
    ofVec2f pos = ofVec2f(ring*this->distance,0);
    for (int angleIndex=0;angleIndex<ANGLE_STEPS;angleIndex++) {
      if (states[ring][angleIndex] != Invalid) {
        ofDrawRectangle(pos.getRotated(angleIndex/100), 1, 1);
      }
    }
  }
  ofPopStyle();
}
