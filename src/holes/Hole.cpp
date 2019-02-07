//
//  Hole.cpp
//  moldApp
//
//  Created by Nuno on 22/01/2019.
//

#include "Hole.h"

bool Hole::fill() {
  if (this->state != Invalid) {
    this->state = this->state;
  }
  if (this->state == Empty) {
    this->state = Filled;
    return true;
  } else {
    return false;
  }
}
