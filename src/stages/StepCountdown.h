//
//  StepCountdown.h
//  hyphaeApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef StepCountdown_h
#define StepCountdown_h

#include "IStep.h"

class StepCountdown: public IStep {
private:
  int count = 0;
  
protected:
  int getCount() const {return count;}

public:
  StepCountdown(int count) {this->count = count;}
  void update() {count--;}
  void draw() {}
  bool isAlive() {return count>0;}
};

#endif /* StepCountdown_h */

