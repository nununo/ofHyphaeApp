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

struct MyceliumStats {
  int hyphaCount = 0;
  int conidiumCount = 0;
};

class Mycelium {

private:
  ofVec2f pos;
  float radius;
  MyceliumSettings settings;
  Conidia *conidia;
  Hyphae *hyphae;
  int lifespan;
  
  void growOlder() {lifespan--;}

public:
  Mycelium(ofVec3f pos, const MyceliumSettings settings, Ink *conidiaInk);
  ~Mycelium();
  
  void update();
  void drawConidia() const;
  void drawHyphae() const;
  bool isAlive() const {return this->lifespan > 0;}
  MyceliumStats getStats();

  void onHyphaDie(HyphaDieEventArgs &e);
};

#endif /* Mycelium_h */
