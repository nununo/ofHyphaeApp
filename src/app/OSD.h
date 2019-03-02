//
//  OSD.h
//  moldApp
//
//  Created by Nuno on 23/02/2019.
//

#ifndef OSD_h
#define OSD_h

#include "Settings.h"
#include "HyphaeParams.h"
#include "HyphaeStats.h"

class OSD {
private:
  const int distance = 15;

  Settings *settings;
  bool active = true;
  bool clean = false;
  int currentLine = 0;

  void drawBackground();
  void drawInfo(const HyphaeParams params, const HyphaeStats stats, const string lifecycleStage);
  void drawLine(const string text);

public:
  OSD(Settings *settings) {this->settings = settings;}
  void draw(const HyphaeParams params, const HyphaeStats stats, const string currentStep);
  void toggleActive() {active=!active;}
};

#endif /* OSD_h */
