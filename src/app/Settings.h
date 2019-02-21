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
  float distortion;
  ofVec2f ratioRange;
  ofVec2f radiusRange;
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
  ofVec2f primalHyphaCount;
  ofVec2f newPrimalHyphaPeriod;
  ofVec2f maxHyphaCount;
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
  ofxXmlSettings xmlSettings;
  
  ofVec2f getRange(const string& xmlPath, const float defaultValue=0.0f) const;

public:
  CanvasSettings canvas;
  HyphaeSettings hyphae;

  Settings(const string& xmlFile);
};

#endif /* Settings_h */
