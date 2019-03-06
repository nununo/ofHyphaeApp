//
//  Settings.h
//  hyphaeApp
//
//  Created by Nuno on 27/01/2019.
//

#ifndef Settings_h
#define Settings_h

#include "ofxXmlSettings.h"

struct BorderSettings {
  float distortion;
  ofVec2f ratioVariation;
  ofVec2f radius;
};

struct HyphaSettings {
  ofColor color;           // Color
  float speed;             // Speed in s (which will be converted to frames)
  float speedVariation;    // Percentual variation from speed
  float pixelOverlap;      // How much a position needs to move before a new pixel is drawn
  ofVec2f maxForkAngle;    // Max angle between a fork and its parent's velocity
  ofVec2f maxBendAngle;    // Max angle applied to the velocity on each iteration
  ofVec2f maxBentAngle;    // Max angle allowed between velocity and position (goal: <90º prevents reapproaching center)
                           // Smaller maxBentAngle (ex.:50º) will start creating patterns as a result of the trajectory being constantly corrected
  vector<float> fertilityRatio;  // Next fork distance ratio
};

struct HyphaeSettings {
  int creationAreaSize;           // Square position around (0,0) where primal Hypha are created
  int dyingPixels;                // Hypha's energy is set toofRandom(0,dyingPixels) when it starts dying
  float euthanasiaPercentage;     // When dying, % of Hypha left before all are deleted
  float dyingOutsidePercentage;   // % of Hypha out before Hyphae starts dying
  ofVec2f newPrimalHyphaPeriod;   // Delay between ech new primal hypha
  vector<float> primalHyphaCount; // Number of primal hypha
  vector<float> maxHyphaCount;    // Max possible number of hypha
  BorderSettings border;
  HyphaSettings hypha;
};

struct CanvasSettings {
  int framerate;
  ofColor osdColor;
  ofColor backgroundColor;
  bool antialiasing;
  float mourningTime;      // Time a Hyphae is shown after it is dead (in secs)
  float fadeoutTime;       // Duration of the fadeout (in secs)
  float idleTime;          // Pause before starting a new cycle
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
