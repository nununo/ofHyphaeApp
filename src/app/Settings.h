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
  ofVec2f ratioVariation;
  ofVec2f radius;
};

struct HyphaSettings {
  ofColor color;           // Color
  ofVec2f speed;           // Speed in s (which will be converted to frames)
  ofVec2f speedVariation;  // Percentual variation from speed
  ofVec2f maxForkAngle;    // Max angle between a fork and its parent's velocity
  ofVec2f maxBendAngle;    // Max angle applied to the velocity on each iteration
  ofVec2f maxBentAngle;    // Max angle allowed between velocity and position (<90º prevents reapproaching center)
  ofVec2f pixelOverlap;    // How much a position needs to move before a new pixel is drawn
};

struct HyphaeSettings {
  ofVec2f creationAreaSize;
  float dyingTime;
  vector<float> primalHyphaCount;
  ofVec2f newPrimalHyphaPeriod;
  vector<float> maxHyphaCount;
  BorderSettings border;
  HyphaSettings hypha;
};

struct CanvasSettings {
  int framerate;
  ofColor osdColor;
  ofVec2f size;
  ofColor backgroundColor;
  float mourningTime;      // Time a Hyphae is shown after it is dead (in secs)
  float fadeoutTime;       // Duration of the fadeout (in secs)
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
