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
  
  params.border.distortion = Tools::randomInRange(settings.border.distortion);
  params.border.radius = Tools::randomInRange(settings.border.radius);
  params.border.ratioVariation = settings.border.ratioVariation;

  params.position = ofVec2f(ofRandom(0+ofGetWidth()/5,ofGetWidth()-ofGetWidth()/5),
                                   ofRandom(0+ofGetHours()/5,ofGetHeight()-ofGetHeight()/5));
  params.creationAreaSize = Tools::randomInRange(settings.creationAreaSize);
  params.primalHyphaCount = (int)Tools::randomInSet(settings.primalHyphaCount);
  params.newPrimalHyphaPeriod = Tools::randomInRange(settings.newPrimalHyphaPeriod);
  params.maxHyphaCount = (int)Tools::randomInSet(settings.maxHyphaCount);
  
  params.hypha.color = settings.hypha.color;
  params.hypha.speed = Tools::randomInRange(settings.hypha.speed);
  params.hypha.speedVariation = Tools::randomInRange(settings.hypha.speedVariation);
  params.hypha.maxForkAngle = Tools::randomInRange(settings.hypha.maxForkAngle);
  params.hypha.maxBendAngle = Tools::randomInRange(settings.hypha.maxBendAngle);
  params.hypha.radiusTolerance = Tools::randomInRange(settings.hypha.radiusTolerance);
  
  return params;
}
