//
//  Hypha.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hypha_h
#define Hypha_h

#include "ofMain.h"
#include "Ink.h"

class Hypha {
private:
  ofVec2f pos;
  Ink *ink;
  ofVec2f vel;
  ofVec2f lastIntPos;
  bool posIsNewPixel;

public:
  Hypha(ofVec2f pos, Ink *ink, ofVec2f vel);
  void update();
  void draw();
};

#endif /* Hypha_h */
