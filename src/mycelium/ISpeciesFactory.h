//
//  IDanceFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef IDanceFactory_h
#define IDanceFactory_h

#include "ConidiumDance.h"

class ISpeciesFactory {
public:
  virtual ConidiumDance *getConidiumDanceInstance(ofVec2f pos) = 0;
};

#endif /* IDanceFactory_h */
