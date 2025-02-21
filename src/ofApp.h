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

		//The Node struct for the LinkedList
		struct Node {
			float radius; //The radius of the circle
			Node* next; //The next node in the list
		};

		//The LinkedList class
		class LinkedList {
			Node* head; 

		//Methods
		public:

			//Default constructor (makes head null)
			LinkedList() : head(NULL) {}

			//Constructor with a value (radius)
			LinkedList(float radius) {
				insertAtHead(radius);
			}

			//Insert Node at the head of the list
			void insertAtHead(float newRadius) {
				Node* newNode = new Node();
				newNode->radius = newRadius;
				newNode->next = head;
				head = newNode;
			}

			//Insert node at the tail of the list
			void insertAtTail(float newRadius){
				Node* newNode = new Node();
				newNode->radius = newRadius;
				newNode->next = NULL;

				//If head is null, make this node the head
				if (!head) {
					head = newNode;
					return;
				}

				//Travel through list to find the last node
				Node* tempNode = head;
				while (tempNode->next) {
					tempNode = tempNode->next;
				}

				//Make last node the new node
				tempNode->next = newNode;
			}

			//Remove node at the head of the list
			void removeAtHead() {
				if (!head) {
					return; //List empty
				}

				Node* tempNode = head;
				head = head->next;
				delete tempNode;
			}

			//Remove node at the tail of the list
			void removeAtTail() {
				if (!head) {
					return; //List empty
				}

				//If there is only one node
				if (!head->next) {
					delete head;
					head = NULL;
					return;
				}

				//Travel through list to second to last node
				Node* tempNode = head;
				while (tempNode->next->next) {
					tempNode = tempNode->next;
				}

				//Remove node at the tail
				delete tempNode->next;
				tempNode->next = NULL;
			}

			//Get the node at the given index
			float getRadiusAtPos(int pos) {
				if (pos < 0) {
					return -1; //If index is less than 0
				}

				//If index is 0, return the head
				if (pos == 0) {
					return head->radius;
				}

				//Navigate through the list to find the node at the index
				int currentIndex = 1;
				Node* tempNode = head->next;
				while (tempNode != nullptr) {
					if (currentIndex == pos) {
						return tempNode->radius;
					}
					tempNode = tempNode->next;
					currentIndex++;
				}

				//If index is out of bounds
				return -1;
			}

			//Return the number of nodes in the linked list
			int listCount() {
				//If no head, return 0
				if (!head) {
					return 0;
				}

				//Navigate through list and incremement the nodecount 
				int nodeCount = 0;
				Node* tempNode = head;
				while (tempNode != nullptr) {
					nodeCount++;
					tempNode = tempNode->next;
				}
				return nodeCount;
			}
		};
		
		LinkedList linkedlist;
};