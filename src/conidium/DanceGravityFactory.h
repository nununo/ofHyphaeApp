//
//  DanceGravityFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef DanceGravityFactory_h
#define DanceGravityFactory_h

#include "DanceGravity.h"

class DanceGravityFactory: public IDanceFactory {
private:
  Ink *ink;

public:
  DanceGravityFactory(Ink *ink) {this->ink = ink;}
  Dance *getInstance(ofVec2f pos) {return new DanceGravity(this->ink, pos);}
};

#endif /* DanceGravityFactory_h */
