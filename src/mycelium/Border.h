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
  float radius;
  std::vector<float> radiuses;
  
  void generateRadiuses(float distortion);
  float calcRadiusForAngle(float angle, float distortion, float seed) const;
public:
  Border(float radius, int resolution, float distortion);
  float getRatio(float angle) const;
  float getRadius(float angle) const {getRatio(angle)*radius;}
  void draw() const;
  
};

#endif /* Border_h */
