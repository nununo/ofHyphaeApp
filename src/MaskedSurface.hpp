//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef MaskedSurface_hpp
#define MaskedSurface_hpp

#include "ofMain.h"
#include "Surface.hpp"

class MaskedSurface: public IDrawable {
private:
  IDrawable *surface;
  ofImage mask;
  ofFbo fbo;
  ofShader shader;

public:
  MaskedSurface(IDrawable *surface,
                const std::filesystem::path maskFilename);

  // ISurface
  float getWidth() {return surface->getWidth();}
  float getHeight() {return surface->getHeight();}
  void update();
  void draw();
};
#endif /* MaskedSurface_hpp */
