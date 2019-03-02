//
//  StepFadeout.cpp
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#include "StepFadeout.h"

StepFadeout::StepFadeout(ofColor color, int count, int steps): StepCountdown((count>256?count:256)) {
  this->color = color;
  period=getCount()/(float)steps;
  if (period==0) {
    period = 1;
  }
}

void StepFadeout::draw() {
  if (ofGetFrameNum() % period == 0) {
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(color, 3);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
  }
}
