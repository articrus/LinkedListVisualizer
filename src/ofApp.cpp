#include "ofApp.h"
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 2, 21-02-2025
*/
//-Initializes values before starting----------------------------
void ofApp::setup(){
	cameraPosition = 0.0f;
	oscillationSpeed = 1.0f;
	oscillationAmp = 100.0f;
	//Generate a list of 5 random radii
	for (int i = 0; i < 5; i++)
	{
		//The radius of the circle will be between 25 and 75
		linkedList.insertAtTail(generateRandNum(25,75)); 
	}
}

//-Used to update the node's y position during oscilation--------
void ofApp::update(){
	Node* tempNode = linkedList.head;
	float time = ofGetElapsedTimef();

	int index = 1;
	int offset;
	while (tempNode != nullptr) {
		//Apply an offset to the y position for snake-like movement
		if (index % 2 == 0) { offset = 2; }
		else { offset = 0; }
		//Update the y position
		tempNode->yPos = ofGetHeight()/2 + sin(oscillationSpeed * time + offset) * oscillationAmp;
		//Increment/move to next node
		tempNode = tempNode->next;
		index++;
	}
}

//-Draws the shapes/lines/values as the are upadted-------------
void ofApp::draw(){
	//Change camera position
	ofTranslate(cameraPosition, 0);
	//Iterate through the list to draw the circles
	Node* tempNode = linkedList.head;
	int j = 0;
	while (tempNode != nullptr) {
		//Draw the circle itself
		ofSetColor(0, 255, 0);
		ofDrawCircle(ofGetWidth() * (j + 1) / 5, tempNode->yPos, tempNode->radius);
		//Draw the value inside
		ofSetColor(255, 255, 255);
		ofDrawBitmapString(tempNode->radius, ofGetWidth() * (j + 1) / 5, tempNode->yPos);
		//Draw the string connecting them (if there is another node to connect)
		if (tempNode->next) {
			ofSetColor(0, 255, 0);
			ofDrawLine((ofGetWidth() * (j + 1) / 5), tempNode->yPos, (ofGetWidth() * (j + 2) / 5), tempNode->next->yPos);
		}
		//Increment/move to next node
		j++;
		tempNode = tempNode->next;
	}
}

//-Processes the user's key inputs------------------------------
void ofApp::keyPressed(int key){
	key = std::tolower(key); //Make key lowercase (inputs are case-sensitive)
	switch (key) {
		//List keys
		case 'q': linkedList.insertAtHead(generateRandNum(25, 100)); break; //Insert at head
		case 'w': linkedList.insertAtTail(generateRandNum(25, 100)); break; //Insert at tail
		case 'a': linkedList.removeAtHead(); break; //Delete head node
		case 's': linkedList.removeAtTail(); break; //Delete at tail
		case 'e': break; //Sort list in ascending order
		//Animation keys
		case 'z': oscillationSpeed += 0.1f; break; //Increase oscillation
		case 'x': oscillationSpeed -= 0.1f; break; //Decrease oscillation
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
