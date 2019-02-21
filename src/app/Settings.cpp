//
//  Settings.cpp
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#include "Settings.h"

Settings::Settings(const string& xmlFile) {
  ofxXmlSettings s;

  s.loadFile(xmlFile);
  
  canvas.framerate = s.getValue("rhizopus:canvas:framerate", 1); // 120
  canvas.osdColor = getColor(s, "rhizopus:canvas:osdColor");

  canvas.width = s.getValue("rhizopus:canvas:width", 1); // 1920
  canvas.height = s.getValue("rhizopus:canvas:height", 1); // 1080
  canvas.backgroundColor = getColor(s, "rhizopus:canvas:backgroundColor");

  hyphae.border.distortion = s.getValue("rhizopus:hyphae:border:distortion", 0.0f); // 0.3f
  hyphae.border.radiusRange = getRange(s, "rhizopus:hyphae:border:radiusRange", 10);
  hyphae.border.ratioRange = getRange(s, "rhizopus:hyphae:border:ratioRange", 1);

  hyphae.creationAreaSize = getRange(s, "rhizopus:hyphae:creationAreaSize", 1000); // 40
  hyphae.primalHyphaCount = getRange(s, "rhizopus:hyphae:primalHyphaCount", 7); // 10
  hyphae.newPrimalHyphaPeriod = getRange(s, "rhizopus:hyphae:newPrimalHyphaPeriod", 0.0f); // 100
  hyphae.maxHyphaCount = getRange(s, "rhizopus:hyphae:maxHyphaCount", 0); // 10000

  hyphae.hypha.color = getColor(s, "rhizopus:hyphae:hypha:color");
  hyphae.hypha.speed = getRange(s, "rhizopus:hyphae:hypha:speed", 1) / canvas.framerate; // pixels/second
  hyphae.hypha.speedVariation = getRange(s, "rhizopus:hyphae:hypha:speedVariation", 0.0f); // 10%
  hyphae.hypha.maxForkAngle = getRange(s, "rhizopus:hyphae:hypha:maxForkAngle", 1.0f); // 90
  hyphae.hypha.maxBendAngle = getRange(s, "rhizopus:hyphae:hypha:maxBendAngle", 0.0f); // 1
  hyphae.hypha.radiusTolerance = getRange(s, "rhizopus:hyphae:hypha:radiusTolerance", 1.0f); // 10%
}

ofVec2f Settings::getRange(ofxXmlSettings &s, const string& xmlPath, const float defaultValue) const {
  return ofVec2f(s.getValue(xmlPath + ":min", defaultValue),
                 s.getValue(xmlPath + ":max", defaultValue));
}

ofColor Settings::getColor(ofxXmlSettings &s, const string& xmlPath) const {
  return ofColor(s.getValue(xmlPath + ":r", 0),
                 s.getValue(xmlPath + ":g", 0),
                 s.getValue(xmlPath + ":b", 0),
                 s.getValue(xmlPath + ":a", 255));
}
