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
#include "EmptyHoleReachedEventArgs.h"
#include "Settings.h"

class Perimeter {
  
private:
  DistortedCircle *dc;
  ConidiaSettings settings;
  Rings *rings;
  float cursors[360];

  void drawCursor();

public:
  Perimeter(ConidiaSettings settings, DistortedCircle *dc);
  ~Perimeter();
  void update();
  void draw();
  
  ofEvent<EmptyHoleReachedEventArgs> emptyHoleReachedEvent;
};

#endif /* Perimeter_hpp */
