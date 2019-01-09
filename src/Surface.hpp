//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "Family.hpp"
#include "IDrawable.h"

class Surface : public IDrawable {
private:
  Family *family;
  ofVec2f size;
  ofImage image;
  ofFbo fbo;

public:
  Surface(Family *family, const std::filesystem::path imageFilename, ofVec2f size);
  
  // ISurface
  float getWidth() {return size.x;}
  float getHeight() {return size.y;}
  void update();
  void draw();
};

#endif /* Surface_hpp */
