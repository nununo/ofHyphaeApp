//
//  NewConidiumEvent.h
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef NewConidiumEvent_h
#define NewConidiumEvent_h

#include "ofMain.h"

class NewConidiumEvent : public ofEventArgs {
  
public:
  ofVec3f pos;
  
  ofEvent<NewConidiumEvent> events;
};

#endif /* NewConidiumEvent_h */
