//
//  DistortedCircle.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef DistortedCircle_hpp
#define DistortedCircle_hpp

#include "ofMain.h"

class DistortedCircle {

private:
  float points[360];
  
public:
  DistortedCircle();
  float getRadius(float angle) {return points[int(angle+0.5f) % 360];}
  void update();
  void draw(float radius);
};

#endif /* DistortedCircle_hpp */
