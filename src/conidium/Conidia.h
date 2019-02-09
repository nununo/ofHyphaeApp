//
//  Conidia.h
//  moldApp
//
//  Created by Nuno on 26/01/2019.
//

#ifndef Conidia_h
#define Conidia_h

#include "Conidium.h"
#include "Settings.h"

class Conidia {
private:
  std::list<Conidium> elements;
  Ink *ink;
  ConidiaSettings settings;

public:
  Conidia(Ink *ink, const ConidiaSettings settings);
  ~Conidia();
  void add(ofVec3f p);
  void update();
  void draw();
  int count() const {return elements.size();}
};

#endif /* Conidia_h */
