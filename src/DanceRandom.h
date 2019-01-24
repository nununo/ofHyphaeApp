//
//  DanceRandom.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef DanceRandom_h
#define DanceRandom_h

#include "Dance.h"
#include "Ink.h"
#include "ofMain.h"

class DanceRandom : public Dance {
private:
  Ink *ink;
  ofVec2f cursor;

public:
  DanceRandom(ofVec2f pos, Ink *ink);
  void update();
  void draw();
};

#endif /* DanceRandom_h */
