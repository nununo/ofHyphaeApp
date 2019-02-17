//
//  Border.h
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#ifndef Border_h
#define Border_h

#include <vector>
#include "Settings.h"

class Border {
private:
  BorderSettings settings;
  float radius;
  std::vector<float> radiuses;
  
  void generateRadiuses();
  float calcRadiusForAngle(float angle, float seed) const;
public:
  Border(BorderSettings settings);
  float getRatio(float angle) const;
  float getRadius(float angle) const {return getRatio(angle)*radius;}
  void draw() const;
  
};

#endif /* Border_h */
