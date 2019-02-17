//
//  Border.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"

#include "ofMain.h"

Border::Border(float radius, int resolution, float distortion) {
  this->radius = radius;
  this->resolution = resolution;
  generateRadiuses(distortion);
}

void Border::generateRadiuses(float distortion) {
  float seed = ofRandom(0,1000);
  for (int i=0; i<resolution*360; i++) {
    radiuses.push_back(calcRadiusForAngle(i/(float)resolution, distortion, seed));
  }
}

float Border::calcRadiusForAngle(float angle, float distortion, float seed) const {
  ofVec2f p = ofVec2f(1,0).rotate(angle);
  return 1+ofNoise(p.x*distortion+seed, p.y*distortion+seed);
}

float Border::getRatio(float angle) const {
  int i = (int)(angle*resolution+0.5);
  return radiuses[i];
}

void Border::draw() const {
  ofPushStyle();
  ofSetColor(255, 0, 0);
  for(int i=0; i<resolution*360; i++) {
    ofVec2f p = ofVec2f(radius*radiuses[i],0).rotate(i/(float)resolution);
    ofDrawRectangle(p.x, p.y, 1, 1);
  }
  ofPopStyle();
}
