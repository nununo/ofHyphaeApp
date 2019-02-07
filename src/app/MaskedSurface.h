//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef MaskedSurface_hpp
#define MaskedSurface_hpp

#include "ofMain.h"
#include "Surface.h"

class MaskedSurface: public IDrawable {
private:
  IDrawable *surface;
  ofImage mask;
  ofShader shader;

public:
  MaskedSurface(IDrawable *surface,
                const std::filesystem::path maskFilename);

  // ISurface
  float getWidth() {return surface->getWidth();}
  float getHeight() {return surface->getHeight();}
  void update();
  void draw();
  bool isAlive() {return true;}
};
#endif /* MaskedSurface_hpp */
