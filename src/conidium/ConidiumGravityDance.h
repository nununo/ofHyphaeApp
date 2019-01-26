//
//  ConidiumDanceGravity.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef ConidiumDanceGravity_h
#define ConidiumDanceGravity_h

#include "ConidiumDance.h"
#include "Ink.h"
#include "ofMain.h"

class ConidiumGravityDance : public ConidiumDance {
private:
  Ink *ink;
  ofVec2f cursor;
  
public:
  ConidiumGravityDance(Ink *ink, ofVec2f pos) : ConidiumDance(pos) {this->ink = ink;}
  void update();
  void draw();
};

#endif /* ConidiumDanceGravity_h */
