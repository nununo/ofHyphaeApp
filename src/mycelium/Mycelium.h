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
#include "Perimeter.h"
#include "Hyphae.h"
#include "Settings.h"

class Mycelium : public IDrawable {

private:
  ofVec2f pos;
  MyceliumSettings settings;
  Conidia *conidia;
  Perimeter *perimeter;
  Hyphae *hyphae;
  int lifespan;
  
  void growOlder() {lifespan--;}

public:
  Mycelium(ofVec3f pos, const MyceliumSettings settings, ISpeciesFactory *danceFactory);
  ~Mycelium();
  
  // IDrawable
  void update();
  void draw();
  float getWidth() {return 0;}
  float getHeight() {return 0;}
  bool isAlive() {return this->lifespan > 0;}

  void onEmptyHoleReachedEvent(EmptyHoleReachedEventArgs &e);
  void onHyphaDie(HyphaDieEventArgs &e);

};

#endif /* Mycelium_h */
