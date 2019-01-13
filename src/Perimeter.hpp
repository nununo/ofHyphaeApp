//
//  Perimeter.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Perimeter_hpp
#define Perimeter_hpp

#include "ofMain.h"

class Perimeter {
  
private:
  float points[360];

public:
  Perimeter();
  void set(float angle, float v);
  float get(float angle);
  void draw();
};

#endif /* Perimeter_hpp */
