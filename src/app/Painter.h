//
//  Painter.h
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

#ifndef Painter_h
#define Painter_h

#include "ofMain.h"

class Painter {
private:
  ofShader shader;
  ofTexture tex;
  vector<ofMatrix4x4> matrices;
  ofBufferObject buffer;
  ofVboMesh mesh;

public:
  Painter(int maxSize);
  void set(int i, ofVec3f pos);
  void update();
  void draw();
};

#endif /* Painter_h */
