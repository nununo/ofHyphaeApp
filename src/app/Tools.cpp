//
//  Tools.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Tools.h"

int Tools::angleToInt(float angle) {
  return ((int)((angle+360) + 0.5))%360;
}

float Tools::randomInSet(vector<float> set) {
  int r = (int)ofRandom(set.size()-0.1f);
  return set[r];
}
