//
//  Ring.h
//  moldApp
//
//  Created by Nuno on 23/01/2019.
//

#ifndef Ring_h
#define Ring_h

#include "Hole.h"
#include "PositionEventArgs.h"
#include "Border.h"
#include "Settings.h"

#define ANGLE_RESOLUTION 10

class Ring {
private:
  int numElements;
  int angleIndexIncrement;
  Hole holes[360*ANGLE_RESOLUTION];

  int getNumElements(float space, int radius);
  void throwHoleFilledEvent(ofVec2f pos);

public:
  Ring(HolesSettings settings, int ringNum, Border *border);
  void fill(float angle);
  void draw();

  ofEvent<PositionEventArgs> holeFilledEvent;
};

#endif /* Ring_h */
