//
//  Sockets.cpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#include "Sockets.h"
#include "ofMain.h"

Sockets::Sockets(float distance) {
  this->distance = distance;
  initialize();
}

void Sockets::initialize() {
  for (int i=0;i<SOCKETS_MAX_DISTANCE;i++) {
    for (int j=0;j<360;j++) {
      if (i != 0 && (j == 0 || j % getAngularDistance(i) == 0)) {
        states[i][j] = Empty;
      } else {
        states[i][j] = Invalid;
      }
    }
  }
}

int Sockets::getAngularDistance(int i) {
  float circlePerimeter = 2 * PI * this->distance * i;
  return (int)(360 * this->distance / circlePerimeter + 0.5f);
}

SocketState Sockets::getState(float r, int angle) {
  int i = getIndex(r);
  if (i<SOCKETS_MAX_DISTANCE) {
    return states[i][angle];
  } else {
    return Invalid;
  }
}

int Sockets::fillState(float r, int angle) {
  int i = getIndex(r);
  if (states[i][angle] == Empty) {
    states[i][angle] = Filled;
    return 0;
  } else {
    return 1;
  }
}
