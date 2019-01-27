//
//  HyphaForkEvent.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef HyphaForkEvent_h
#define HyphaForkEvent_h

#include "ofMain.h"

class HyphaForkEvent : public ofEventArgs {
  
public:
  ofVec3f pos;
  
  ofEvent<HyphaForkEvent> events;
};

#endif /* HyphaForkEvent_h */
