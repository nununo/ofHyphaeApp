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
  for (int i=0; i<360; i++) {
    radiuses.push_back(calcRatioForAngle(i));
  }
}

float Border::calcRatioForAngle(float angle) const {
  ofVec2f p = ofVec2f(1,0).rotate(angle);
  return ofLerp(params.ratioVariation.x, params.ratioVariation.y,
                ofNoise(p.x*params.distortion+params.noiseOffset, p.y*params.distortion+params.noiseOffset));
}

float Border::getRatio(float angle) const {
  int i = Tools::angleToInt(angle);
  return radiuses[i];
}

void Border::draw() const {
  ofPushStyle();
  ofSetColor(255, 0, 0);
  ofVec2f prevP;
  for(int i=0; i<=360; i++) {
    ofVec2f p = ofVec2f(params.radius*radiuses[Tools::angleToInt(i)],0).rotate(i);
    if (i!=0) {ofDrawLine(prevP, p);}
    prevP = p;
  }
  ofPopStyle();
}
