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
  ofColor color;
  float speed;
  float speedVariation;
  float maxForkAngle;
  float maxBendAngle;
  float radiusTolerance;
};

struct HyphaeSettings {
  bool active;
  int creationAreaSize;
  HyphaSettings hypha;
  int primalHyphaCount;
  float newPrimalHyphaPeriod;
  int maxHyphaCount;
};

struct ConidiumSettings {
  int lifespan;
  float delay;
  float recenterRatio;
};

struct ConidiaSettings {
  bool active;
  ConidiumSettings conidium;
};

struct MyceliumSettings {
  ofVec2f radiusRange;
  ConidiaSettings conidia;
  HyphaeSettings hyphae;
};

struct CanvasSettings {
  int width;
  int height;
  std::filesystem::path shaderFilename;
  ofColor backgroundColor;
};

class Settings {
private:
  ofxXmlSettings xmlSettings;

public:
  int framerate;
  ofColor osdColor;
  CanvasSettings canvas;
  MyceliumSettings mycelium;

  Settings(const string& xmlFile);
};

#endif /* Settings_h */
