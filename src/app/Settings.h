//
//  Settings.h
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#ifndef Settings_h
#define Settings_h

#include "ofxXmlSettings.h"

struct BorderSettings {
  ofVec2f distortion;
  ofVec2f ratio;
  ofVec2f radius;
};

struct HyphaSettings {
  ofColor color;
  ofVec2f speed;
  ofVec2f speedVariation;
  ofVec2f maxForkAngle;
  ofVec2f maxBendAngle;
  ofVec2f radiusTolerance;
};

struct HyphaeSettings {
  ofVec2f creationAreaSize;
  vector<float> primalHyphaCount;
  ofVec2f newPrimalHyphaPeriod;
  vector<float> maxHyphaCount;
  BorderSettings border;
  HyphaSettings hypha;
};

struct CanvasSettings {
  int framerate;
  ofColor osdColor;
  int width;
  int height;
  ofColor backgroundColor;
};

class Settings {
private:  
  ofVec2f getRange(ofxXmlSettings &xmlSettings, const string& xmlPath, const float defaultValue=0.0f) const;
  ofColor getColor(ofxXmlSettings &s, const string& xmlPath) const;
  vector<float> getSet(ofxXmlSettings &s, const string& xmlPath);
  int pushTags(ofxXmlSettings &s, const string& xmlPath);
  void popTags(ofxXmlSettings &s, int levels);

public:
  CanvasSettings canvas;
  HyphaeSettings hyphae;

  Settings(const string& xmlFile);
};

#endif /* Settings_h */
