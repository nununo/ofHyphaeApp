//
//  Hypha.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hypha_h
#define Hypha_h

#include "ofMain.h"
#include "HyphaForkEventArgs.h"
#include "Settings.h"
#include "Border.h"

class Hypha {
private:
  HyphaParams params;
  int generation;
  Border *border;
  ofVec2f noiseOffset;

  ofVec2f position;
  ofVec2f delta;
  ofVec2f velocity;
  bool posIsNewPixel;
  int nextForkDistance;
  int forkCount;
  float deathRadius;
  bool dead;

  void growOlder();
  ofVec3f getInitialVelocity(const ofVec2f dir) const;
  void updateDirection();
  void calcNextForkDistance();
  void fork();
  float calcDeathRadius() const;
  
  void throwForkEvent();
  void throwDieEvent();
  void throwPositionEvent();

public:
  Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaParams params, const int generation=0);
  bool isAlive() const {return !dead;}
  void update();
  void draw();
  void die() {dead = true;}

  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
