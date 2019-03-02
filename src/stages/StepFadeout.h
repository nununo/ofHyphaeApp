//
//  StepFadeout.h
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef StepFadeout_h
#define StepFadeout_h

#include "StepCountdown.h"
#include "ofMain.h"

class StepFadeout: public StepCountdown {
private:
  int period;
  ofColor color;
  
public:
  StepFadeout(ofColor color, int count, int steps);
  void draw() override;
};

#endif /* StepFadeout_h */
