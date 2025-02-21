#include "ofApp.h"
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 2, 21-02-2025
*/

//--------------------------------------------------------------
void ofApp::setup(){
	//Generate a list of 5 random radii
	for (int i = 0; i < 5; i++)
	{
		linkedlist.insertAtTail(5.0f * (i + 1));
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(linkedlist.listCount(), 100, 100);
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
		case 'q': break; //Insert at head
		case 'w': break; //Insert at tail
		case 'a': break; //Delete head node
		case 's': break; //Delete at tail
		case 'e': break; //Sort list in ascending order
		//Animation keys
		case 'z': break; //Increase oscillation
		case 'x': break; //Decrease oscillation
		//Camera keys
		case OF_KEY_LEFT: break; //Pan left
		case OF_KEY_RIGHT: break; //Pan right
	}
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
