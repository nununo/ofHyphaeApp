//
//  StepFadeToBlack.cpp
//  moldApp
//
//  Created by Nuno on 03/03/2019.
//

#include "StepFadeToBlack.h"
#include "ofMain.h"

#define ALPHA_LEVELS 256

StepFadeToBlack::StepFadeToBlack(int count): StepCountdown((count>ALPHA_LEVELS?count:ALPHA_LEVELS)) {
  // We must do 256 iterations. If count<256 we set it to 256 (sending it to our
  // superclass). In that case the period will also be <1 so we'll set it to 1.
  period=getCount()/(float)ALPHA_LEVELS;
  if (period==0) {
    period = 1;
  }
}

void StepFadeToBlack::draw() {
  if (ofGetFrameNum() % period == 0) {
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(ofColor::black, alpha++);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
    if (ofGetFrameNum()%(period*10)==0) {alpha++;}
  }
}
