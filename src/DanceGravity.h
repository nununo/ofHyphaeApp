//
//  DanceGravity.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef DanceGravity_h
#define DanceGravity_h

#include "Dance.h"
#include "Ink.h"
#include "ofMain.h"

class DanceGravity : public Dance {
private:
  Ink *ink;
  ofVec2f cursor;
  
public:
  DanceGravity(Ink *ink, ofVec2f pos) : Dance(pos) {this->ink = ink;}
  void update();
  void draw();
};

#endif /* DanceGravity_h */
