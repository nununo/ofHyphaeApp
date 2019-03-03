//
//  HyphaForkEventArgs.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEventArgs_h
#define HyphaForkEventArgs_h

#include "ofMain.h"

class HyphaForkEventArgs : public ofEventArgs {
  
public:
  ofVec3f pos;
  ofVec3f dir;
  int generation;
};

#endif /* HyphaForkEventArgs_h */
