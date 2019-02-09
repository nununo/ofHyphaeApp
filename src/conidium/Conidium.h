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
#include "ConidiumDance.h"
#include "Settings.h"

class Conidium {
private:
  ConidiumDance *dance;
  ConidiumSettings settings;
  ofVec2f speed;
  ofVec3f pos;
  int lifespan;
  float angle;
  int sleepFrames;
  

  void updateCursor();
  void updatePosition() {this->pos += this->speed; }
  void growOlder();
  bool isStillSleeping() {return sleepFrames>0;}

public:
  Conidium(ofVec3f pos, float speed, const ConidiumSettings settings, Ink *ink);
  ~Conidium();
  bool isAlive() {return lifespan > 0;}
  void update();
  void draw();
};

#endif /* Conidium_h */
