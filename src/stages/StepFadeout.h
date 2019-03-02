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
  ofColor color;
  
public:
  StepFadeout(ofColor color, int count, int period) : StepCountdown(count,period) {this->color = color;}
  void draw() override;
};

#endif /* StepFadeout_h */
