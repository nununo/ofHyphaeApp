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
  Ink *ink;
  ofVec2f pos;
  std::list<Element> elements;
  ofFbo fbo;

public:
  Family(Ink *ink, ofVec2f pos, int size);
  void update();
  void draw();
  float getWidth() {return fbo.getWidth();}
  float getHeight() {return fbo.getHeight();}
};

#endif /* Family_hpp */
