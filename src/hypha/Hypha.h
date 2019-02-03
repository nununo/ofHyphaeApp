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
  Ink *ink;
  HyphaSettings settings;
  ofVec2f noiseOffset;

  ofVec3f pos;
  ofVec3f vel;
  ofVec3f lastIntPos;
  bool posIsNewPixel;

  int lifespan;
  int nextForkDistance;
  int generation;
  int forkCount;
  
  void updateVelocity();
  float getFertilityRate();
  void calcNextForkDistance();
  void fork();
  void drawZ();
  
  ofVec3f getInitialVelocity(ofVec3f dir);
  ofVec3f calcVelocity(float speed, float angle, float inclination);

public:
  Hypha(ofVec3f pos, Ink *ink, ofVec3f dir, const HyphaSettings settings, int generation=0);
  bool isAlive() {return (lifespan>0 && pos.z<settings.maxHeight);}
  void update();
  void draw();
  void die() {this->lifespan=0;}

  ofEvent<HyphaForkEventArgs> forkEvent;
};

#endif /* Hypha_h */
