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
#include "Rings.h"
#include "NewConidiumEvent.h"

class Perimeter {
  
private:
  DistortedCircle *dc;
  Rings *rings;
  float space;
  float growthSpeed;
  float cursors[360];

  void drawCursor();

public:
  Perimeter(float growthSpeed, float space, float distortion);
  ~Perimeter();
  void update();
  void draw();
  
  ofEvent<NewConidiumEvent> newConidiumEvent;
};

#endif /* Perimeter_hpp */
