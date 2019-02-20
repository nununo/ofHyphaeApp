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
#include "MyceliumParams.h"

#define BORDER_ANGLE_RESOLUTION 10

class Border {
private:
  BorderParams params;
  std::vector<float> radiuses;
  
  void generateRadiuses();
  float calcRadiusForAngle(float angle, float seed) const;
public:
  Border(const BorderParams params);
  float getRatio(float angle) const;
  float getRadius(float angle) const {return getRatio(angle)*params.radius;}
  void draw() const;
  
};

#endif /* Border_h */
