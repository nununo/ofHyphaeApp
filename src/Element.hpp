//
//  Element.hpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#ifndef Element_hpp
#define Element_hpp

#include "ofMain.h"
#include "Ink.hpp"

class Element {
private:
  Ink *ink;
  ofVec2f pos;
  float size;
  ofFbo fbo;
  ofVec2f cursor;
  
public:
  Element(Ink *ink, ofVec2f pos, float size);
  void update();
  void draw();
};

#endif /* Element_hpp */
