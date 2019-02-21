//
//  Spot.hpp
//  moldApp
//
//  Created by Nuno on 08/01/2019.
//

#ifndef Mycelium_h
#define Mycelium_h

#include "ofMain.h"
#include "Hyphae.h"
#include "Settings.h"
#include "MyceliumParams.h"

struct MyceliumStats {
  int hyphaCount = 0;
  int primalHyphaCount = 0;
};

class Mycelium {

private:
  ofVec2f pos;
  Border *border;
  MyceliumSettings settings;
  MyceliumParams params;
  Hyphae *hyphae = NULL;
  bool wasAlreadyAlive = false;

public:
  Mycelium(const MyceliumSettings settings, MyceliumParams params);
  ~Mycelium();
  
  void update();
  void draw() const;
  bool isAlive() const {return (!wasAlreadyAlive || hyphae->count() > 0);}
  MyceliumStats getStats();
};

#endif /* Mycelium_h */
