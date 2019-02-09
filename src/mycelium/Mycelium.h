//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Mycelium_h
#define Mycelium_h

#include "ofMain.h"
#include "Conidia.h"
#include "Hyphae.h"
#include "Settings.h"

class Mycelium {

private:
  ofVec2f pos;
  MyceliumSettings settings;
  Conidia *conidia;
  Hyphae *hyphae;
  int lifespan;
  
  void growOlder() {lifespan--;}

public:
  Mycelium(ofVec3f pos, const MyceliumSettings settings, Ink *conidiaInk);
  ~Mycelium();
  
  // IDrawable
  void update();
  void draw();
  bool isAlive() {return this->lifespan > 0;}

  void onHyphaDie(HyphaDieEventArgs &e);
};

#endif /* Mycelium_h */
