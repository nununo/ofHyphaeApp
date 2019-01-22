//
//  Hole.hpp
//  moldApp
//
//  Created by Nuno on 22/01/2019.
//

#ifndef Hole_h
#define Hole_h

#include "ofMain.h"

enum HoleState {Invalid, Empty, Filled};

class Hole {
  ofVec2f position = ofVec2f(0,0);
  HoleState state = Invalid;
public:
  ofVec2f setPosition(ofVec2f p, HoleState s) {this->position=p;this->state=s;}
  ofVec2f getPosition() {return position;}
  void setEmpty() {this->state = Empty};
  bool fill() 
};

#endif /* Hole_h */
