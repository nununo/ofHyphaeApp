//
//  Hypha.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hypha_h
#define Hypha_h

#include "ofMain.h"
#include "Ink.h"
#include "HyphaForkEventArgs.h"
#include "PositionEventArgs.h"
#include "Settings.h"
#include "Border.h"

class Hypha {
private:
  HyphaSettings settings;
  int generation;
  Border *border;
  ofVec2f noiseOffset;
  ofColor color;

  ofVec2f pos;
  ofVec2f vel;
  ofVec2f lastIntPos;
  bool posIsNewPixel;
  int nextForkDistance;
  int forkCount;
  float deathRadius;
  bool dead;

  void growOlder();
  void updateVelocity();
  void calcNextForkDistance();
  void fork();
  float calcDeathRadius() const;
  
  ofVec3f getInitialVelocity(const ofVec2f dir) const;
  void throwForkEvent();
  void throwDieEvent();
  void throwPositionEvent();

public:
  Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaSettings settings, const int generation=0);
  bool isAlive() const {return !dead;}
  void update();
  void draw();
  void die();

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<PositionEventArgs> dieEvent;
  ofEvent<PositionEventArgs> positionEvent;
};

#endif /* Hypha_h */
