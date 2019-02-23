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
#include "HyphaeParams.h"

class Border {
private:
  BorderParams params;
  std::vector<float> radiuses;
  
  void generateRadiuses();
  float calcRatioForAngle(float angle) const;
public:
  Border(const BorderParams params);
  float getRatio(float angle) const;
  float getRadius(float angle) const {return getRatio(angle)*params.radius;}
  void draw() const;
  
};

#endif /* Border_h */
