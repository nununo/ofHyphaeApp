//
//  DistortedCircle.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "DistortedCircle.hpp"

DistortedCircle::DistortedCircle() {
  this->iteration = 0;
  this->offset = ofVec2f(ofRandom(1000), ofRandom(1000));
  this->scale = 0.05f;
  for(int i=0; i<360; i++) {
    points[i] = 1.0f;
  }
}

void DistortedCircle::update() {
  for(int i=0; i<360; i++) {
    // Even though we need a 1D noise, since it's circular (and thus periodic)
    // we will use 2D Perlin noise to achieve consistency in the transition
    // from 0 to 360
    ofVec2f p = ofVec2f(iteration,0).getRotated(i);
    points[i] += ofSignedNoise(p.x*scale+offset.x, p.y*scale+offset.y);
  }
  iteration++;
}

void DistortedCircle::draw(float radius, float distance) {
  ofPushStyle();
  ofSetColor(0, 255, 255, 255);
  for(int i=0; i<360; i++) {
    ofVec2f p = ofVec2f(radius,0).getRotated(i) + getRadius(i) * distance;
    ofDrawRectangle(p, 1, 1);
  }
  ofPopStyle();
}
