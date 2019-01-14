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

  fbo.allocate(getWidth(), getHeight());
}

void MaskedSurface::update() {
  surface->update();

  fbo.begin();
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  surface->draw();
  shader.end();
  fbo.end();
}

void MaskedSurface::draw() {
  ofSetColor(255,0,0);
  ofDrawRectangle(0, 0, getWidth(), getHeight());
  ofSetColor(255,255,255);
  fbo.draw(0,0, getWidth(), getHeight());
}
