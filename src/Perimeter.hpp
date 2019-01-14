//
//  Perimeter.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Perimeter_hpp
#define Perimeter_hpp

#include "ofMain.h"
#include "DistortedCircle.hpp"
#include "Sockets.hpp"

class Perimeter {
  
private:
  DistortedCircle *dc;
  Sockets *sockets;
  float elementDistance;
  float growthSpeed;
  float cursors[360];

public:
  Perimeter(float growthSpeed, float elementDistance);
  ~Perimeter();
  void update();
  void draw();
};

#endif /* Perimeter_hpp */
