//
//  Steps.cpp
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#include "Steps.h"
#include "HyphaeParamsBuilder.h"
#include "StepHyphae.h"
#include "StepCountdown.h"
#include "StepFadeout.h"

Steps::Steps(Settings *settings) {
  this->settings = settings;
  setGrowing();
}

void Steps::update() {
  if (step->isAlive()) {
    step->update();
  } else {
    switch (currentStep) {
      case idle:
        setGrowing();
        break;
      case growing:
        setMourning();
        break;
      case mourning:
        setFadeout();
        break;
      case fadeout:
        currentStep = idle;
        break;
    }
  }
}

void Steps::setGrowing() {
  HyphaeParamsBuilder builder;
  HyphaeParams currentParams = builder.create(*settings);
  hyphae.reset(new Hyphae(currentParams));
  ofBackground(settings->canvas.backgroundColor);
  currentStep = growing;
  step.reset(new StepHyphae(hyphae.get()));
}

void Steps::setMourning() {
  step.reset(new StepCountdown(settings->canvas.mourningTime * settings->canvas.framerate, 256));
  currentStep = mourning;
}

void Steps::setFadeout() {
  step.reset(new StepFadeout(settings->canvas.backgroundColor, settings->canvas.fadeoutTime * settings->canvas.framerate, 256));
  currentStep = fadeout;
}

string Steps::getCurrentStepName() {
  switch (currentStep) {
    case idle:
      return "idle";
      break;
    case growing:
      return "growing";
      break;
    case mourning:
      return "mourning";
      break;
    case fadeout:
      return "fadeout";
      break;
    default:
      return "?";
      break;
  }
}
