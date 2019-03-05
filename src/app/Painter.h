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
  vector<ofVec2f> matrices;
  ofBufferObject buffer;
  ofVboMesh mesh;

  int counter=0;

public:
  Painter(int maxSize, ofColor color);
  void reset() {counter=0;}
  void set(ofVec2f pos);
  void update();
  void draw();
};

#endif /* Painter_h */
