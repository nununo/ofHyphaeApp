//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Family_hpp
#define Family_hpp

#include "ofMain.h"
#include <list>

class Family {

private:
  ofImage image;
  ofVec2f pos;
  float size;
  std::list<ofVec2f> spotPositions;
  ofFbo fbo;

public:
  Family(const std::filesystem::path imageFilename, ofVec2f pos, float size);
  void update();
  void draw();
};

#endif /* Family_hpp */
