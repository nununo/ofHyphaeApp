//
//  IStage.h
//  moldApp
//
//  Created by Nuno on 24/02/2019.
//

#ifndef IStage_h
#define IStage_h

class IStage {
public:
  virtual ~IStage() {}
  virtual void update()=0;
  virtual void draw()=0;
  virtual bool isAlive()=0;
};

#endif /* IStage_h */
