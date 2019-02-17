//
//  Border.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"
#include "ofMain.h"
#include "Tools.h"

Border::Border(BorderSettings settings) {
  this->settings = settings;
  this->radius = ofRandom(settings.radiusRange.x, settings.radiusRange.y);
  generateRadiuses();
}

void Border::generateRadiuses() {
  float seed = ofRandom(0,1000);
  for (int i=0; i<settings.resolution*360; i++) {
    radiuses.push_back(calcRadiusForAngle(i/(float)settings.resolution, seed));
  }
}

float Border::calcRadiusForAngle(float angle, float seed) const {
  ofVec2f p = ofVec2f(1,0).rotate(angle);
  return 1+ofNoise(p.x*settings.distortion+seed, p.y*settings.distortion+seed);
}

float Border::getRatio(float angle) const {
  int i = Tools::angleToInt(angle, settings.resolution);
  return radiuses[i];
}

void Border::draw() const {
  ofPushStyle();
  ofSetColor(255, 0, 0);
  for(int i=0; i<settings.resolution*360; i++) {
    ofVec2f p = ofVec2f(radius*radiuses[i],0).rotate(i/(float)settings.resolution);
    ofDrawRectangle(p.x, p.y, 1, 1);
  }
  ofPopStyle();
}
