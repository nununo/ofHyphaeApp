//
//  EmptyHoleReachedEvent.h
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef EmptyHoleReachedEvent_h
#define EmptyHoleReachedEvent_h

#include "ofMain.h"

class EmptyHoleReachedEvent : public ofEventArgs {
  
public:
  ofVec3f pos;
  
  //ofEvent<EmptyHoleReachedEvent> events;
};

#endif /* EmptyHoleReachedEvent_h */
