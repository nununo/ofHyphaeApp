//
//  HyphaeParamsBuilderParamsBuilder.cpp
//  hyphaeApp
//
//  Created by Nuno on 19/02/2019.
//

#include "HyphaeParamsBuilder.h"
#include "Tools.h"

HyphaeParams HyphaeParamsBuilder::create(const Settings &settings) {
  HyphaeParams params;
  HyphaeSettings hyphaeSettings = settings.hyphae;
  params.seed = 634710; //(int)ofRandom(999999);
  ofSeedRandom(params.seed);

  params.position = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
  params.creationAreaSize = hyphaeSettings.creationAreaSize;
  params.maxHyphaCount = (int)Tools::randomInSet(hyphaeSettings.maxHyphaCount);
  params.primalHyphaCount = (int)Tools::randomInSet(hyphaeSettings.primalHyphaCount);
  params.newPrimalHyphaFramesPeriod = settings.canvas.framerate * Tools::randomInRange(hyphaeSettings.newPrimalHyphaPeriod);
  params.dyingPixels = settings.hyphae.dyingPixels;
  params.euthanasiaPercentage = settings.hyphae.euthanasiaPercentage;
  params.dyingOutsidePercentage = settings.hyphae.dyingOutsidePercentage;
  
  params.border.noiseOffset = ofRandom(99999);
  params.border.distortion = hyphaeSettings.border.distortion;
  params.border.radius = Tools::randomInRange(hyphaeSettings.border.radius);
  params.border.ratioVariation = hyphaeSettings.border.ratioVariation;

  params.hypha.color = hyphaeSettings.hypha.color;
  params.hypha.speed = hyphaeSettings.hypha.speed;
  params.hypha.speedVariation = hyphaeSettings.hypha.speedVariation;
  params.hypha.pixelOverlap = hyphaeSettings.hypha.pixelOverlap;
  params.hypha.maxForkAngle = Tools::randomInRange(hyphaeSettings.hypha.maxForkAngle);
  params.hypha.maxBendAngle = Tools::randomInRange(hyphaeSettings.hypha.maxBendAngle);
  params.hypha.maxBentAngle = Tools::randomInRange(hyphaeSettings.hypha.maxBentAngle);
  params.hypha.fertilityRatio = Tools::randomInRange(hyphaeSettings.hypha.fertilityRatio);

  return params;
}
