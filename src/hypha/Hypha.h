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
#include "Settings.h"

class Hypha {
private:
  ofVec2f pos;
  Ink *ink;
  HyphaSettings settings;
  ofVec2f noiseOffset;
  ofVec2f vel;
  ofVec2f lastIntPos;
  bool posIsNewPixel;
  int lifespan;
  int nextForkDistance;
  int generation;
  
  void updateVelocity();
  void calcNextForkDistance();
  void fork();

public:
  Hypha(ofVec2f pos, Ink *ink, ofVec2f vel, const HyphaSettings settings, int generation=0);
  bool isAlive() {return this->lifespan>0;}
  void update();
  void draw();

  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
