//
//  InkColor.hpp
//  MoleculisOpusApp
//
//  Created by Nuno on 03/06/16.
//
//

#ifndef InkColor_hpp
#define InkColor_hpp

#include "Ink.h"

class InkColor : public Ink {
private:
  ofColor color;
  
public:
  InkColor(ofColor color) : Ink(color.a) {this->color = color; this->color.a = getTransparency();}
  InkColor(ofColor color, int transparency) : Ink(transparency) {this->color = color; this->color.a = getTransparency();}
  ofColor getColor(ofPoint position) {return this->color;}
};

#endif /* InkColor_hpp */
