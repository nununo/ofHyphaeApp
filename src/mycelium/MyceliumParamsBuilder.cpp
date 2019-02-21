//
//  MyceliumParamsBuilder.cpp
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#include "MyceliumParamsBuilder.h"
#include "Tools.h"

MyceliumParams MyceliumParamsBuilder::create() {
  MyceliumParams params;
  
  params.border.distortion = settings.border.distortion;
  params.border.radius = Tools::randomInRange(settings.border.radiusRange);
  params.border.ratioVariation = settings.border.ratioRange;

  params.hyphae.creationAreaSize = Tools::randomInRange(settings.hyphae.creationAreaSize);
  params.hyphae.primalHyphaCount = (int)(Tools::randomInRange(settings.hyphae.primalHyphaCount)+0.5f);
  params.hyphae.newPrimalHyphaPeriod = Tools::randomInRange(settings.hyphae.newPrimalHyphaPeriod);
  params.hyphae.maxHyphaCount = (int)(Tools::randomInRange(settings.hyphae.maxHyphaCount)+0.5f);
  
  params.hyphae.hypha.color = settings.hyphae.hypha.color;
  params.hyphae.hypha.speed = Tools::randomInRange(settings.hyphae.hypha.speed);
  params.hyphae.hypha.speedVariation = Tools::randomInRange(settings.hyphae.hypha.speedVariation);
  params.hyphae.hypha.maxForkAngle = Tools::randomInRange(settings.hyphae.hypha.maxForkAngle);
  params.hyphae.hypha.maxBendAngle = Tools::randomInRange(settings.hyphae.hypha.maxBendAngle);
  params.hyphae.hypha.radiusTolerance = Tools::randomInRange(settings.hyphae.hypha.radiusTolerance);
  
  return params;
}
