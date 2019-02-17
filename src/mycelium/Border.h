//
//  Border.h
//  moldApp
//
//  Created by Nuno on 17/02/2019.
//

#ifndef Border_h
#define Border_h

#include <vector>

class Border {
private:
  int resolution;
  std::vector<float> radiuses;
  
  void generateRadiuses(float distortion);
  float calcRadiusForAngle(float angle, float distortion, float seed) const;
public:
  Border(int resolution, float distortion);
  float getRadius(float angle) const;
  void draw(float radius) const;
  
};

#endif /* Border_h */
