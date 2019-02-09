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
  Ink *ink;
  HyphaSettings settings;
  ofVec2f noiseOffset;
  int generation;

  ofVec3f pos;
  ofVec3f vel;
  ofVec3f lastIntPos;
  bool posIsNewPixel;
  int lifespan;
  int nextForkDistance;
  int forkCount;
  bool dead;

  void growOlder();
  void updateVelocity();
  float getFertilityRate() const;
  void calcNextForkDistance();
  void fork();
  void drawZ() const;
  
  ofVec3f getInitialVelocity(const ofVec3f dir) const;
  void throwForkEvent();
  void throwDieEvent();

public:
  Hypha(const ofVec3f pos, Ink *ink, const ofVec3f dir, const HyphaSettings settings, const int generation=0);
  bool isAlive() const {return !dead;}
  void update();
  void draw();
  void die() {this->lifespan=1; growOlder();}

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaDieEventArgs> dieEvent;
};

#endif /* Hypha_h */
