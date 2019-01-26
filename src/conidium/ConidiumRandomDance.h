//
//  ConidiumRandomDance.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef ConidiumRandomDance_h
#define ConidiumRandomDance_h

#include "ConidiumDance.h"
#include "Ink.h"
#include "ofMain.h"

class ConidiumRandomDance : public ConidiumDance {
private:
  Ink *ink;
  ofVec2f cursor;

public:
  ConidiumRandomDance(Ink *ink) : ConidiumDance(ofVec2f(0,0)) {this->ink = ink;}
  void update();
  void draw();
};

#endif /* ConidiumRandomDance_h */
