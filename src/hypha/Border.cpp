//
//  Border.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Border.h"
#include "ofMain.h"

Border::Border(const BorderParams params) {
  this->params = params;
  generateRadiuses();
}

void Border::generateRadiuses() {
  for (int i=0; i<360; i++) {
    BorderPoint bp;
    bp.ratio = calcRatioForAngle(i);
    points.push_back(bp);
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

bool Border::isOutside(ofVec2f pos) {
  int i = Tools::angleToInt(Tools::posToAngle(pos));
  if (points[i].touched) {
    return true;
  } else if (pos.length() > points[i].ratio*params.radius) {
    points[i].touched = true;
    if (i==0) {
      points[359].touched = true;
      points[1].touched = true;
    } else if (i==359) {
      points[358].touched = true;
      points[0].touched = true;
    } else {
      points[i+1].touched = true;
      points[i-1].touched = true;
    }
    return true;
  } else {
    return false;
  }
}

void Border::draw() {
  ofPushStyle();
  ofVec2f prevP;
  for(int i=0; i<=360; i++) {
    if (!drawn) {
      if (points[i%360].touched) {
        ofSetColor(255, 0, 0);
      } else {
        ofSetColor(0, 255, 0);
      }
    } else {
      ofSetColor(0,0,0);
    }
    ofVec2f p = ofVec2f(params.radius*points[i%360].ratio,0).rotate(i);
    if (i!=0) {ofDrawLine(prevP, p);}
    prevP = p;
  }
  ofPopStyle();
  drawn = !drawn;
}
