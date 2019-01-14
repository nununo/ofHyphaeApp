//
//  Utils.h
//  moldApp
//
//  Created by Nuno on 13/01/2019.
//

#ifndef Utils_h
#define Utils_h

class Utils {

public:
  static int angleToIndex(float angle) {return (int)(angle+0.5f) % 360;}
};

#endif /* Utils_h */
