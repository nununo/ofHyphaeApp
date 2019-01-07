//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "ofMain.h"

class Surface {
private:
  ofImage  mask;
  ofImage  image;
  ofFbo    fbo;
  ofShader shader;

public:
  Surface(const std::filesystem::path imageFilename,
          const std::filesystem::path maskFilename);
  void update();
  void draw();
};
#endif /* Surface_hpp */
