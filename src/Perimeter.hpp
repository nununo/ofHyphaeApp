//
//  Perimeter.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Perimeter_hpp
#define Perimeter_hpp

#include "ofMain.h"
#include "DistortedCircle.hpp"

class Perimeter {
  
private:
  DistortedCircle *dc;
  float elementDistance;
  float growthSpeed;
  float lastElements[360];
  float cursors[360];

  float getElementAngleDistance(float r);

public:
  Perimeter(float growthSpeed, float elementDistance);
  ~Perimeter();
  void update();
  void draw();
};

#endif /* Perimeter_hpp */
