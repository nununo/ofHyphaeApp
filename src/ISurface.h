//
//  ISurface.h
//  moldApp
//
//  Created by Nuno on 07/01/2019.
//

#ifndef ISurface_h
#define ISurface_h

class ISurface {

public:
  virtual void update() = 0;
  virtual void draw() = 0;
  virtual float getWidth() = 0;
  virtual float getHeight() = 0;
};
#endif /* ISurface_h */
