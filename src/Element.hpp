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
#include "IDrawable.h"

class Element : IDrawable {
private:
  Ink *ink;
  ofVec2f pos;
  ofFbo fbo;
  ofVec2f cursor;
  
public:
  Element(Ink *ink, ofVec2f pos, float size);
  void update();
  void draw();
  float getWidth() {return fbo.getWidth();}
  float getHeight() {return fbo.getHeight();}
};

#endif /* Element_hpp */
