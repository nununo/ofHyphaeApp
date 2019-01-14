//
//  Sockets.hpp
//  moldApp
//
//  Created by Nuno on 14/01/2019.
//

#ifndef Sockets_hpp
#define Sockets_hpp

enum SocketState { Invalid,Empty,Filled };

#define SOCKETS_MAX_DISTANCE 100

class Sockets {
private:
  SocketState states[SOCKETS_MAX_DISTANCE][360];
  float distance;

  void initialize();
  int getAngularDistance(int i);
  int getIndex(float r) {return (int)(r/this->distance + 0.5f);}

public:
  Sockets(float distance);
  SocketState getState(float r, int angle);
  int fillState(float r, int angle);
};

#endif /* Sockets_hpp */
