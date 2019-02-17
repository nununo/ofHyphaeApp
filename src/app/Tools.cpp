//
//  Tools.cpp
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#include "Tools.h"

int Tools::angleToInt(float angle, int resolution) {
  return ((int)((angle+360)*resolution + 0.5))%(360*resolution);
}
