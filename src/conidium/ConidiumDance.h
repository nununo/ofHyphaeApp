//
//  ConidiumDance.h
//  moldApp
//
//  Created by Nuno on 24/01/2019.
//

#ifndef ConidiumDance_h
#define ConidiumDance_h

#include "ofMain.h"

class ConidiumDance {
private:
  ofVec2f pos;
  
protected:
  ofVec2f getPosition() {return this->pos;}

public:
  ConidiumDance(ofVec2f pos) {this->pos = pos;}
  virtual void update() = 0;
  virtual void draw() = 0;
};

#endif /* ConidiumDance_h */
