//
//  DanceRandom.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef DanceRandom_h
#define DanceRandom_h

#include "IDance.h"
#include "Ink.h"
#include "ofMain.h"

class DanceRandom : public IDance {
private:
  Ink *ink;
  ofVec2f cursor;

public:
  DanceRandom(Ink *ink);
  void update();
  void draw();
};

#endif /* DanceRandom_h */
