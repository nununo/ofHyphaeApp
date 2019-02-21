//
//  MyceliumParams.h
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#ifndef MyceliumParams_h
#define MyceliumParams_h

struct BorderParams {
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
  ofVec2f position;
  int creationAreaSize;
  int primalHyphaCount;
  float newPrimalHyphaPeriod;
  int maxHyphaCount;
  HyphaParams hypha;
};

struct MyceliumParams {
  BorderParams border;
  HyphaeParams hyphae;
};

#endif /* MyceliumParams_h */
