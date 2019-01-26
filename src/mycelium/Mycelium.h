//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Mycelium_h
#define Mycelium_h

#include <list>
#include "ofMain.h"
#include "Conidium.h"
#include "Hypha.h"
#include "Perimeter.h"
#include "NewConidiumEvent.h"
#include "IDanceFactory.h"

class Mycelium : public IDrawable {

private:
  ofVec2f pos;
  std::list<Conidium> conidia;
  std::list<Hypha> hyphae;
  int lifespan;
  int conidiumLifespan;
  Perimeter *perimeter;
  IDanceFactory *danceFactory;
  
  void addConidium(ofVec3f pos);
  void addHypha();
  void grow();
  void destroyDeadElements();

public:
  Mycelium(ofVec3f pos, int size, float growthSpeed, int lifespan,
         int elementLifespan, float elementDistance,
         float perimeterDistortion,
         IDanceFactory *danceFactory);
  ~Mycelium();

  void onNewElementEvent(NewConidiumEvent &e);
  
  // IDrawable
  void update();
  void draw();
  float getWidth() {return 0;}
  float getHeight() {return 0;}
  bool isAlive() {return this->lifespan > 0;}
};

#endif /* Mycelium_h */
