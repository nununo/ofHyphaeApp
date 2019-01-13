//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.hpp"
#include "Utils.hpp"

Perimeter::Perimeter(float growthSpeed, float elementDistance) {
  this->elementDistance = elementDistance;
  this->dc = new DistortedCircle(0.01f);
  this->growthSpeed = growthSpeed;
  for(int i=0; i<360;i++) {
    cursors[i] = 0;
    lastElements[i] = 0;
  }
}

Perimeter::~Perimeter() {
  delete this->dc;
}

void Perimeter::update() {
  for(int i=0; i<360; i++) {
    cursors[i] += dc->get(i, cursors[i]) * this->growthSpeed;
    if (cursors[i] > lastElements[i] + this->elementDistance)
      lastElements[i] = cursors[i];
  }
}

float Perimeter::getElementAngleDistance(float r) {
  float circlePerimeter = 2 * PI * r;
  return 360 * this->elementDistance / circlePerimeter;
}

void Perimeter::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255, 255, 0, 255);
  for(int i=0; i<360; i++) {
    ofVec2f pc = ofVec2f(cursors[i],0).getRotated(i);
    ofDrawRectangle(pc, 1, 1);
    ofVec2f ple = ofVec2f(lastElements[i],0).getRotated(i);
    ofDrawRectangle(ple, 1, 1);
  }
  ofPopStyle();
}
