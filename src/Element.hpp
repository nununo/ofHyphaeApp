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
  ofVec3f dir;
  ofVec3f pos;
  float size;
  ofVec2f cursor;
  int lifespan;
  
  void grow() {this->lifespan--;}
  void updateCursor();
  void updatePosition() {pos += dir; }

public:
  Element(Ink *ink, ofVec3f pos, int lifespan);

  // IDrawable
  void update();
  void draw();
  float getWidth() {return this->size;}
  float getHeight() {return this->size;}
  bool isAlive() {return this->lifespan > 0;}
};

#endif /* Element_hpp */
