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

  int startFrameNum = 0;    // Frame number at birth
  int primalHyphaCount = 0; // Primal Hypha
  int outsideCount = 0;     // Number of hypha outside border
  int dyingCount = 0;       // Hypha count when dying starts
  bool sterile = false;     // Sterile Hyphae cannot create more Hypha
  bool dying = false;       // Is in a dying process
  bool wasAlive = false;    // To return isAlive()=true when no Hypha was created yet

  
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
