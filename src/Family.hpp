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
#include "VboElement.hpp"
#include "IDrawable.h"

class Family : public IDrawable {

private:
  ofVec2f pos;
  std::list<VboElement> vboElements;

public:
  Family(ofVec2f pos, int size);
  void update();
  void draw();
  float getWidth() {return 0;}
  float getHeight() {return 0;}
};

#endif /* Family_hpp */
