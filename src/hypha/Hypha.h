//
//  Hypha.h
//  hyphaeApp
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
  float baseSpeed;

  ofVec2f pos;
  ofVec2f velocity;
  float angle;
  //bool started = false;

  ofVec2f delta = ofVec2f::zero();
  bool posIsNewPixel = false;
  int velocityAge = 0;
  int checkBorderAge = 0;

  int energy = 999999;
  int nextForkDistance = 0;
  int forkCount = 0;
  bool dying = false;

  ofVec2f calcVelocity() const;
  void updateDirectionAndVelocity();
  void calcNextForkDistance();
  void fork();
  void checkBorder();
  void checkFork();
  
  void throwForkEvent();

public:
  Hypha(const ofVec2f pos, const float angle, Border *border, const HyphaParams params, const int generation);
  bool isAlive() const {return energy>0;}
  void update();
  void die(int energy) {this->dying=true; this->energy = energy;}
  ofVec2f getPosition() const {return pos;}
  bool isNewPixel() {return posIsNewPixel;}
  void resetNewPixel() {posIsNewPixel=false;}

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<ofEventArgs> outsideEvent;
};

#endif /* Hypha_h */
