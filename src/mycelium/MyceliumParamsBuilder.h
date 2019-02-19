//
//  MyceliumParamsBuilder.h
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#ifndef MyceliumParamsBuilder_h
#define MyceliumParamsBuilder_h

#include "Settings.h"
#include "MyceliumParams.h"

class MyceliumParamsBuilder {
private:
  MyceliumSettings settings;
  
public:
  MyceliumParamsBuilder(MyceliumSettings settings) {this->settings = settings;}
  MyceliumParams create();
};

#endif /* MyceliumParamsBuilder_h */
