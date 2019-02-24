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
  bool active = true;
  bool clean = false;

  void drawBackground(const Settings &settings);
  void drawInfo(const Settings &settings, const HyphaeParams params, const HyphaeStats stats, const int lifecycleStage);

public:
  void draw(const Settings &settings, const HyphaeParams params, const HyphaeStats stats, const int lifecycleStage);
  void toggleActive() {active=!active;}
};

#endif /* OSD_h */
