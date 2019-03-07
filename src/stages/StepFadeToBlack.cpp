//
//  StepFadeToBlack.cpp
//  hyphaeApp
//
//  Created by Nuno on 03/03/2019.
//

#include "StepFadeToBlack.h"
#include "ofMain.h"

void StepFadeToBlack::draw() {
  ofPushStyle();
  ofEnableAlphaBlending();
  ofSetColor(ofColor::black, alpha++);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  ofPopStyle();
  if (ofGetFrameNum()%3==0) {alpha++;}
}
