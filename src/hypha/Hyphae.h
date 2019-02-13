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
  HyphaeSettings settings;
  float radius;
  std::list<Hypha> elements;
  
  void add(Hypha *hypha);
  void generatePrimalHyphas();
  void removeAllDeadHypha();
  void removeOlderHyphaIfOverpopulated();
  void updateAllHypha();

public:
  Hyphae(const HyphaeSettings settings, float radius);
  void update();
  void draw();
  int count() const {return elements.size();}
  bool isAlive() const {return count() > 0;}

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaDie(HyphaDieEventArgs &e);

  ofEvent<HyphaDieEventArgs> hyphaDieEvent;
};

#endif /* Hyphae_h */
