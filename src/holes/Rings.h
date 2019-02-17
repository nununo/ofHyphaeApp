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
  HolesSettings settings;
  std::array<Ring*, MAX_RINGS> rings;

  int getRing(float radius) {return (int)(radius/settings.space);}

public:
  Rings(HolesSettings settings);
  ~Rings();
  void fill(ofVec2f pos);
  void draw();
  void onHoleFilled(PositionEventArgs &e);

  ofEvent<PositionEventArgs> holeFilledEvent;
};

#endif /* Rings_h */
