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
  int primalHyphaCount = 0;
  
  void add(Hypha *hypha);
  void addPrimalHypha(const float inclination);
  ofVec3f calcDirection(const float angle, const float inclination) const;
  void generatePrimalHypha();
  void removeAllDeadHypha();
  void removeOlderHyphaIfOverpopulated();
  void updateAllHypha();

public:
  Hyphae(const HyphaeSettings settings);
  ~Hyphae();
  void update();
  void draw();
  bool isAlive() const {return elements.size() > 0;}

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaDie(HyphaDieEventArgs &e);

  ofEvent<HyphaDieEventArgs> hyphaDieEvent;
};

#endif /* Hyphae_h */
