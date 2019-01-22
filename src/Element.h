//
//  Element.hpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#ifndef Element_hpp
#define Element_hpp

#include "ofMain.h"
#include "Ink.h"
#include "IDrawable.h"
#include "DistortedCircle.h"

class Element : public IDrawable {
private:
  Ink *ink;
  ofVec2f speed;
  ofVec3f pos;
  float size;
  ofVec2f cursor;
  int lifespan;
  
  void grow() {this->lifespan--;}
  void updateCursor();
  void updatePosition() {pos += this->speed; }

public:
  Element(Ink *ink, ofVec3f pos, float speed, int lifespan);
  bool isAlive() {return this->lifespan > 0;}
  void kill() {this->lifespan = 0;}

  // IDrawable
  void update();
  void draw();
  float getWidth() {return this->size;}
  float getHeight() {return this->size;}
};

#endif /* Element_hpp */
