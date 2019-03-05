#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  ofGLWindowSettings settings;
  settings.setGLVersion(3,2);
  settings.setSize(3840, 2160);
  settings.windowMode = OF_FULLSCREEN;
  ofCreateWindow(settings);      // <-------- setup the GL context

//  ofSetupOpenGL(2880,1620,OF_FULLSCREEN);      // <-------- setup the GL context
  //ofSetupOpenGL(3840,2160,OF_FULLSCREEN);      // <-------- setup the GL context
  // 4K: 3840 x 2160

  // this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
