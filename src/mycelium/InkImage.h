//
//  InkImage.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef InkImage_hpp
#define InkImage_hpp

#include "Ink.h"

class InkImage : public Ink {
  
  ofImage *image;
  
public:
  InkImage(ofImage *image, int transparency) : Ink(transparency) {this->image = image;}
  ofColor getColor(ofPoint position) {return image->getColor(position.x, position.y);}
};

#endif /* InkImage_hpp */
