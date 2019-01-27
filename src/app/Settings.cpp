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
  
  mycelium.lifespan = xmlSettings.getValue("mycelia:mycelium:lifespan", 1); // 10000

  mycelium.conidia.space = xmlSettings.getValue("mycelia:mycelium:conidia:space", 100); // 5
  mycelium.conidia.perimeterDistortion = xmlSettings.getValue("mycelia:mycelium:conidia:perimeterDistortion", 10.0f); // 0.0026f
  mycelium.conidia.growthSpeed = xmlSettings.getValue("mycelia:mycelium:conidia:growthSpeed", 10.0f); // 0.0026f
  mycelium.conidia.maxRings = xmlSettings.getValue("mycelia:mycelium:conidia:maxRings", 1); // 200f
  mycelium.conidia.space = xmlSettings.getValue("mycelia:mycelium:conidia:angleResolution", 1); // 10

  mycelium.conidia.conidium.lifespan = xmlSettings.getValue("mycelia:mycelium:conidia:conidium:lifespan", 1); // 1000

  mycelium.hyphae.creationAreaSize = xmlSettings.getValue("mycelia:mycelium:hyphae:creationAreaSize", 1000); // 40
  mycelium.hyphae.initHyphaCount = xmlSettings.getValue("mycelia:mycelium:hyphae:initHyphaCount", 0); // 10

  mycelium.hyphae.hypha.maxLifespan = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxLifespan", 1); // 100000
  mycelium.hyphae.hypha.distortion = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:distortion", 1000.0f); // 1.0f
  mycelium.hyphae.hypha.forkAgeRatio = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:forkAgeRatio", 10000.0f); // 2.0f
  mycelium.hyphae.hypha.maxForkAngle = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxForkAngle", 1.0f); // 90
  mycelium.hyphae.hypha.maxBendAngle = xmlSettings.getValue("mycelia:mycelium:hyphae:hypha:maxBendAngle", 10.0f); // 1
}
