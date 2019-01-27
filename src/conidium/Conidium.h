//
//  Conidium.hpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#ifndef Conidium_h
#define Conidium_h

#include "ofMain.h"
#include "Ink.h"
#include "IDrawable.h"
#include "ConidiumDance.h"
#include "DistortedCircle.h"
#include "Settings.h"

class Conidium : public IDrawable {
private:
  ConidiumDance *dance;
  ConidiumSettings settings;
  ofVec2f speed;
  ofVec3f pos;
  float size;
  int lifespan;
  float angle;
  
  void updateCursor();
  void updatePosition() {this->pos += this->speed; }
  void growOlder() {this->lifespan--;}

public:
  Conidium(ofVec3f pos, float speed, const ConidiumSettings settings, ConidiumDance *dance);
  bool isAlive() {return this->lifespan > 0;}

  // IDrawable
  void update();
  void draw();
  float getWidth() {return this->size;}
  float getHeight() {return this->size;}
};

#endif /* Conidium_h */
