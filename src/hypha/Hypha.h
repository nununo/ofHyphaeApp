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
  Border *border;
  int generation;
  ofVec2f noiseOffset;

  ofVec2f position;
  ofVec2f velocity;
  float angle = 0;
  bool started = false;

  ofVec2f delta = ofVec2f::zero();
  bool posIsNewPixel = false;

  int energy;
  int nextForkDistance;
  int forkCount = 0;
  bool dying = false;

  ofVec2f getInitialVelocity(const ofVec2f dir) const;
  void updateDirection();
  void calcNextForkDistance();
  void fork();
  bool isOutsideBorder();
  
  void throwForkEvent();

public:
  Hypha(const ofVec2f pos, const ofVec2f dir, Border *border, const HyphaParams params, const int generation);
  bool isAlive() const {return energy>0;}
  void update();
  void draw();
  void die(int energy) {this->dying=true; this->energy = energy;}

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<ofEventArgs> outsideEvent;
};

#endif /* Hypha_h */
