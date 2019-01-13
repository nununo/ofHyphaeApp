//
//  Perimeter.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "Perimeter.hpp"
#include "Utils.hpp"

Perimeter::Perimeter() {
  for(int i=0; i<360;i++) {
    points[i] = 0;
  }
}

void Perimeter::set(float angle, float v) {
  int i = Utils::angleToIndex(angle);
  if (points[i] < v) {
    points[i] = v;
  }
}

float Perimeter::get(float angle) {
  return points[Utils::angleToIndex(angle)];
}

void Perimeter::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(255, 255, 0, 30);
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(points[i],0).getRotated(i);
    ofDrawRectangle(p, 1, 1);
  }
  ofPopStyle();
}
