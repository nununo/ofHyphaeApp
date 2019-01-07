//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "ofMain.h"
#include "ISurface.h"

class Surface : public ISurface {
private:
  ofImage image;

public:
  Surface(const std::filesystem::path imageFilename);
  
  // ISurface
  float getWidth();
  float getHeight();
  void update();
  void draw();
};

#endif /* Surface_hpp */
