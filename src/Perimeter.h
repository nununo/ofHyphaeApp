//
//  Perimeter.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Perimeter_hpp
#define Perimeter_hpp

#include "ofMain.h"
#include "DistortedCircle.h"
#include "Sockets.h"
#include "NewElementEvent.h"

class Perimeter {
  
private:
  DistortedCircle *dc;
  Sockets *sockets;
  float elementDistance;
  float growthSpeed;
  float cursors[360];

  void drawCursor();

public:
  Perimeter(float growthSpeed, float elementDistance);
  ~Perimeter();
  void update();
  void draw();
  
  ofEvent<NewElementEvent> newElementEvent;
};

#endif /* Perimeter_hpp */
