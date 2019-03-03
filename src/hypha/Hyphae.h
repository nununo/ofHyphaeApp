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
  std::list<Hypha> elements;

  int primalHyphaCount = 0;
  bool sterile = false;
  bool dying = false;
  bool wasAlive = false;
  
  void add(ofVec2f pos, ofVec2f dir, int generation);
  void generatePrimalHyphas();
  void removeAllHypha();
  void updateLifecycle();
  int count() const {return elements.size();}
  int primalCount() const {return primalHyphaCount;}

public:
  Hyphae(const HyphaeParams params);
  ~Hyphae();

  virtual void update();
  virtual void draw();
  bool isAlive() {return !wasAlive || count()>0;}

  HyphaeParams getParams() const {return params;}
  HyphaeStats getStats() const;
  void drawBorder() const;

  void onHyphaFork(HyphaForkEventArgs &e);
  void onHyphaOutside(ofEventArgs &e);
};

#endif /* Hyphae_h */
