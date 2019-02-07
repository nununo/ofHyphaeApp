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
  width = xmlSettings.getValue("mycelia:width", 1); // 1920
  height = xmlSettings.getValue("mycelia:height", 1); // 1080
  backgroundColor = ofColor(xmlSettings.getValue("mycelia:backgroundColor:r", 255),
                                     xmlSettings.getValue("mycelia:backgroundColor:g", 0),
                                     xmlSettings.getValue("mycelia:backgroundColor:b", 0));
  foregroundColor = ofColor(xmlSettings.getValue("mycelia:foregroundColor:r", 0),
                                     xmlSettings.getValue("mycelia:foregroundColor:g", 255),
                                     xmlSettings.getValue("mycelia:foregroundColor:b", 0));
  mycelium.lifespan = xmlSettings.getValue("mycelia:mycelium:lifespan", 1); // 10000
 
  mycelium.holes.space = xmlSettings.getValue("mycelia:mycelium:holes:space", 100); // 5
  mycelium.holes.perimeterDistortion = xmlSettings.getValue("mycelia:mycelium:holes:perimeterDistortion", 10.0f); // 0.0026f
  mycelium.holes.growthSpeed = xmlSettings.getValue("mycelia:mycelium:holes:growthSpeed", 10.0f); // 0.0026f
  mycelium.holes.maxRings = xmlSettings.getValue("mycelia:mycelium:holes:maxRings", 1); // 200f
  mycelium.holes.angleResolution = xmlSettings.getValue("mycelia:mycelium:holes:angleResolution", 1); // 10

  mycelium.conidia.active = xmlSettings.getValue("mycelia:mycelium:conidia:active", 0); // 1

  mycelium.conidia.conidium.lifespan = xmlSettings.getValue("mycelia:mycelium:conidia:conidium:lifespan", 1); // 1000

  mycelium.hyphae.active = xmlSettings.getValue("mycelia:mycelium:hyphae:active", 0); // 1
  mycelium.hyphae.color = ofColor(xmlSettings.getValue("mycelia:mycelium:hyphae:color:r", 255),
                                  xmlSettings.getValue("mycelia:mycelium:hyphae:color:g", 0),
                                  xmlSettings.getValue("mycelia:mycelium:hyphae:color:b", 0),
                                  xmlSettings.getValue("mycelia:mycelium:hyphae:color:a", 255));
  mycelium.hyphae.creationAreaSize = xmlSettings.getValue("mycelia:mycelium:hyphae:creationAreaSize", 1000); // 40
  mycelium.hyphae.initHyphaCount = xmlSettings.getValue("mycelia:mycelium:hyphae:initHyphaCount", 0); // 10
  mycelium.hyphae.maxHyphaCount = xmlSettings.getValue("mycelia:mycelium:hyphae:maxHyphaCount", 0); // 10000
  mycelium.hyphae.newHyphaPeriod = xmlSettings.getValue("mycelia:mycelium:hyphae:newHyphaPeriod", 0); // 100

  mycelium.hyphae.hypha.maxLifespan = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxLifespan", 1); // 100000
  mycelium.hyphae.hypha.speed = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:speedRange", 0.0f); // 0.005f
  mycelium.hyphae.hypha.speedRange = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:speedRange", 0.0f); // 0.0025f
  mycelium.hyphae.hypha.gravity = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:gravity", 0.0f); // 0.005f
  mycelium.hyphae.hypha.maxHeight = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxHeight", 0); // 20
  mycelium.hyphae.hypha.distortion = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:distortion", 1000.0f); // 1.0f
  mycelium.hyphae.hypha.forkAgeRatio = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:forkAgeRatio", 10000.0f); // 2.0f
  mycelium.hyphae.hypha.maxForkAngle = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxForkAngle", 1.0f); // 90
  mycelium.hyphae.hypha.maxBendAngle = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxBendAngle", 10.0f); // 1
  mycelium.hyphae.hypha.fertilityRateRatio = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:fertilityRateRatio", 0.0f); // 5
  mycelium.hyphae.hypha.fertilityRatePower = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:fertilityRatePower", 0.0f); // 3
}
