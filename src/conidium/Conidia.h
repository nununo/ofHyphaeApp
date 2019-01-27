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
#include "Settings.h"

class Conidia {
private:
  std::list<Conidium> elements;
  ISpeciesFactory *speciesFactory;
  ConidiaSettings settings;

public:
  Conidia(ISpeciesFactory *speciesFactory, const ConidiaSettings settings);
  ~Conidia();
  void add(ofVec3f p);
  void update();
  void draw();
};

#endif /* Conidia_h */
