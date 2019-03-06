//
//  Tools.cpp
//  hyphaeApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Tools.h"

int Tools::angleToInt(float angle) {
  return ((int)((angle+36000) + 0.5))%360;
}

float Tools::angleTo360(float angle) {
  while(angle>360) {angle-=360;}
  while(angle<0) {angle+=360;}
  return angle;
}

float Tools::randomInSet(vector<float> set) {
  int r = (int)ofRandom(set.size()-0.1f);
  return set[r];
}
