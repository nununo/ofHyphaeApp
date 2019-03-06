//
//  Settings.cpp
//  hyphaeApp
//
//  Created by Nuno on 27/01/2019.
//

#include "Settings.h"

Settings::Settings(const string& xmlFile) {
  ofxXmlSettings s;

  s.loadFile(xmlFile);
  
  canvas.framerate = s.getValue("rhizopus:canvas:framerate", 1); // 120
  canvas.osdColor = getColor(s, "rhizopus:canvas:osdColor");
  canvas.backgroundColor = getColor(s, "rhizopus:canvas:backgroundColor");
  canvas.antialiasing = (bool)s.getValue("rhizopus:canvas:antialiasing", true);
  canvas.mourningTime = s.getValue("rhizopus:canvas:mourningTime", 0); // 5
  canvas.fadeoutTime = s.getValue("rhizopus:canvas:fadeoutTime", 0); // 5
  canvas.idleTime = s.getValue("rhizopus:canvas:idleTime", 0); // 5

  hyphae.border.distortion = s.getValue("rhizopus:hyphae:border:distortion", 0.0f); // 0.7
  hyphae.border.radius = getRange(s, "rhizopus:hyphae:border:radius", 10);
  hyphae.border.ratioVariation = getRange(s, "rhizopus:hyphae:border:ratioVariation", 1);

  hyphae.dyingPixels = s.getValue("rhizopus:hyphae:dyingPixels", 0); // 20
  hyphae.creationAreaSize = s.getValue("rhizopus:hyphae:creationAreaSize", 1000); // 40
  hyphae.primalHyphaCount = getSet(s, "rhizopus:hyphae:primalHyphaCount");
  hyphae.newPrimalHyphaPeriod = getRange(s, "rhizopus:hyphae:newPrimalHyphaPeriod", 0.0f); // 100
  hyphae.maxHyphaCount = getSet(s, "rhizopus:hyphae:maxHyphaCount");
  hyphae.euthanasiaPercentage = s.getValue("rhizopus:hyphae:euthanasiaPercentage", 100.0f) / 100.0f; // 10.0f
  hyphae.dyingOutsidePercentage = s.getValue("rhizopus:hyphae:dyingOutsidePercentage", 100.0f) / 100.0f; // 10.0f

  hyphae.hypha.color = getColor(s, "rhizopus:hyphae:hypha:color");
  hyphae.hypha.speed = s.getValue("rhizopus:hyphae:hypha:speed", 1.0f) / canvas.framerate; // pixels/second
  hyphae.hypha.speedVariation = s.getValue("rhizopus:hyphae:hypha:speedVariation", 0.0f); // 10%
  hyphae.hypha.pixelOverlap = s.getValue("rhizopus:hyphae:hypha:pixelOverlap", 0.0f); // 0.9f
  hyphae.hypha.maxForkAngle = getRange(s, "rhizopus:hyphae:hypha:maxForkAngle", 1.0f); // 90
  hyphae.hypha.maxBendAngle = getRange(s, "rhizopus:hyphae:hypha:maxBendAngle", 0.0f); // 1
  hyphae.hypha.maxBentAngle = getRange(s, "rhizopus:hyphae:hypha:maxBentAngle", 0.0f); // 80
  hyphae.hypha.fertilityRatio = getRange(s, "rhizopus:hyphae:hypha:fertilityRatio", 0.0f); // 1.0f
}

int Settings::pushTags(ofxXmlSettings &s, const string& xmlPath) {
  int pos;
  int levels = 0;
  string tag = xmlPath;
  do {
    pos = tag.find(":");
    string tagToFind((pos > 0) ? tag.substr(0,pos) :tag);
    s.pushTag(tagToFind);
    levels++;
    if (pos>0) {
      tag = tag.substr(pos+1);
    }
  } while (pos>0);
  return levels;
}

void Settings::popTags(ofxXmlSettings &s, int levels) {
  for(int i=0;i<levels;i++) {
    s.popTag();
  }
}

ofVec2f Settings::getRange(ofxXmlSettings &s, const string& xmlPath, const float defaultValue) const {
  return ofVec2f(s.getValue(xmlPath + ":min", defaultValue),
                 s.getValue(xmlPath + ":max", defaultValue));
}

vector<float> Settings::getSet(ofxXmlSettings &s, const string& xmlPath) {
  vector<float> list;
  float value;

  int levels = pushTags(s, xmlPath);
  int numElements = s.getNumTags("v");
  for(int i=0; i<numElements; i++){
    value = s.getValue("v", 0, i);
    list.push_back(value);
  }
  
  popTags(s, levels);
  return list;
}

ofColor Settings::getColor(ofxXmlSettings &s, const string& xmlPath) const {
  return ofColor(s.getValue(xmlPath + ":r", 0),
                 s.getValue(xmlPath + ":g", 0),
                 s.getValue(xmlPath + ":b", 0),
                 s.getValue(xmlPath + ":a", 255));
}
