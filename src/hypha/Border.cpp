//
//  Border.cpp
//  hyphaeApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"
#include "ofMain.h"
#include "Tools.h"

Border::Border(const BorderParams params, ofColor backgroundColor) {
  this->params = params;
  this->backgroundColor = backgroundColor;
  generateRadiuses();
}

void Border::generateRadiuses() {
  for (int i=0; i<360; i++) {
    radiuses.push_back(calcRatioForAngle(i));
  }
}

float Border::calcRatioForAngle(float angle) const {
  // 2 level Perlin noise in which the 1st octave is just a symetry of 180º so that it can make elongated
  // shapes. The 2nd octave is actually the 3rd octave since it is being multiplied by 4. The first octave
  // has 0.75 weight while the 2nd has a smaller weight and will just add diversity to the shape

  // Octave 1
  ofVec2f p1 = ofVec2f(1,0).getRotated(abs(angle-180)); // We want it to be symetrical
  float ratio1 = ofNoise(p1.x*params.distortion+params.noiseOffset, p1.y*params.distortion+params.noiseOffset);
  // Octave 2 (wich will be 3rd)
  ofVec2f p2 = ofVec2f(1,0).getRotated(angle);
  float ratio2 = ofNoise(4*p2.x*params.distortion+params.noiseOffset, 4*p2.y*params.distortion+params.noiseOffset);
  // Add both and conform the result to the ratio variation in the settings
  return ofLerp(params.ratioVariation.x, params.ratioVariation.y, 0.75f*ratio1 + 0.25f*ratio2);
}

float Border::getRatio(float angle) const {
  int i = Tools::angleToInt(angle);
  return radiuses[i];
}

bool Border::isOutside(ofVec2f pos) const {
  return (pos.length() > getRadius(Tools::posToAngle(pos)));
}

void Border::draw() {
  ofPushStyle();
  if(!drawn) {
    ofSetColor(255, 0, 0);
  } else {
    ofSetColor(backgroundColor);
  }
  ofVec2f prevP;
  for(int i=0; i<=360; i++) {
    ofVec2f p = ofVec2f(params.radius*radiuses[Tools::angleToInt(i)],0).rotate(i);
    if (i!=0) {ofDrawLine(prevP, p);}
    prevP = p;
  }
  ofPopStyle();
  drawn = !drawn;
}
