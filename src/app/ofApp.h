#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Hyphae.h"
#include "HyphaeParamsBuilder.h"
#include "OSD.h"

enum LifecycleStage {alive, mourning, fadeout, idle};

class ofApp : public ofBaseApp{

private:
  unique_ptr<Settings> settings;
  unique_ptr<Hyphae> hyphae;
  unique_ptr<OSD> osd;
  HyphaeParams currentParams;
  LifecycleStage lifecycleStage = idle;
  int mourningFrames = 0;
  int fadeoutFrames = 0;
  int fadeoutFramesPeriod = 0;

  void newHyphae();
  void drawOSD();

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key) {}
  void mouseMoved(int x, int y ) {}
  void mouseDragged(int x, int y, int button) {}
  void mousePressed(int x, int y, int button) {}
  void mouseReleased(int x, int y, int button) {}
  void mouseEntered(int x, int y) {}
  void mouseExited(int x, int y) {}
  void windowResized(int w, int h) {}
  void dragEvent(ofDragInfo dragInfo) {}
  void gotMessage(ofMessage msg) {}
};
