//
//  StepFadeToBlack.cpp
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#include "StepFadeToBlack.h"

#define STEPS 256

StepFadeToBlack::StepFadeToBlack(int count): StepCountdown((count>STEPS?count:STEPS)) {
  // We must do 256 iterations. If count<256 we set it to 256 (sending it to our
  // superclass). In that case the period will also be <1 so we'll set it to 1.
  period=getCount()/(float)STEPS;
  if (period==0) {
    period = 1;
  }
  screenTexture.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "shaders/fadeToBlack.frag");
  shader.linkProgram();
  
}

void StepFadeToBlack::draw() {
  if (ofGetFrameNum() % period == 0) {
    ofPushStyle();
    screenTexture.loadScreenData(0, 0, ofGetWidth(), ofGetHeight());
    shader.begin();
    shader.setUniform1f("amount", 1/(float(STEPS)));
    screenTexture.draw(0,0);
    shader.end();
    ofPopStyle();
  }
}
