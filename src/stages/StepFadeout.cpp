//
//  StepFadeout.cpp
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#include "StepFadeout.h"

void StepFadeout::draw() {
  if (ofGetFrameNum() % getPeriod() == 0) {
    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(color, 3);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPopStyle();
  }
}
