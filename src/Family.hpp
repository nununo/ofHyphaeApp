//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Family_hpp
#define Family_hpp

#include <list>
#include "ofMain.h"
#include "Element.hpp"
#include "IDrawable.h"
#include "Perimeter.hpp"
#include "NewElementEvent.h"

class Family : public IDrawable {

private:
  ofVec2f pos;
  std::list<Element> elements;
  ofFbo fbo;
  int lifespan;
  int elementLifespan;
  Perimeter *perimeter;
  
  void addElement(ofVec3f pos);
  void grow();
  void createElements();
  void destroyDeadElements();
  void updateFBO();

public:
  Family(ofVec3f pos, int size, float growthSpeed, int lifespan, int elementLifespan, float elementDistance);
  ~Family();

  void onNewElementEvent(NewElementEvent &e);
  
  // IDrawable
  void update();
  void draw();
  float getWidth() {return fbo.getWidth();}
  float getHeight() {return fbo.getHeight();}
  bool isAlive() {return this->lifespan > 0;}
};

#endif /* Family_hpp */
