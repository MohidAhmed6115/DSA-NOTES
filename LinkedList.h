#pragma once
#include <iostream>
#include <stdexcept>
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
		bool isFound = false;

		Node<T> *currentNode = head;
		while(currentNode != NULL){
			if (currentNode->data == target) {
				Node<T> *newNode = new Node<T>;
				newNode->data = data;
				newNode->next = currentNode->next;
				currentNode->next = newNode;
				isFound = true;
				return;
			}
			currentNode = currentNode->next;
		}
		
		if (!isFound) throw runtime_error("Target Not Found")

	}
	void insertBeforeTarget(T target,T data){
		
		if (head == nullptr) throw runtime_error("No List")

		bool isFound = false;

		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		Node<T> *newNode = new Node<T>;
		newNode->data = data;

		if (target == head->data) {
			newNode->next = head;
			head = newNode;
			return;
		}

		while(currentNode != NULL && currentNode->data != target){
			if (currentNode->data == target) {
				newNode->next = prevNode->next;
				prevNode->next = newNode;
				isFound = true;
				return;
			}

			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		
		if (!isFound) throw runtime_error("Target Not Found")
		
	}

	void insertAtPos(int pos,T data){
		Node<T> *currentNode = head;
		Node<T> *prevNode = nullptr;
		Node<T> *newNode = new Node<T>;
		
		if (pos == 1) {
			insertAtFront(data);
			return;
		}
		newNode->data = data;

		int count = 1;

		while ( currentNode != nullptr ) {
			if (count == pos) {
				newNode->next = prevNode->next;
				prevNode->next = newNode;
				return;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
			count++;
		}

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

	void deleteByData(T target){
    Node<T> *currentNode = head;
    Node<T> *prevNode = nullptr;

    while(currentNode != nullptr && currentNode->data != target){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    // Not found (also covers empty list)
    if(currentNode == nullptr){
        return;
    }

    // Deleting the head
    if(prevNode == nullptr){
        head = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    delete currentNode;
}
	
	void deleteByPosition(int position){
    if (head == nullptr) throw runtime_error("List is Empty");
    if (position < 1) throw runtime_error("Invalid position");

    // Deleting the head
    if (position == 1){
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<T> *prevNode = head;
    Node<T> *currentNode = head->next;
    int pos = 2;

    while (currentNode != nullptr){
        if (pos == position){
            prevNode->next = currentNode->next;
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
        pos++;
    }

    throw runtime_error("Position out of range");
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