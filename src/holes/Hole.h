//
//  Hole.hpp
//  moldApp
//
//  Created by Nuno on 22/01/2019.
//

#ifndef Hole_h
#define Hole_h

#include "ofMain.h"
#include "HoleFilledEventArgs.h"

enum HoleState {Invalid, Empty, Filled};

class Hole {
private:
  ofVec2f position;
  HoleState state;
  
  void throwHoleFilledEvent();
  
public:
  Hole() {position=ofVec2f(0,0); state = Invalid;}
  ofVec2f setPosition(ofVec2f p) {this->position=p; this->state=Empty;}
  ofVec2f getPosition() {return position;}
  HoleState getState() {return state;}
  bool fill();
  
  ofEvent<HoleFilledEventArgs> holeFilledEvent;
};

#endif /* Hole_h */
