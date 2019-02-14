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
  int lifespan;
  int nextForkDistance;
  int forkCount;
  float nextDeathRadius;
  bool dead;

  void growOlder();
  void updateVelocity();
  float getFertilityRate() const;
  void calcNextForkDistance();
  void fork();
  float getAngle(ofVec2f p, ofVec2f d) const {return ofClamp(abs(pos.angle(vel)),0.0f,90.0f);} // absolute and clamped
  float getMaxLifespan(float angle) const {return ofLerp(1.0f, 0.01f, angle/90.0f)*settings.maxLifespan;}
  ofColor calcColor(float angle) const;
  float calcDeathRadius();
  
  ofVec3f getInitialVelocity(const ofVec2f dir) const;
  void throwForkEvent();
  void throwDieEvent();

public:
  Hypha(const ofVec2f pos, const ofVec2f dir, float radius, const HyphaSettings settings, const int generation=0);
  bool isAlive() const {return !dead;}
  void update();
  void draw();
  void die() {this->lifespan=1; growOlder();}

  ofEvent<HyphaForkEventArgs> forkEvent;
  ofEvent<HyphaDieEventArgs> dieEvent;
};

#endif /* Hypha_h */
