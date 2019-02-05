//
//  SpeciesGravityFactory.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef SpeciesGravityFactory_h
#define SpeciesGravityFactory_h

#include "ConidiumGravityDance.h"
#include "ISpeciesFactory.h"

class SpeciesGravityFactory: public ISpeciesFactory {
private:
  Ink *ink;

public:
  SpeciesGravityFactory(Ink *ink) {this->ink = ink;}
  ConidiumDance *getConidiumDanceInstance(ofVec2f pos) {return new ConidiumGravityDance(this->ink, pos);}
};

#endif /* DanceGravityFactory_h */
