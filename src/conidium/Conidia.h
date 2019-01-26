//
//  Conidia.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Conidia_h
#define Conidia_h

#include "Conidium.h"
#include "ISpeciesFactory.h"

class Conidia {
private:
  std::list<Conidium> elements;
  ISpeciesFactory *speciesFactory;
  int conidiumLifespan;

public:
  Conidia(ISpeciesFactory *speciesFactory, int conidiumLifespan);
  ~Conidia();
  void add(ofVec3f p);
  void update();
  void draw();
};

#endif /* Conidia_h */
