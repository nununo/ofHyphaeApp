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
  HyphaeParams params;
  Border *border;
  int newPrimalHyphaFramesPeriod;
  int primalHyphaCount;
  std::list<Hypha> elements;
  bool sterile;
  
  void add(Hypha *hypha);
  void generatePrimalHyphas();
  void removeAllDeadHypha();
  void sterilizeIfFull();
  void updateAllHypha();

public:
  Hyphae(const HyphaeParams params, Border *border);
  void update();
  void draw();
  int count() const {return elements.size();}
  bool isAlive() const {return count() > 0;}

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaPosition(PositionEventArgs &e);

  ofEvent<PositionEventArgs> hyphaPositionEvent;
};

#endif /* Hyphae_h */
