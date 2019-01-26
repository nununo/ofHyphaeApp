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
#include "Dance.h"
#include "DistortedCircle.h"

class Element : public IDrawable {
private:
  Dance *dance;
  ofVec2f speed;
  ofVec3f pos;
  float size;
  int lifespan;
  float angle;
  
  void updateCursor();
  void updatePosition() {this->pos += this->speed; }
  void growOlder() {this->lifespan--;}

public:
  Element(ofVec3f pos, float speed, int lifespan, Dance *dance);
  bool isAlive() {return this->lifespan > 0;}
  void kill() {this->lifespan = 0;}

  // IDrawable
  void update();
  void draw();
  float getWidth() {return this->size;}
  float getHeight() {return this->size;}
};

#endif /* Element_hpp */
