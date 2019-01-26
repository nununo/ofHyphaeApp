//
//  IDanceFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef IDanceFactory_h
#define IDanceFactory_h

#include "Dance.h"

class IDanceFactory {
public:
  virtual Dance *getInstance(ofVec2f pos) = 0;
};

#endif /* IDanceFactory_h */
