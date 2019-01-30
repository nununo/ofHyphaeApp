//
//  DistortedCircle.cpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#include "DistortedCircle.h"

DistortedCircle::DistortedCircle(float scale) {
  this->offset = ofVec2f(ofRandom(1000), ofRandom(1000));
  this->scale = scale;
}

float DistortedCircle::get(ofVec2f p) {
  return ofNoise(p.x*scale+offset.x, p.y*scale+offset.y);
}

float DistortedCircle::getForAngle(float angle, float radius) {
  ofVec2f p = ofVec2f(radius,0).getRotated(angle);
  return get(p);
}
