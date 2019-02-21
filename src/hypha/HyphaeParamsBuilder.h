//
//  HyphaeParamsBuilder.h
//  moldApp
//
//  Created by Nuno on 19/02/2019.
//

#ifndef HyphaeParamsBuilder_h
#define HyphaeParamsBuilder_h

#include "Settings.h"
#include "HyphaeParams.h"

class HyphaeParamsBuilder {
private:
  HyphaeSettings settings;
  
public:
  HyphaeParamsBuilder(HyphaeSettings settings) {this->settings = settings;}
  HyphaeParams create();
};

#endif /* HyphaeParamsBuilder_h */
