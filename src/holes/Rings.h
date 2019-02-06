//
//  Rings.hpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef Rings_h
#define Rings_h

#include "Ring.h"
#include "Settings.h"

#define MAX_RINGS 200

class Rings {
private:
  Ring *rings[MAX_RINGS];
  ConidiaSettings settings;

public:
  Rings(ConidiaSettings settings);
  int getRing(float radius) {return (int)(radius/settings.space);}
  ofVec2f fill(int ring, float angle);
  void draw();
};

#endif /* Rings_h */
