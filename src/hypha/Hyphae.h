//
//  Hyphae.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"

class Hyphae {
private:
  Ink *ink;
  DistortedCircle *dc;
  std::list<Hypha> elements;
  HyphaeSettings settings;
  int zeroHyphaCount = 0;
  
  void add(Hypha *hypha);
  void addGeneration0(float inclination);
  ofVec3f calcDirection(float angle, float inclination);
  void generateZeroHypha();
  void removeAllDeadHypha();
  void removeOlderHyphaIfOverpopulated();
  void updateAllHypha();

public:
  Hyphae(Ink *ink, const HyphaeSettings settings, DistortedCircle *dc); 
  void update();
  void draw();

  void onHyphaFork(HyphaForkEventArgs &e);
};

#endif /* Hyphae_h */
