//
//  HyphaeParams.h
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#ifndef HyphaeParams_h
#define HyphaeParams_h

struct BorderParams {
  int seed;
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
  float radiusTolerance;
};

struct HyphaeParams {
  int seed;
  ofVec2f position;
  int creationAreaSize;
  int primalHyphaCount;
  float newPrimalHyphaPeriod;
  int maxHyphaCount;
  BorderParams border;
  HyphaParams hypha;
};

#endif /* HyphaeParams_h */
