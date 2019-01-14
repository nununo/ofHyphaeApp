//
//  NewElementEvent.h
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef NewElementEvent_h
#define NewElementEvent_h

#include "ofMain.h"

class NewElementEvent : public ofEventArgs {
  
public:
  ofVec3f pos;
  
  static ofEvent <NewElementEvent> events;
};

#endif /* NewElementEvent_h */
