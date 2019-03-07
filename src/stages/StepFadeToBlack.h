//
//  StepFadeToBlack.h
//  hyphaeApp
//
//  Created by Nuno on 03/03/2019.
//

#ifndef StepFadeToBlack2_h
#define StepFadeToBlack2_h

#include "StepCountdown.h"

class StepFadeToBlack: public StepCountdown {
private:
  int period;
  int alpha=0;
  
public:
  StepFadeToBlack(int count): StepCountdown(count) {}
  void draw() override;
};

#endif /* StepFadeToBlack2_h */
