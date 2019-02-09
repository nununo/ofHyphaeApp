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
  
  void add(Hypha *hypha);
  ofVec3f calcDirection(const float angle, const float inclination) const;
  void generatePrimalHyphas();
  void removeAllDeadHypha();
  void removeOlderHyphaIfOverpopulated();
  void updateAllHypha();

public:
  Hyphae(const HyphaeSettings settings);
  ~Hyphae();
  void update();
  void draw();
  int count() const {return elements.size();}
  bool isAlive() const {return count() > 0;}

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaDie(HyphaDieEventArgs &e);

  ofEvent<HyphaDieEventArgs> hyphaDieEvent;
};

#endif /* Hyphae_h */
