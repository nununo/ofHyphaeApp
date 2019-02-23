//
//  HyphaeParamsBuilderParamsBuilder.cpp
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#include "HyphaeParamsBuilder.h"
#include "Tools.h"

HyphaeParams HyphaeParamsBuilder::create() {
  HyphaeParams params;
  
  params.seed = (int)ofRandom(999999);
  ofSeedRandom(params.seed);

  params.position = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
  params.creationAreaSize = Tools::randomInRange(settings.creationAreaSize);
  params.primalHyphaCount = (int)Tools::randomInSet(settings.primalHyphaCount);
  params.newPrimalHyphaPeriod = Tools::randomInRange(settings.newPrimalHyphaPeriod);
  params.maxHyphaCount = (int)Tools::randomInSet(settings.maxHyphaCount);

  params.border.noiseOffset = ofRandom(100000);
  params.border.distortion = Tools::randomInRange(settings.border.distortion);
  params.border.radius = Tools::randomInRange(settings.border.radius);
  params.border.ratioVariation = settings.border.ratioVariation;

  params.hypha.color = settings.hypha.color;
  params.hypha.speed = Tools::randomInRange(settings.hypha.speed);
  params.hypha.speedVariation = Tools::randomInRange(settings.hypha.speedVariation);
  params.hypha.maxForkAngle = Tools::randomInRange(settings.hypha.maxForkAngle);
  params.hypha.maxBendAngle = Tools::randomInRange(settings.hypha.maxBendAngle);
  params.hypha.radiusTolerance = Tools::randomInRange(settings.hypha.radiusTolerance);
  params.hypha.pixelOverlap = Tools::randomInRange(settings.hypha.pixelOverlap);

  return params;
}
