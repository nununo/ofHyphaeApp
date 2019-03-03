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
#include "Tools.h"

struct BorderPoint {
  float ratio=0;
  bool touched=false;
};

class Border {
private:
  BorderParams params;
  std::vector<BorderPoint> points;
  bool drawn = false;
  
  void generateRadiuses();
  float calcRatioForAngle(float angle) const;

public:
  Border(const BorderParams params);
  float getRatio(float angle) const {return points[Tools::angleToInt(angle)].ratio;};
  bool isOutside(ofVec2f pos);
  void draw();
  
};

#endif /* Border_h */
