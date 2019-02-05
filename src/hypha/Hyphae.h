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
  std::list<Hypha> elements;
  HyphaeSettings settings;
  int zeroHyphaCount = 0;
  
  void add(Hypha *hypha);
  void addPrimalHypha(float inclination);
  ofVec3f calcDirection(float angle, float inclination);
  void generateZeroHypha();
  void removeAllDeadHypha();
  void removeOlderHyphaIfOverpopulated();
  void updateAllHypha();

public:
  Hyphae(Ink *ink, const HyphaeSettings settings); 
  void update();
  void draw();

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaDie(HyphaDieEventArgs &e);

  ofEvent<HyphaDieEventArgs> hyphaDieEvent;
};

#endif /* Hyphae_h */
