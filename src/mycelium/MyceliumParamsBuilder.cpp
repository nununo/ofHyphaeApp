//
//  MyceliumParamsBuilder.cpp
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#include "MyceliumParamsBuilder.h"

MyceliumParams MyceliumParamsBuilder::create() {
  MyceliumParams params;
  
  params.border.distortion = settings.border.distortion;
  params.border.radius = ofRandom(settings.border.radiusRange.x, settings.border.radiusRange.y);
  params.border.ratioVariation = settings.border.ratioRange;

  params.hyphae.creationAreaSize = settings.hyphae.creationAreaSize;
  params.hyphae.primalHyphaCount = settings.hyphae.primalHyphaCount;
  params.hyphae.newPrimalHyphaPeriod = settings.hyphae.newPrimalHyphaPeriod;
  params.hyphae.maxHyphaCount = settings.hyphae.maxHyphaCount;
  
  params.hyphae.hypha.color = settings.hyphae.hypha.color;
  params.hyphae.hypha.speed = settings.hyphae.hypha.speed;
  params.hyphae.hypha.speedVariation = settings.hyphae.hypha.speedVariation;
  params.hyphae.hypha.maxForkAngle = settings.hyphae.hypha.maxForkAngle;
  params.hyphae.hypha.maxBendAngle = settings.hyphae.hypha.maxBendAngle;
  params.hyphae.hypha.radiusTolerance = settings.hyphae.hypha.radiusTolerance;
  
  return params;
}
