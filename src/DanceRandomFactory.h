//
//  DanceRandomFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef DanceRandomFactory_h
#define DanceRandomFactory_h

#include "DanceRandom.h"

class DanceRandomFactory: public IDanceFactory {
private:
  Ink *ink;
public:
  DanceRandomFactory(Ink *ink) {this->ink = ink;}
  Dance *getInstance(ofVec2f pos) {return new DanceRandom(this->ink);}
};

#endif /* DanceRandomFactory_h */
