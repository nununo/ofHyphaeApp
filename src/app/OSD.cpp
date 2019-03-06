//
//  OSD.cpp
//  hyphaeApp
//
//  Created by Nuno on 23/02/2019.
//

#include "OSD.h"

void OSD::draw(const HyphaeParams params, const HyphaeStats stats, const string currentStep, const bool saveScreenEnabled) {
  drawBackground();
  drawInfo(params, stats, currentStep, saveScreenEnabled);
}

void OSD::drawBackground() {
  if (!clean) {
    ofPushStyle();
    ofSetColor(settings->canvas.backgroundColor);
    ofDrawRectangle(0, 0, 400, 400);
    ofPopStyle();
    clean = true;
    currentLine = 0;
  }
}

void OSD::drawLine(const string text) {
  ofDrawBitmapString(text, 10,distance*(1+currentLine++));
}

void OSD::drawInfo(const HyphaeParams params, const HyphaeStats stats, const string currentStep, const bool saveScreenEnabled) {
  if (!active) {
    return;
  }
  
  ofPushStyle();
  ofSetColor(settings->canvas.osdColor);
  
  drawLine("#" + ofToString(params.seed));
  
  drawLine("");

  drawLine("border");
  drawLine(" distortion: " + ofToString(params.border.distortion));
  drawLine(" radius: " + ofToString(params.border.radius));

  drawLine("");

  drawLine("hypha");
  drawLine(" speed: " + ofToString(params.hypha.speed) + " +-" + ofToString(params.hypha.speedVariation) + "%");
  drawLine(" max bend angle: " + ofToString(params.hypha.maxBendAngle));
  drawLine(" max bent angle: " + ofToString(params.hypha.maxBentAngle));
  drawLine(" max fork angle: " + ofToString(params.hypha.maxForkAngle));
  drawLine(" fertility ratio: " + ofToString(params.hypha.fertilityRatio));

  drawLine("");

  drawLine("hyphae");
  drawLine(" creation area size: " + ofToString(params.creationAreaSize));
  drawLine(" new primal hypha period: " + ofToString(params.newPrimalHyphaFramesPeriod));

  drawLine("");

  drawLine("stats");
  drawLine(" framerate: " + ofToString(ofGetFrameRate(),2));
  drawLine(" hyphae lifetime: " + ofToString((ofGetFrameNum() - stats.startFrameNum) / settings->canvas.framerate ,2));
  drawLine(" step: " + currentStep);
  drawLine(" hyphae: " + ofToString(stats.hyphaCount) + "/" + ofToString(params.maxHyphaCount));
  drawLine(" primalHyphae: " + ofToString(stats.primalHyphaCount) + "/" + ofToString(params.primalHyphaCount));
  drawLine(" outside: " + ofToString(stats.outsideCount));

  drawLine("");
  
  drawLine("antialiasing: " + ofToString(settings->canvas.antialiasing));
  drawLine("save screen: " + ofToString(saveScreenEnabled));

  ofPopStyle();

  clean = false;
}
