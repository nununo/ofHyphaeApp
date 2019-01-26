//
//  IDance.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef Dance_h
#define Dance_h

#include "ofMain.h"

class Dance {
private:
  ofVec2f pos;
  
protected:
  ofVec2f getPosition() {return this->pos;}

public:
  Dance(ofVec2f pos) {this->pos = pos;}
  virtual void update() = 0;
  virtual void draw() = 0;
};

#endif /* Dance_h */
