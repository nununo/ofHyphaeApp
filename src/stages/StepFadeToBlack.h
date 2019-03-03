//
//  StepFadeout.h
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef StepFadeToBlack_h
#define StepFadeToBlack_h

#include "StepCountdown.h"
#include "ofMain.h"

class StepFadeToBlack: public StepCountdown {
private:
  int period;
  ofShader shader;
  ofTexture screenTexture;
  
public:
  StepFadeToBlack(int count);
  void draw() override;
};

#endif /* StepFadeToBlack_h */
