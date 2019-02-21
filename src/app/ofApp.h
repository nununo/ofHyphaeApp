#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "Hyphae.h"
#include "HyphaeParamsBuilder.h"

class ofApp : public ofBaseApp{

private:
  Settings *settings;
  Hyphae *hyphae;
  HyphaeParamsBuilder *builder;

  void drawOSD();
  void restart();

public:
  ~ofApp();
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
