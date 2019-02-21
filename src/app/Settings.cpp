//
//  Settings.cpp
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#include "Settings.h"

Settings::Settings(const string& xmlFile) {
  xmlSettings.loadFile(xmlFile);
  
  canvas.framerate = xmlSettings.getValue("rhizopus:canvas:framerate", 1); // 120
  canvas.osdColor = ofColor(xmlSettings.getValue("rhizopus:canvas:osdColor:r", 0),
                            xmlSettings.getValue("rhizopus:canvas:osdColor:g", 255),
                            xmlSettings.getValue("rhizopus:canvas:osdColor:b", 0),
                            xmlSettings.getValue("rhizopus:canvas:osdColor:a", 255));

  canvas.width = xmlSettings.getValue("rhizopus:canvas:width", 1); // 1920
  canvas.height = xmlSettings.getValue("rhizopus:canvas:height", 1); // 1080
  canvas.backgroundColor = ofColor(xmlSettings.getValue("rhizopus:canvas:backgroundColor:r", 255),
                                   xmlSettings.getValue("rhizopus:canvas:backgroundColor:g", 0),
                                   xmlSettings.getValue("rhizopus:canvas:backgroundColor:b", 0));

  hyphae.border.distortion = xmlSettings.getValue("rhizopus:hyphae:border:distortion", 0.0f); // 0.3f
  hyphae.border.radiusRange = getRange("rhizopus:hyphae:border:radiusRange", 10);
  hyphae.border.ratioRange = getRange("rhizopus:hyphae:border:ratioRange", 1);

  hyphae.creationAreaSize = getRange("rhizopus:hyphae:creationAreaSize", 1000); // 40
  hyphae.primalHyphaCount = getRange("rhizopus:hyphae:primalHyphaCount", 7); // 10
  hyphae.newPrimalHyphaPeriod = getRange("rhizopus:hyphae:newPrimalHyphaPeriod", 0.0f); // 100
  hyphae.maxHyphaCount = getRange("rhizopus:hyphae:maxHyphaCount", 0); // 10000

  hyphae.hypha.color = ofColor(xmlSettings.getValue("rhizopus:hyphae:hypha:color:r", 255),
                               xmlSettings.getValue("rhizopus:hyphae:hypha:color:g", 0),
                               xmlSettings.getValue("rhizopus:hyphae:hypha:color:b", 0),
                               xmlSettings.getValue("rhizopus:hyphae:hypha:color:a", 255));
  hyphae.hypha.speed = getRange("rhizopus:hyphae:hypha:speed", 1) / canvas.framerate; // pixels/second
  hyphae.hypha.speedVariation = getRange("rhizopus:hyphae:hypha:speedVariation", 0.0f); // 10%
  hyphae.hypha.maxForkAngle = getRange("rhizopus:hyphae:hypha:maxForkAngle", 1.0f); // 90
  hyphae.hypha.maxBendAngle = getRange("rhizopus:hyphae:hypha:maxBendAngle", 0.0f); // 1
  hyphae.hypha.radiusTolerance = getRange("rhizopus:hyphae:hypha:radiusTolerance", 1.0f); // 10%
}

ofVec2f Settings::getRange(const string& xmlPath, const float defaultValue) const {
  return ofVec2f(xmlSettings.getValue(xmlPath + ":min", defaultValue),
                 xmlSettings.getValue(xmlPath + ":max", defaultValue));
}
