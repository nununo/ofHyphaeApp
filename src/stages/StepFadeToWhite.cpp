//
//  StepFadeToWhite.cpp
//  moldApp
//
//  Created by Nuno on 03/03/2019.
//

#include "StepFadeToWhite.h"
#include "ofMain.h"

#define ITERATIONS 256

StepFadeToWhite::StepFadeToWhite(int count): StepCountdown(count) {
  period = count/(float)256;
  if (period==0) {
    period = 1;
  }
}

void StepFadeToWhite::draw() {
  if (ofGetFrameNum() % period == 0) {
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(ofColor::white, 1);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
  }
}
