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

class Element : public IDrawable {
private:
  Ink *ink;
  ofVec2f dir;
  ofVec2f pos;
  float size = ofGetHeight()/2;
  ofVec2f cursor;

public:
  Element(Ink *ink, ofVec2f pos);
  void update();
  void draw();
  float getWidth() {return size;}
  float getHeight() {return size;}
};

#endif /* Element_hpp */
