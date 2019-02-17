//
//  Border.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"

#include "ofMain.h"

Border::Border(int resolution, float distortion) {
  this->resolution = resolution;
  generateRadiuses(distortion);
}

void Border::generateRadiuses(float distortion) {
  float seed = ofRandom(0,1000);
  for (int i=0; i<resolution*360; i++) {
    radiuses.push_back(calcRadiusForAngle(i/360.0f, distortion, seed));
  }
}

float Border::calcRadiusForAngle(float angle, float distortion, float seed) const {
  ofVec2f p = ofVec2f(1,0).rotate(angle);
  return ofNoise(p.x*distortion+seed, p.y*distortion+seed);
}

float Border::getRadius(float angle) const {
  int i = (int)(angle*resolution+0.5);
  return radiuses[i];
}
