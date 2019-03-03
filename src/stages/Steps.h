//
//  Steps.h
//  hyphaeApp
//
//  Created by Nuno on 02/03/2019.
//

#ifndef Steps_h
#define Steps_h

#include "IStep.h"
#include <memory>
#include "Settings.h"
#include "Hyphae.h"

enum LifecycleStep {growing, mourning, fadeout, idle};

class Steps: public IStep {
private:
  Settings *settings;
  unique_ptr<Hyphae> hyphae;
  std::unique_ptr<IStep> step;
  LifecycleStep currentStep = idle;

public:
  Steps(Settings *settings);
  // IStep
  void update();
  void draw() {step->draw();}
  bool isAlive() {return step->isAlive();}
  
  void setGrowing();
  void setMourning();
  void setFadeout();
  void setIdle();
  
  string getCurrentStepName();

  HyphaeParams getHyphaeParams() const {return hyphae->getParams();}
  HyphaeStats getHyphaeStats() const {return hyphae->getStats();}
  void drawHyphaeBorder() {hyphae->drawBorder();}
};

#endif /* Steps_h */
