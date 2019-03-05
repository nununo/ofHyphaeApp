//
//  Painter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "Painter.h"

Painter::Painter(int maxSize,ofColor color) {
  mesh.setMode(OF_PRIMITIVE_POINTS);
}

void Painter::set(ofVec2f pos) {
  ofVec3f pos3 = pos;
  mesh.addVertex(pos3);
}

void Painter::draw() {
  mesh.draw();
}
