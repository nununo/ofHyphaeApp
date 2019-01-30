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
  ofVec2f offset;
  float scale;
  
public:
  DistortedCircle(float scale);
  float get(ofVec2f p);
  float getForAngle(float angle, float radius);
};

#endif /* DistortedCircle_hpp */
