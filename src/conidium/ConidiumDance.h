//
//  ConidiumDance.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef ConidiumDance_h
#define ConidiumDance_h

#include "ofMain.h"
#include "Ink.h"

class ConidiumDance {
private:
  Ink *ink;
  ofVec2f cursor;
  float recenterRatio;

public:
  ConidiumDance(Ink *ink, float recenterRatio);
  void update();
  void draw();
};

#endif /* ConidiumDance_h */
