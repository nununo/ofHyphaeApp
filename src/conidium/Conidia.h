//
//  Conidia.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Conidia_h
#define Conidia_h

#include "Conidium.h"
#include "IDanceFactory.h"

class Conidia {
private:
  std::list<Conidium> elements;
  IDanceFactory *danceFactory;
  int conidiumLifespan;

public:
  Conidia(IDanceFactory *danceFactory, int conidiumLifespan);
  ~Conidia();
  void add(ofVec3f p);
  void update();
  void draw();
};

#endif /* Conidia_h */
