#include "ofMain.h"
#include "ofApp.h"
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 2, 21-02-2025
*/

//========================================================================
int main( ){

	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN

	auto window = ofCreateWindow(settings);

	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

}
