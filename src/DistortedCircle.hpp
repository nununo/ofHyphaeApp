//
//  DistortedCircle.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef DistortedCircle_hpp
#define DistortedCircle_hpp

#include "ofMain.h"
#include "Utils.hpp"

class DistortedCircle {

private:
  float points[360];
  int iteration;
  ofVec2f offset;
  float scale;
  
public:
  DistortedCircle();
  float getRadius(float angle) {return points[Utils::angleToIndex(angle)];}
  void update();
  void draw(float radius, float distance);
};

#endif /* DistortedCircle_hpp */
