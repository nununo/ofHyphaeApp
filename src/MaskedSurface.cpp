//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "MaskedSurface.hpp"

MaskedSurface::MaskedSurface(Surface *surface,
                             const std::filesystem::path maskFilename) {

  this->surface = surface;
  mask.load(maskFilename);

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "shaders/alphamask.frag");
  shader.linkProgram();

  fbo.allocate(surface->getWidth(), surface->getHeight());
}

float MaskedSurface::getWidth() {return surface->getWidth();}

float MaskedSurface::getHeight() {return surface->getHeight();}

void MaskedSurface::update() {
  fbo.begin();
  ofClear(0, 0, 0, 0);
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  surface->draw();
  shader.end();
  fbo.end();
}

void MaskedSurface::draw() {
  ofSetColor(255,255);
  fbo.draw(0,0, ofGetWidth(), ofGetHeight());
}
