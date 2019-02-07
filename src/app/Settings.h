//
//  Settings.h
//  moldApp
//
//  Created by Nuno on 27/01/2019.
//

#ifndef Settings_h
#define Settings_h

#include "ofxXmlSettings.h"

struct HyphaSettings {
  int maxLifespan;
  float speed;
  float speedRange;
  float gravity;
  int maxHeight;
  float distortion;
  float forkAgeRatio;
  float maxForkAngle;
  float maxBendAngle;
  float fertilityRateRatio;
  float fertilityRatePower;
};

struct HyphaeSettings {
  bool active;
  ofColor color;
  int creationAreaSize;
  HyphaSettings hypha;
  int initHyphaCount;
  int maxHyphaCount;
  int newHyphaPeriod;
};

struct ConidiumSettings {
  int lifespan;
};

struct ConidiaSettings {
  bool active;
  ConidiumSettings conidium;
};

struct HolesSettings {
  int space;
  float growthSpeed;
  float perimeterDistortion;
  int maxRings;
  int angleResolution;
};

struct MyceliumSettings {
  int lifespan;
  HolesSettings holes;
  ConidiaSettings conidia;
  HyphaeSettings hyphae;
};


class Settings {
private:
  ofxXmlSettings xmlSettings;

public:
  int framerate;
  int width;
  int height;
  ofColor backgroundColor;
  ofColor foregroundColor;
  MyceliumSettings mycelium;

  Settings(const string& xmlFile);
};

#endif /* Settings_h */
