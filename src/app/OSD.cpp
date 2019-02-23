//
//  OSD.cpp
//  moldApp
//
//  Created by Nuno on 23/02/2019.
//

#include "OSD.h"

void OSD::draw(HyphaeParams params, HyphaeStats stats) {
  if (!active) {
    return;
  }

  ofPushStyle();
  
  ofSetColor(settings->canvas.backgroundColor);
  ofDrawRectangle(0, 0, 180, 50);
  
  ofSetColor(settings->canvas.osdColor);
  
  string str = "framerate: " + ofToString(ofGetFrameRate(), 2);
  ofDrawBitmapString(str, 10,10);
  
  str = "hyphae: " + ofToString(stats.hyphaCount) + "/" + ofToString(params.maxHyphaCount);
  ofDrawBitmapString(str, 10,25);
  
  str = "primalHyphae: " + ofToString(stats.primalHyphaCount) + "/" + ofToString(params.primalHyphaCount);
  ofDrawBitmapString(str, 10,40);

  str = "seed: " + ofToString(params.border.seed);
  ofDrawBitmapString(str, 10,55);

  str = "distortion: " + ofToString(params.border.distortion);
  ofDrawBitmapString(str, 10,70);

  str = "radius: " + ofToString(params.border.radius) + " (" +
        ofToString(params.border.ratioVariation.x) + "," +
        ofToString(params.border.ratioVariation.y) + ") tolerance: " + ofToString(params.hypha.radiusTolerance) + "%";
  ofDrawBitmapString(str, 10,85);

  str = "speed: " + ofToString(params.hypha.speed) + " +-" + ofToString(params.hypha.speedVariation) + "%";
  ofDrawBitmapString(str, 10,100);

  str = "max bend angle: " + ofToString(params.hypha.maxBendAngle);
  ofDrawBitmapString(str, 10,115);

  str = "max fork angle: " + ofToString(params.hypha.maxForkAngle);
  ofDrawBitmapString(str, 10,130);

  str = "creation area size: " + ofToString(params.creationAreaSize);
  ofDrawBitmapString(str, 10,145);

  str = "new primal hypha period: " + ofToString(params.newPrimalHyphaPeriod);
  ofDrawBitmapString(str, 10,160);

  ofPopStyle();
}
