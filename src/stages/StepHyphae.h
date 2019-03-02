//
//  StepHyphae.h
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef StepHyphae_h
#define StepHyphae_h

#include "IStep.h"
#include "Hyphae.h"

class StepHyphae: public IStep {
private:
  Hyphae *hyphae;

public:
  StepHyphae(Hyphae *hyphae) {this->hyphae = hyphae;}
  void update() {hyphae->update();}
  void draw() {hyphae->draw();}
  bool isAlive() {return hyphae->isAlive();}
};
#endif /* StepHyphae_h */
