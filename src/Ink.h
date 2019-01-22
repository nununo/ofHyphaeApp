//
//  Ink.h
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Ink_h
#define Ink_h

#include "ofMain.h"

class Ink {
private:
  int transparency;
  
public:
  Ink(int transparency){ this->transparency = transparency;}
  virtual ~Ink() {}
  int getTransparency() {return transparency;}

  virtual ofColor getColor(ofPoint position)=0;
};

#endif /* Ink_h */
