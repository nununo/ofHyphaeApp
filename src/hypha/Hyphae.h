//
//  Hyphae.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"
#include "Border.h"
#include "HyphaeStats.h"

class Hyphae {
private:
  HyphaeParams params;
  unique_ptr<Border> border;
  int primalHyphaCount;
  std::list<Hypha> elements;
  bool sterile;
  
  void add(ofVec2f pos, ofVec2f dir, int generation);
  void generatePrimalHyphas();
  void removeAllHypha(bool onlyDead);
  void sterilizeIfFull();
  void updateAllHypha();

public:
  Hyphae(const HyphaeParams params);
  ~Hyphae();
  void update();
  void draw();
  int count() const {return elements.size();}
  int primalCount() const {return primalHyphaCount;}
  bool isAlive() const {return count() > 0;}
  HyphaeParams getParams() const {return params;}
  HyphaeStats getStats() const;
  void drawBorder() const;

  void onHyphaFork(HyphaForkEventArgs &e);
};

#endif /* Hyphae_h */
