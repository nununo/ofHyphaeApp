//
//  Hyphae.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Hyphae_h
#define Hyphae_h

#include "Ink.h"
#include "Hypha.h"
#include "Settings.h"

class Hyphae {
private:
  Ink *ink;
  std::list<Hypha> elements;
  HyphaeSettings settings;
  
  void addAtPosition(ofVec2f pos, ofVec2f vel, int generation);
  void addGeneration0(ofVec2f vel);

public:
  Hyphae(Ink *ink, const HyphaeSettings settings); 
  void update();
  void draw();

  void onHyphaFork(HyphaForkEventArgs &e);
};

#endif /* Hyphae_h */
