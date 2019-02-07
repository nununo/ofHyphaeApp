//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "ofMain.h"
#include "IDrawable.h"

class Surface : public IDrawable {
private:
  ofVec2f size;
  ofColor backgroundColor;
  ofFbo fbo;
  std::list<IDrawable*> parts;


public:
  Surface(const ofVec2f size, const ofColor backgroundColor);
  ~Surface();
  
  // ISurface
  float getWidth() {return size.x;}
  float getHeight() {return size.y;}
  void update();
  void draw();
  bool isAlive() {return true;}

  void addPart(IDrawable *d) {parts.push_back(d);}
};

#endif /* Surface_hpp */
