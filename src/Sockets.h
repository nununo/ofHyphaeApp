//
//  Sockets.hpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef Sockets_hpp
#define Sockets_hpp

enum SocketState { Invalid,Empty,Filled };

#define MAX_RINGS 100
#define ANGLE_STEPS 36000

class Sockets {
private:
  SocketState states[MAX_RINGS][ANGLE_STEPS];
  float distance;

  void initialize();
  int getAngularDistance(int ring);
  int getAngleIndex(float angle) {return (int)(angle*100 +0.5f);}

public:
  Sockets(float distance);
  int getRing(float radius) {return (int)(radius/this->distance + 0.5f);}
  SocketState isFilled(int ring, float angle);
  bool fill(int ring, float angle);
  void draw();
};

#endif /* Sockets_hpp */
