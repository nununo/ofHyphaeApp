//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "ofMain.h"
#include "Mycelium.h"
#include "Settings.h"

class Surface {
private:
  ofVec2f size;
  CanvasSettings settings;
  ofImage mask;
  ofFbo fboHyphae;
  ofFbo fboConidia;
  ofShader shader;
  std::list<Mycelium*> mycelia;

  void drawPartsToFbo();
  void initializeFbo(ofFbo *fbo, ofColor backgroundColor);

public:
  Surface(const ofVec2f size, const CanvasSettings settings);
  ~Surface();
  
  float getWidth() const {return size.x;}
  float getHeight() const {return size.y;}
  void update();
  void draw();
  bool isAlive() const {return true;}

  void addMycelium(Mycelium *m) {mycelia.push_back(m);}
  MyceliumStats getMyceliaStats();
};

#endif /* Surface_hpp */
