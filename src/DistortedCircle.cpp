//
//  DistortedCircle.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "DistortedCircle.hpp"

DistortedCircle::DistortedCircle() {
  for(int i=0; i<360; i++) {
    points[i] = 1.0f;
  }
}

void DistortedCircle::update() {
  for(int i=0; i<360; i++) {
    // Even though we need a 1D noise, since it's circular (and thus periodic)
    // we will use 2D Perlin noise to achieve consistency in the transition
    // from 0 to 360
    points[i] += ofSignedNoise(ofVec2f(1,0).getRotated(i)/3) / 10;
  }
}

void DistortedCircle::draw(float radius) {
  ofLog() << "DistortedCircle::draw" << radius;
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(1,0).getRotated(i) * getRadius(i) * radius;
    ofPushStyle();
    ofSetColor(255, 255, 255, 255);
    ofDrawRectangle(p, 1, 1);
    ofPopStyle();
  }
}
