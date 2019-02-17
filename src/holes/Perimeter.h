//
//  Perimeter.hpp
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Perimeter_hpp
#define Perimeter_hpp

#include "ofMain.h"
#include "Rings.h"
#include "EmptyHoleReachedEventArgs.h"
#include "Settings.h"

class Perimeter {
  
private:
  HolesSettings settings;
  Rings *rings;
  std::array<float, 360> cursors;

  void drawCursor();

public:
  Perimeter(HolesSettings settings);
  ~Perimeter();
  void update(ofVec2f pos);
  void draw();
  
  ofEvent<EmptyHoleReachedEventArgs> emptyHoleReachedEvent;
};

#endif /* Perimeter_hpp */
