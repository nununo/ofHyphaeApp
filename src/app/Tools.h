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
  static float randomInRange(ofVec2f v) {return ofRandom(v.x, v.y);}
  static float randomInSet(vector<float> set);
  static ofVec2f getRandomVec2f() {ofVec2f(ofRandom(99999), ofRandom(99999));}
};

#endif /* Tools_h */
