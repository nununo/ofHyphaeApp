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
  Settings *settings;
  bool active;

public:
  OSD(Settings *settings) {this->settings = settings; active=true;}
  void draw(HyphaeParams params, HyphaeStats stats);
  void toggleActive() {active=!active;}
};

#endif /* OSD_h */
