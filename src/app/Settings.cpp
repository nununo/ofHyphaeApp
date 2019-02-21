//
//  Settings.cpp
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#include "Settings.h"

Settings::Settings(const string& xmlFile) {
  xmlSettings.loadFile(xmlFile);
  
  framerate = xmlSettings.getValue("mycelia:framerate", 1); // 120
  osdColor = ofColor(xmlSettings.getValue("mycelia:osdColor:r", 0),
                     xmlSettings.getValue("mycelia:osdColor:g", 255),
                     xmlSettings.getValue("mycelia:osdColor:b", 0),
                     xmlSettings.getValue("mycelia:osdColor:a", 255));

  canvas.width = xmlSettings.getValue("mycelia:canvas:width", 1); // 1920
  canvas.height = xmlSettings.getValue("mycelia:canvas:height", 1); // 1080
  canvas.backgroundColor = ofColor(xmlSettings.getValue("mycelia:canvas:backgroundColor:r", 255),
                                   xmlSettings.getValue("mycelia:canvas:backgroundColor:g", 0),
                                   xmlSettings.getValue("mycelia:canvas:backgroundColor:b", 0));

  mycelium.border.distortion = xmlSettings.getValue("mycelia:mycelium:border:distortion", 0.0f); // 0.3f
  mycelium.border.radiusRange = getRange("mycelia:mycelium:border:radiusRange", 10);
  mycelium.border.ratioRange = getRange("mycelia:mycelium:border:ratioRange", 1);

  mycelium.hyphae.creationAreaSize = getRange("mycelia:mycelium:hyphae:creationAreaSize", 1000); // 40
  mycelium.hyphae.primalHyphaCount = getRange("mycelia:mycelium:hyphae:primalHyphaCount", 7); // 10
  mycelium.hyphae.newPrimalHyphaPeriod = getRange("mycelia:mycelium:hyphae:newPrimalHyphaPeriod", 0.0f); // 100
  mycelium.hyphae.maxHyphaCount = getRange("mycelia:mycelium:hyphae:maxHyphaCount", 0); // 10000

  mycelium.hyphae.hypha.color = ofColor(xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:color:r", 255),
                                        xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:color:g", 0),
                                        xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:color:b", 0),
                                        xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:color:a", 255));
  mycelium.hyphae.hypha.speed = getRange("mycelia:mycelium:hyphae:hypha:speed", 1) / framerate; // pixels/second
  mycelium.hyphae.hypha.speedVariation = getRange("mycelia:mycelium:hyphae:hypha:speedVariation", 0.0f); // 10%
  mycelium.hyphae.hypha.maxForkAngle = getRange("mycelia:mycelium:hyphae:hypha:maxForkAngle", 1.0f); // 90
  mycelium.hyphae.hypha.maxBendAngle = getRange("mycelia:mycelium:hyphae:hypha:maxBendAngle", 0.0f); // 1
  mycelium.hyphae.hypha.radiusTolerance = getRange("mycelia:mycelium:hyphae:hypha:radiusTolerance", 1.0f); // 10%
}

ofVec2f Settings::getRange(const string& xmlPath, const float defaultValue) const {
  return ofVec2f(xmlSettings.getValue(xmlPath + ":min", defaultValue),
                 xmlSettings.getValue(xmlPath + ":max", defaultValue));
}
