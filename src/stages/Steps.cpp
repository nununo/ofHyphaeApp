//
//  Steps.cpp
//  hyphaeApp
//
//  Created by Nuno on 02/03/2019.
//

#include "Steps.h"
#include "HyphaeParamsBuilder.h"
#include "StepHyphae.h"
#include "StepCountdown.h"
#include "StepFadeToBlack.h"
#include "StepFadeToWhite.h"

Steps::Steps(Settings *settings) {
  this->settings = settings;
  filenamePrefix = "images/hyphae_" + ofGetTimestampString() + "_";
  setGrowing();
}

void Steps::saveScreen() {
  ofSaveScreen(filenamePrefix + ofToString(counter, 5, '0')+".png");
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
        setIdle();
        break;
    }
  }
}

void Steps::setGrowing() {
  HyphaeParamsBuilder builder;
  HyphaeParams currentParams = builder.create(*settings);
  hyphae.reset(new Hyphae(currentParams, settings->canvas.backgroundColor));
  ofBackground(settings->canvas.backgroundColor);
  step.reset(new StepHyphae(hyphae.get()));
  currentStep = growing;
}

void Steps::setMourning() {
  step.reset(new StepCountdown(settings->canvas.mourningTime * settings->canvas.framerate));
  currentStep = mourning;
}

void Steps::setFadeout() {
  counter++;
  if (saveScreenEnabled) {
    saveScreen();
  }
  if (settings->canvas.backgroundColor.r == 0) {
    step.reset(new StepFadeToBlack(settings->canvas.fadeoutTime * settings->canvas.framerate));
  } else {
    step.reset(new StepFadeToWhite(settings->canvas.fadeoutTime * settings->canvas.framerate));
  }
  currentStep = fadeout;
}

void Steps::setIdle() {
  step.reset(new StepCountdown(settings->canvas.idleTime * settings->canvas.framerate));
  currentStep = idle;
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
