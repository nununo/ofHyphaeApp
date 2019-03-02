//
//  IStep.h
//  moldApp
//
//  Created by Nuno on 24/02/2019.
//

#ifndef IStep_h
#define IStep_h

class IStep {
public:
  virtual ~IStep() {}
  virtual void update()=0;
  virtual void draw()=0;
  virtual bool isAlive()=0;
};

#endif /* IStep_h */
