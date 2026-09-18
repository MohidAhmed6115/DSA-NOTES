#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T> *next;
};

template <typename T>
class LinkedList {
private:
	Node<T> *head = nullptr;
public:
	void insertAtFront(T data){
		Node<T> *newNode = new Node<T>;				// Making a new Node
		newNode->data = data;
		newNode->next = head;						// As there is no next node so setting the address of next to null
		head = newNode;								// Giving head the address of newNode
	}

	void insertAtEnd(T data){
		Node<T> *newNode = new Node<T>;
		

		if (head == nullptr){
			newNode->data = data;
			head = newNode;
			newNode->next = NULL;
			return;
		}
		
		Node<T> *currentNode = head;
		while(currentNode->next != NULL){		
			currentNode = currentNode->next;
		}
		newNode->data = data;
		currentNode->next = newNode;
		newNode->next = NULL;
		
	}

	void insertAfterTarget(T target,T data){

		Node<T> *currentNode = head;
		while(currentNode != NULL && currentNode->data != target){
			currentNode = currentNode->next;
		}
		Node<T> *newNode = new Node<T>;
		
		newNode->data = data;
		newNode->next = currentNode->next;
		currentNode->next = newNode;


	}

	void deleteAtFront(){
		if (head == nullptr) return;

		Node<T> *currentNode = head;
		head = currentNode->next;
		delete currentNode;
		currentNode = nullptr; 
	}

	void deleteAtEnd(){
		if (head == nullptr) return;

		if (head->next == nullptr){
			deleteAtFront();
			return;
		}

		Node<T> *currentNode = head;
		while(currentNode->next->next != NULL){
			currentNode = currentNode->next;
		}
		delete currentNode->next;
		currentNode->next = nullptr;
		
	}

	void deleteTarget(T target){
		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		while(currentNode != nullptr && currentNode->data != target){
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		prevNode->next = currentNode->next;
		delete currentNode;
		currentNode = nullptr;
		
	}

	void reverse(){

		if (head == nullptr) return;

		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		Node<T> *nextNode = nullptr;

		while(currentNode != nullptr){

			nextNode = currentNode->next;
			currentNode->next = prevNode;
			prevNode = currentNode;
			currentNode = nextNode;
		}
		head = prevNode;

	}

	// void ascending(){
	// 	Node<T> *currentNode = head;
	// 	while(currentNode != NULL){

	// 	}
	// }

	// Return True or False 
	bool find(T target){
		Node<T> *currentNode = head;
		bool isFound = false;
		while(currentNode != NULL){
			if (currentNode->data == target) {
				isFound = true;
				break;
			}
			currentNode = currentNode->next;
		}

		return isFound;
	}

	void replace(T target,T new_data){
		Node<T> *currentNode = head;
		while(currentNode != nullptr){
			if (currentNode->data == target) {
				currentNode->data = new_data;
				return; 
			}
			currentNode = currentNode->next;
		}
		
	}

	void display(){
		Node<T> *currentNode = head;				// Assigning the currentNode the value of Head at the start 
		while(currentNode != NULL){
			cout<<currentNode->data<<endl;			// Displaying the currentNode
			currentNode = currentNode->next;		// Assigning currentNode the value of it's next pointer so that currentNode moves
		}
	}

	~LinkedList(){
		Node<T> *currentNode = head;
		while(currentNode != NULL){
			Node<T> *nextNode = currentNode->next;
			delete currentNode;
			currentNode = nextNode;
		}
	}

};

int main (){
	LinkedList<int> list;
	list.insertAtEnd(5);
	list.insertAtEnd(10);
	list.insertAtEnd(15);
	list.insertAtEnd(20);
	list.display();
	list.deleteAtEnd();
	cout<<endl;
	list.display();
}