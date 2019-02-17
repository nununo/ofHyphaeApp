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
#include "HyphaDieEventArgs.h"
#include "Settings.h"

class Hypha {
private:
  HyphaSettings settings;
  int generation;
  float radius;
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
  float calcDeathRadius();
  
  ofVec3f getInitialVelocity(const ofVec2f dir) const;
  void throwForkEvent();
  void throwDieEvent();

public:
  Hypha(const ofVec2f pos, const ofVec2f dir, float radius, const HyphaSettings settings, const int generation=0);
  bool isAlive() const {return !dead;}
  void update();
  void draw();
  void die();

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaDieEventArgs> dieEvent;
};

#endif /* Hypha_h */
