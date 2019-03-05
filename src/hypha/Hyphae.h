//
//  Hyphae.h
//  hyphaeApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Hypha.h"
#include "Border.h"
#include "HyphaeStats.h"
#include "Painter.h"

class Hyphae {
private:
  HyphaeParams params;
  std::list<Hypha> elements;
  unique_ptr<Border> border;
  unique_ptr<Painter> painter;

  int startFrameNum = 0;
  int primalHyphaCount = 0;
  int outsideCount = 0;
  bool sterile = false;
  bool dying = false;
  bool wasAlive = false;

  
  void add(ofVec2f pos, ofVec2f dir, int generation);
  void generatePrimalHyphas();
  void updateLifecycle();
  int count() const {return elements.size();}
  int primalCount() const {return primalHyphaCount;}
  void removeAllHypha();

public:
  Hyphae(const HyphaeParams params, ofColor backgroundColor);
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
