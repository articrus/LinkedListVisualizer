#include "ofApp.h"
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 2, 21-02-2025
*/

//--------------------------------------------------------------
void ofApp::setup(){
	cameraPosition = 0.0f;
	//Generate a list of 5 random radii
	for (int i = 0; i < 5; i++)
	{
		linkedlist.insertAtTail(generateRandNum(25,100));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(cameraPosition, 0);
	//Leaving these here for testing
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(linkedlist.listCount(), 100, 100);
	ofDrawBitmapString(cameraPosition, 150, 100);
	//Draw the list as circles (adjust later)
	for (int i = 0; i < linkedlist.listCount(); i++) {
		ofSetColor(0, 255, 0);
		ofDrawCircle(ofGetWidth() * (i + 1) / 6, ofGetHeight() / 2, linkedlist.getRadiusAtPos(i));
		ofSetColor(255, 255, 255);
		ofDrawBitmapString(linkedlist.getRadiusAtPos(i), ofGetWidth() * (i + 1) / 6, ofGetHeight() / 2);
	}
}

//-Processes the user's key inputs------------------------------
void ofApp::keyPressed(int key){
	key = std::tolower(key); //Make key lowercase (inputs are case-sensitive)
	switch (key) {
		//List keys
		case 'q': linkedlist.insertAtHead(generateRandNum(25, 100)); break; //Insert at head
		case 'w': linkedlist.insertAtTail(generateRandNum(25, 100)); break; //Insert at tail
		case 'a': linkedlist.removeAtHead(); break; //Delete head node
		case 's': linkedlist.removeAtTail(); break; //Delete at tail
		case 'e': break; //Sort list in ascending order
		//Animation keys
		case 'z': break; //Increase oscillation
		case 'x': break; //Decrease oscillation
		//Camera keys
		case OF_KEY_LEFT: cameraPosition += 10.0f; break; //Pan left
		case OF_KEY_RIGHT: cameraPosition -= 10.0f; break; //Pan right
	}
}

//-Generates a random number between the min and maximum and returns it
int ofApp::generateRandNum(int min, int max) {
	std::random_device rd; //The random object
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> range(min, max); //Setting the bounds
	return range(gen);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
