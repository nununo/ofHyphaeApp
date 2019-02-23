//
//  OSD.cpp
//  moldApp
//
//  Created by Nuno on 23/02/2019.
//

#include "OSD.h"

void OSD::draw(const Settings &settings, const HyphaeParams params, const HyphaeStats stats) {
  if (!active) {
    return;
  }

  int line = 1;
  const int distance = 15;
  
  ofPushStyle();
  
  ofSetColor(settings.canvas.backgroundColor);
  ofDrawRectangle(0, 0, 180, 250);
  
  ofSetColor(settings.canvas.osdColor);

  string str = "#" + ofToString(params.seed);
  ofDrawBitmapString(str, 10,distance*line++);
  
  line++;

  str = "noiseOffset: " + ofToString(params.border.noiseOffset);
  ofDrawBitmapString(str, 10,distance*line++);

  str = "distortion: " + ofToString(params.border.distortion);
  ofDrawBitmapString(str, 10,distance*line++);

  str = "radius: " + ofToString(params.border.radius) + " (" +
        ofToString(params.border.ratioVariation.x) + "," +
        ofToString(params.border.ratioVariation.y) + ") tolerance: " + ofToString(params.hypha.radiusTolerance) + "%";
  ofDrawBitmapString(str, 10,distance*line++);

  str = "speed: " + ofToString(params.hypha.speed) + " +-" + ofToString(params.hypha.speedVariation) + "%";
  ofDrawBitmapString(str, 10,distance*line++);

  str = "max bend angle: " + ofToString(params.hypha.maxBendAngle);
  ofDrawBitmapString(str, 10,distance*line++);

  str = "max fork angle: " + ofToString(params.hypha.maxForkAngle);
  ofDrawBitmapString(str, 10,distance*line++);

  str = "creation area size: " + ofToString(params.creationAreaSize);
  ofDrawBitmapString(str, 10,distance*line++);

  str = "new primal hypha period: " + ofToString(params.newPrimalHyphaFramesPeriod);
  ofDrawBitmapString(str, 10,distance*line++);

  line++;
  
  str = "framerate: " + ofToString(ofGetFrameRate(),2);
  ofDrawBitmapString(str, 10,distance*line++);
  
  str = "hyphae: " + ofToString(stats.hyphaCount) + "/" + ofToString(params.maxHyphaCount);
  ofDrawBitmapString(str, 10,distance*line++);
  
  str = "primalHyphae: " + ofToString(stats.primalHyphaCount) + "/" + ofToString(params.primalHyphaCount);
  ofDrawBitmapString(str, 10,distance*line++);

  ofPopStyle();
}
