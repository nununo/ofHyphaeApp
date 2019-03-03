//
//  StepFadeToWhite.h
//  hyphaeApp
//
//  Created by Nuno on 03/03/2019.
//

#ifndef StepFadeToWhite_h
#define StepFadeToWhite_h

#include "StepCountdown.h"

class StepFadeToWhite: public StepCountdown {
private:
  int period;
  
public:
  StepFadeToWhite(int count);
  void draw() override;
};

#endif /* StepFadeToWhite_h */
