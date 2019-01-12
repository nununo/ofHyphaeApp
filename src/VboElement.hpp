//
//  Element.hpp
//  moldApp
//
//  Created by Nuno on 10/01/2019.
//

#ifndef VboElement_hpp
#define VboElement_hpp

#include "ofMain.h"
#include "Ink.hpp"
#include "IDrawable.h"

class VboElement : public IDrawable {
private:
  Ink *ink;
  ofMesh mesh;
  ofVec2f pos;
  float size = ofGetHeight()/2;
  ofVec2f cursor;
  
public:
  VboElement(Ink *ink, ofVec2f pos);
  void update();
  void draw();
  float getWidth() {return size;}
  float getHeight() {return size;}
  void addPoint(ofVec2f pos);
};

#endif /* VboElement_hpp */
