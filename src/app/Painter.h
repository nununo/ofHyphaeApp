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
  ofVboMesh mesh;

public:
  Painter(int maxSize, ofColor color);
  void reset() {mesh.clear();}
  void set(ofVec2f pos);
  void draw();
};

#endif /* Painter_h */
