//
//  Surface.cpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#include "Surface.hpp"

Surface::Surface(const std::filesystem::path imageFilename) {
  image.load(imageFilename);
}

void Surface::update() {
}

void Surface::draw() {
  ofSetColor(255,255);
  image.draw(0,0);
}

float Surface::getWidth() {return image.getWidth();}

float Surface::getHeight() {return image.getHeight();}
