//
//  Painter.cpp
//  hyphaeApp
//
//  Created by Nuno on 05/03/2019.
//

// Mostly copied from the gl/textureBufferInstanceExample

#include "Painter.h"

Painter::Painter(int maxSize) {
  matrices.resize(maxSize);

  // upload the transformation for each box using a texture buffer. for that
  // we need to upload the matrices to the buffer and allocate the texture using it
  buffer.allocate();
  buffer.bind(GL_TEXTURE_BUFFER);
  buffer.setData(matrices,GL_STREAM_DRAW);

  // using GL_RGBA32F allows to read each row of each matrix
  // as a float vec4 from the shader.
  // Note that we're allocating the texture as a Buffer Texture:
  // https://www.opengl.org/wiki/Buffer_Texture
  tex.allocateAsBufferTexture(buffer,GL_RGBA32F);

  // now we bind the texture to the shader as a uniform
  // so we can read the texture buffer from it
  shader.load("shaders/painter.vert.glsl","shaders/frag.glsl");
  shader.begin();
  shader.setUniformTexture("tex",tex,0);
  shader.end();

  // we are going to use instanced drawing so we
  // only need one geometry
  mesh = ofMesh::box(1,1,1,1,1,1);
  mesh.setUsage(GL_STATIC_DRAW);

}

void Painter::set(int i, ofVec3f pos) {
  ofNode node;
  node.setPosition(pos);
  matrices[i] = node.getLocalTransformMatrix();
}

void Painter::update() {
  buffer.updateData(0,matrices);
}

void Painter::draw() {
  shader.begin();
  mesh.drawInstanced(OF_MESH_WIREFRAME,matrices.size());
  shader.end();
}
