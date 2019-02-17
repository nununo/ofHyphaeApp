//
//  Hole.cpp
//  moldApp
//
//  Created by Nuno on 22/01/2019.
//

#include "Hole.h"

bool Hole::fill() {
  if (this->state == Empty) {
    this->state = Filled;
    throwHoleFilledEvent();
    return true;
  } else {
    return false;
  }
}

void Hole::throwHoleFilledEvent() {
  HoleFilledEventArgs args;
  args.pos = this->position;
  ofNotifyEvent(this->holeFilledEvent, args);
}
