//
//  Tools.h
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#ifndef Tools_h
#define Tools_h

#include "ofMain.h"

class Tools {
public:
  static int angleToInt(float angle, int resolution=1);
  static float posToAngle(ofVec2f v) {return ofVec2f(1,0).angle(v);}
};

#endif /* Tools_h */
