//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "MaskedSurface.h"

MaskedSurface::MaskedSurface(IDrawable *surface,
                             const std::filesystem::path maskFilename) {

  this->surface = surface;
  mask.load(maskFilename);
  mask.resize(surface->getWidth(), surface->getHeight());

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "shaders/alphamask.frag");
  shader.linkProgram();
}

void MaskedSurface::update() {
  surface->update();
}

void MaskedSurface::draw() {
  ofPushStyle();
  ofSetColor(255,255,255);
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  surface->draw();
  shader.end();
  ofPopStyle();
}
