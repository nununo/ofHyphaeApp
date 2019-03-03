//
//  HyphaeParams.h
//  hyphaeApp
//
//  Created by Nuno on 19/02/2019.
//

#ifndef HyphaeParams_h
#define HyphaeParams_h

struct BorderParams {
  float noiseOffset;
  float distortion;
  float radius;
  ofVec2f ratioVariation;
};

struct HyphaParams {
  ofColor color;
  float speed;
  float speedVariation;
  float maxForkAngle;
  float maxBendAngle;
  float maxBentAngle;
  float pixelOverlap;
  float fertilityRatio;
};

struct HyphaeParams {
  int seed;
  ofVec2f position;
  int creationAreaSize;
  int primalHyphaCount;
  int newPrimalHyphaFramesPeriod;
  int maxHyphaCount;
  int dyingPixels;
  float euthanasiaPercentage;
  BorderParams border;
  HyphaParams hypha;
};

#endif /* HyphaeParams_h */
