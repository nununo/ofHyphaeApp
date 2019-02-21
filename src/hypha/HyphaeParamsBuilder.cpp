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
  
  params.border.distortion = settings.border.distortion;
  params.border.radius = Tools::randomInRange(settings.border.radiusRange);
  params.border.ratioVariation = settings.border.ratioRange;

  params.position = ofVec2f(ofRandom(0+ofGetWidth()/5,ofGetWidth()-ofGetWidth()/5),
                                   ofRandom(0+ofGetHours()/5,ofGetHeight()-ofGetHeight()/5));
  params.creationAreaSize = Tools::randomInRange(settings.creationAreaSize);
  params.primalHyphaCount = (int)(Tools::randomInRange(settings.primalHyphaCount)+0.5f);
  params.newPrimalHyphaPeriod = Tools::randomInRange(settings.newPrimalHyphaPeriod);
  params.maxHyphaCount = (int)(Tools::randomInRange(settings.maxHyphaCount)+0.5f);
  
  params.hypha.color = settings.hypha.color;
  params.hypha.speed = Tools::randomInRange(settings.hypha.speed);
  params.hypha.speedVariation = Tools::randomInRange(settings.hypha.speedVariation);
  params.hypha.maxForkAngle = Tools::randomInRange(settings.hypha.maxForkAngle);
  params.hypha.maxBendAngle = Tools::randomInRange(settings.hypha.maxBendAngle);
  params.hypha.radiusTolerance = Tools::randomInRange(settings.hypha.radiusTolerance);
  
  return params;
}
