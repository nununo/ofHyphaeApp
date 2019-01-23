//
//  Ring.h
//  moldApp
//
//  Created by Nuno on 23/01/2019.
//

#ifndef Ring_h
#define Ring_h

#include "Hole.h"

#define ANGLE_RESOLUTION 10

class Ring {
private:
  int numElements;
  int angleIndexIncrement;
  Hole holes[360*ANGLE_RESOLUTION];

  int getNumElements(float space, int radius);
  int getAngleIndex(float angle) {return (int)(angle*ANGLE_RESOLUTION +0.5f);}

public:
  Ring(float space, int radius);
  bool fill(float angle);
  void draw();
};

#endif /* Ring_h */
