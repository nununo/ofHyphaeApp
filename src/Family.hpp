//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Family_hpp
#define Family_hpp

#include "ofMain.h"
#include <list>
#include "Element.hpp"
#include "IDrawable.h"

class Family : public IDrawable {

private:
  ofVec2f pos;
  std::list<Element> elements;
  ofFbo fbo;
  float elementDistance;
  float radius;
  float growthSpeed;
  float lastElementRadius;

  void addElement(ofVec3f pos);
  float getElementAngleDistance();
  void grow();
  void createElements();

public:
  Family(ofVec3f pos, int size, float elementDistance);
  void update();
  void draw();
  float getWidth() {return fbo.getWidth();}
  float getHeight() {return fbo.getHeight();}
};

#endif /* Family_hpp */
