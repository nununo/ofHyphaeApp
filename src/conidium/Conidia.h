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
#include "Perimeter.h"

class Conidia {
private:
  std::list<Conidium> elements;
  ISpeciesFactory *speciesFactory;
  ConidiaSettings settings;
  Perimeter *perimeter;

public:
  Conidia(ISpeciesFactory *speciesFactory, const ConidiaSettings settings, DistortedCircle *dc);
  ~Conidia();
  void add(ofVec3f p);
  void update();
  void draw();

  void onEmptyHoleReachedEvent(EmptyHoleReachedEventArgs &e);
};

#endif /* Conidia_h */
