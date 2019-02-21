//
//  Border.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"
#include "ofMain.h"
#include "Tools.h"

Border::Border(const BorderParams params) {
  this->params = params;
  generateRadiuses();
}

void Border::generateRadiuses() {
  float seed = ofRandom(0,1000);
  for (int i=0; i<BORDER_ANGLE_RESOLUTION*360; i++) {
    radiuses.push_back(calcRadiusForAngle(i/(float)BORDER_ANGLE_RESOLUTION, seed));
  }
}

float Border::calcRadiusForAngle(float angle, float seed) const {
  ofVec2f p = ofVec2f(1,0).rotate(angle);
  return ofLerp(params.ratioVariation.x, params.ratioVariation.y, ofNoise(p.x*params.distortion+seed, p.y*params.distortion+seed));
}

float Border::getRatio(float angle) const {
  int i = Tools::angleToInt(angle, BORDER_ANGLE_RESOLUTION);
  return radiuses[i];
}

void Border::draw() const {
  ofPushStyle();
  ofSetColor(255, 0, 0);
  for(int i=0; i<BORDER_ANGLE_RESOLUTION*360; i++) {
    ofVec2f p = ofVec2f(params.radius*radiuses[i],0).rotate(i/(float)BORDER_ANGLE_RESOLUTION);
    ofDrawRectangle(p.x, p.y, 1, 1);
  }
  ofPopStyle();
}
