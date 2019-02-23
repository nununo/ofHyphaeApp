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
public:
  HyphaeParams create(const Settings &settings);
};

#endif /* HyphaeParamsBuilder_h */
