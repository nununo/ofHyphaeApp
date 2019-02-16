//
//  Surface.hpp
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef Surface_hpp
#define Surface_hpp

#include "ofMain.h"
#include "Mycelia.h"
#include "Settings.h"

class Surface {
private:
  ofVec2f size;
  CanvasSettings settings;
  ofFbo fboHyphae;
  ofFbo fboConidia;
  ofShader shader;
  Mycelia *mycelia;

  void drawPartsToFbo();
  void initializeFbo(ofFbo *fbo, ofColor backgroundColor);

public:
  Surface(const ofVec2f size, const CanvasSettings settings, const MyceliumSettings myceliumSettings);
  ~Surface();
  
  void update();
  void draw();

  void addMycelium(ofVec3f pos, Ink *conidiaInk) {mycelia->add(pos, conidiaInk);}
  MyceliaStats getMyceliaStats() {return mycelia->getStats();}
};

#endif /* Surface_hpp */
