//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.hpp"

Surface::Surface(const std::filesystem::path imageFilename,
                 const std::filesystem::path maskFilename) {

  image.load(imageFilename);
  mask.load(maskFilename);

  shader.setupShaderFromFile(GL_FRAGMENT_SHADER, "shaders/alphamask.frag");
  shader.linkProgram();

  fbo.allocate(image.getWidth(), image.getHeight());
}

void Surface::update() {
  fbo.begin();
  ofClear(0, 0, 0, 0);
  shader.begin();
  shader.setUniformTexture("maskTex", mask.getTexture(), 1 );
  image.draw(0,0);
  shader.end();
  fbo.end();
}

void Surface::draw() {
  ofSetColor(255,255);
  fbo.draw(0,0, ofGetWidth(), ofGetHeight());
}
