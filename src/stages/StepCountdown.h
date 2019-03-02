//
//  StepCountdown.h
//  moldApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef StepCountdown_h
#define StepCountdown_h

#include "IStep.h"

class StepCountdown: public IStep {
private:
  int count = 0;
  int period = 0;
  
protected:
  int getCount() const {return count;}
  int getPeriod() const {return period;}

public:
  StepCountdown(int count, int period) {this->count = count;this->period = period;}
  void update() {count--;}
  void draw() {}
  bool isAlive() {return count>0;}
};

/*
if (--mourningFrames <= 0) {
  lifecycleStep = fadeout;
  fadeoutFramesPeriod = (int)(settings->canvas.fadeoutTime * settings->canvas.framerate / 256);
  if (fadeoutFramesPeriod==0) {
    fadeoutFramesPeriod = 1;
  }
  fadeoutFrames = settings->canvas.fadeoutTime * settings->canvas.framerate;
  if (fadeoutFrames<256) {
    fadeoutFrames = 256;
  }
}
*/
#endif /* StepCountdown_h */

