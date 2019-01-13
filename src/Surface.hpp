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
  ofFbo fbo;
  std::list<IDrawable*> parts;


public:
  Surface(ofVec2f size);
  
  // ISurface
  float getWidth() {return size.x;}
  float getHeight() {return size.y;}
  void update();
  void draw();

  void addPart(IDrawable *d) {parts.push_back(d);}
};

#endif /* Surface_hpp */
