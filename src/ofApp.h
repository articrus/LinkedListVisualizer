#pragma once

#include "ofMain.h"
/*
 * Written by: Gianni Coladonato
 * ID: 2414537
 * Assignment 2, 21-02-2025
*/

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		//To generate random radii
		int generateRandNum(int min, int max);

		//The Node struct for the LinkedList
		struct Node {
			int radius; //The radius of the circle
			float yPos; //The y position (used in animation)
			Node* next; //The next node in the list
		};

		//The LinkedList class
		class LinkedList {
			public: Node* head; 

		//Methods (Some methods referenced with W3 schools)
		public:

			//Default constructor (makes head null)
			LinkedList() { head = NULL; }

			//Constructor with a value (radius)
			LinkedList(int radius) { insertAtHead(radius); }

			//Insert Node at the head of the list
			void insertAtHead(int newRadius) {
				Node* newNode = new Node();
				//The radius of the circle
				newNode->radius = newRadius;
				newNode->next = head;
				head = newNode;
			}

			//Insert node at the tail of the list
			void insertAtTail(int newRadius){
				Node* newNode = new Node();
				//The radius of the circle
				newNode->radius = newRadius;
				newNode->next = NULL;

				//If head is null, make this node the head
				if (!head) 
				{
					head = newNode;
					return;
				}

				//Travel through list to find the last node
				Node* tempNode = head;
				while (tempNode->next) { tempNode = tempNode->next; }

				//Make last node the new node
				tempNode->next = newNode;
			}

			//Remove node at the head of the list
			void removeAtHead() {
				if (!head) { return; } //List empty
				//Make tempNode the head, make the next the head, and delete tempnode
				Node* tempNode = head;
				head = head->next;
				delete tempNode;
			}

			//Remove node at the tail of the list
			void removeAtTail() {
				if (!head) { return; } //List empty

				//If there is only one node
				if (!head->next) 
				{
					delete head;
					head = NULL;
					return;
				}

				//Travel through list to second to last node
				Node* tempNode = head;
				while (tempNode->next->next) { tempNode = tempNode->next; }

				//Remove node at the tail
				delete tempNode->next;
				tempNode->next = NULL;
			}
		};
		
		LinkedList linkedList; //The linked list we are going to use
		float cameraPosition; //The camera's position (used in paning)
		float oscillationSpeed; //The speed of the oscillation
		float oscillationAmp; //The oscillation amplitude
};