//
//  SpeciesRandomFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef SpeciesRandomFactory_h
#define SpeciesRandomFactory_h

#include "ConidiumRandomDance.h"

class SpeciesRandomFactory: public ISpeciesFactory {
private:
  Ink *ink;
public:
  SpeciesRandomFactory(Ink *ink) {this->ink = ink;}
  ConidiumDance *getConidiumDanceInstance(ofVec2f pos) {return new ConidiumRandomDance(this->ink);}
};

#endif /* SpeciesRandomFactory_h */
